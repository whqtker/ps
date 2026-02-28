const axios = require('axios');
const fs = require('fs');
const path = require('path');

const ROOT = path.join(__dirname, '..');
const readmePath = path.join(ROOT, 'README.md');

// ── 언어별 ID/이름 수집 ──────────────────────────────────────────────────────

function getBojCppIds() {
    const p = path.join(ROOT, 'baekjoon', 'cpp', 'solutions');
    if (!fs.existsSync(p)) return new Set();
    return new Set(
        fs.readdirSync(p).filter(f => f.endsWith('.cpp')).map(f => f.replace('.cpp', ''))
    );
}

function getBojJavaIds() {
    const p = path.join(ROOT, 'baekjoon', 'java', 'src', 'main', 'java', 'boj');
    if (!fs.existsSync(p)) return new Set();
    return new Set(
        fs.readdirSync(p).filter(d => d.startsWith('boj_')).map(d => d.replace('boj_', ''))
    );
}

function getBojPythonIds() {
    const p = path.join(ROOT, 'baekjoon', 'python');
    if (!fs.existsSync(p)) return new Set();
    return new Set(
        fs.readdirSync(p).filter(f => f.endsWith('.py')).map(f => f.replace('.py', ''))
    );
}

function getSweaJavaIds() {
    const p = path.join(ROOT, 'swea', 'java', 'src', 'main', 'java', 'swea');
    if (!fs.existsSync(p)) return new Set();
    return new Set(
        fs.readdirSync(p).filter(d => d.startsWith('swea_')).map(d => d.replace('swea_', ''))
    );
}

function getProgCppNames() {
    const p = path.join(ROOT, 'programmers', 'cpp');
    if (!fs.existsSync(p)) return [];
    return fs.readdirSync(p)
        .filter(f => f.endsWith('.cpp'))
        .map(f => f.replace('.cpp', ''))
        .sort();
}

// ── 언어 태그 생성 ─────────────────────────────────────────────────────────

function buildBojLangTags(id, cppIds, javaIds, pythonIds) {
    const tags = [];
    if (cppIds.has(id))    tags.push(`[\`C++\`](./baekjoon/cpp/solutions/${id}.cpp)`);
    if (javaIds.has(id))   tags.push(`[\`Java\`](./baekjoon/java/src/main/java/boj/boj_${id}/Main.java)`);
    if (pythonIds.has(id)) tags.push(`[\`Python\`](./baekjoon/python/${id}.py)`);
    return tags.join(' ');
}

// ── README 섹션 파싱 / 교체 ────────────────────────────────────────────

function parseExistingBojRows(content) {
    const startTag = '<!-- BOJ_TABLE_START -->';
    const endTag   = '<!-- BOJ_TABLE_END -->';
    const startIdx = content.indexOf(startTag);
    const endIdx   = content.indexOf(endTag);
    if (startIdx === -1 || endIdx === -1) return new Map();

    const section = content.slice(startIdx + startTag.length, endIdx);
    const rowMap  = new Map();
    for (const line of section.split('\n')) {
        const m = line.match(/^\| (\d+) \|/);
        if (m) rowMap.set(m[1], line);
    }
    return rowMap;
}

function updateLangTagsInRow(row, id, cppIds, javaIds, pythonIds) {
    const cols = row.split('|');
    // cols[0]='' cols[1]=id cols[2]=문제 cols[3]=언어 cols[4]=해설 cols[5]=''
    if (cols.length < 5) return row;
    cols[3] = ` ${buildBojLangTags(id, cppIds, javaIds, pythonIds)} `;
    return cols.join('|');
}

function replaceSection(content, startTag, endTag, newRows) {
    const startIdx = content.indexOf(startTag);
    const endIdx   = content.indexOf(endTag);
    if (startIdx === -1 || endIdx === -1) {
        console.error(`섹션 태그를 찾을 수 없습니다: ${startTag}`);
        return content;
    }
    const before = content.slice(0, startIdx + startTag.length);
    const after  = content.slice(endIdx);
    return before + '\n' + newRows.join('\n') + '\n' + after;
}

const sleep = ms => new Promise(resolve => setTimeout(resolve, ms));

// ── 메인 ──────────────────────────────────────────────────────────────────

async function updateReadme() {
    try {
        let content = fs.readFileSync(readmePath, 'utf8');

        // ── 백준 섹션 ──
        const cppIds    = getBojCppIds();
        const javaIds   = getBojJavaIds();
        const pythonIds = getBojPythonIds();

        const bojIds = [...new Set([...cppIds, ...javaIds, ...pythonIds])]
            .sort((a, b) => parseInt(a) - parseInt(b));

        console.log(`백준: ${bojIds.length}개 문제 처리 중...`);

        // 기존 행 캐시 (API 실패 시 폴백용)
        const existingRows = parseExistingBojRows(content);

        const bojRows = [];
        for (const id of bojIds) {
            try {
                const res = await axios.get(`https://solved.ac/api/v3/problem/show?problemId=${id}`);
                const p   = res.data;
                const langTags = buildBojLangTags(id, cppIds, javaIds, pythonIds);
                bojRows.push(
                    `| ${id} | <img src="https://static.solved.ac/tier_small/${p.level}.svg" width="20" height="20"> [${p.titleKo}](https://www.acmicpc.net/problem/${id}) | ${langTags} | [해설](https://whqtker.github.io/posts/백준-${id}/) |`
                );
                console.log(`  ✓ ${id} (${p.titleKo})`);
                await sleep(50);
            } catch (e) {
                // API 실패: 기존 행 재사용 + 언어 태그 업데이트
                if (existingRows.has(id)) {
                    bojRows.push(updateLangTagsInRow(existingRows.get(id), id, cppIds, javaIds, pythonIds));
                    console.log(`  ~ ${id}: API 실패, 기존 행 유지`);
                } else {
                    const langTags = buildBojLangTags(id, cppIds, javaIds, pythonIds);
                    bojRows.push(`| ${id} | [${id}](https://www.acmicpc.net/problem/${id}) | ${langTags} | [해설](https://whqtker.github.io/posts/백준-${id}/) |`);
                    console.log(`  ✗ ${id}: API 실패, 최소 행 추가`);
                }
            }
        }

        content = replaceSection(content, '<!-- BOJ_TABLE_START -->', '<!-- BOJ_TABLE_END -->', bojRows);

        // ── 프로그래머스 섹션 ──
        const progNames = getProgCppNames();
        console.log(`\n프로그래머스: ${progNames.length}개 문제 처리 중...`);

        const progRows = progNames.map(name =>
            `| ${name} | [\`C++\`](./programmers/cpp/${name}.cpp) |`
        );

        content = replaceSection(content, '<!-- PROG_TABLE_START -->', '<!-- PROG_TABLE_END -->', progRows);

        // ── SWEA 섹션 ──
        const sweaIds = [...getSweaJavaIds()].sort((a, b) => parseInt(a) - parseInt(b));
        console.log(`\nSWEA: ${sweaIds.length}개 문제 처리 중...`);

        const sweaRows = sweaIds.map(id =>
            `| ${id} | [\`Java\`](./swea/java/src/main/java/swea/swea_${id}/Solution.java) |`
        );

        content = replaceSection(content, '<!-- SWEA_TABLE_START -->', '<!-- SWEA_TABLE_END -->', sweaRows);

        fs.writeFileSync(readmePath, content);
        console.log('\nREADME.md 업데이트 완료');

    } catch (e) {
        console.error('오류 발생:', e);
    }
}

updateReadme();
