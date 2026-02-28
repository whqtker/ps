// 기존 C++/Python README에서 메타데이터를 가져와 새 README를 시드로 생성
// API 호출 없이 정확한 README 복원용 1회성 스크립트
const fs   = require('fs');
const path = require('path');

const ROOT = path.join(__dirname, '..');

function parseMetaFromReadme(filePath) {
    const map = new Map();
    if (!fs.existsSync(filePath)) return map;
    for (const line of fs.readFileSync(filePath, 'utf8').replace(/\r/g, '').split('\n')) {
        const m = line.match(/^\| (\d+) \| (<img [^>]+>) \[([^\]]+)\]\(([^)]+)\)/);
        if (m) map.set(m[1], { img: m[2], title: m[3], url: m[4] });
    }
    return map;
}

function getBojCppIds() {
    const p = path.join(ROOT, 'baekjoon', 'cpp', 'solutions');
    if (!fs.existsSync(p)) return new Set();
    return new Set(fs.readdirSync(p).filter(f => f.endsWith('.cpp')).map(f => f.replace('.cpp', '')));
}
function getBojJavaIds() {
    const p = path.join(ROOT, 'baekjoon', 'java', 'src', 'main', 'java', 'boj');
    if (!fs.existsSync(p)) return new Set();
    return new Set(fs.readdirSync(p).filter(d => d.startsWith('boj_')).map(d => d.replace('boj_', '')));
}
function getBojPythonIds() {
    const p = path.join(ROOT, 'baekjoon', 'python');
    if (!fs.existsSync(p)) return new Set();
    return new Set(fs.readdirSync(p).filter(f => f.endsWith('.py')).map(f => f.replace('.py', '')));
}
function getSweaJavaIds() {
    const p = path.join(ROOT, 'swea', 'java', 'src', 'main', 'java', 'swea');
    if (!fs.existsSync(p)) return new Set();
    return new Set(fs.readdirSync(p).filter(d => d.startsWith('swea_')).map(d => d.replace('swea_', '')));
}
function getProgCppNames() {
    const p = path.join(ROOT, 'programmers', 'cpp');
    if (!fs.existsSync(p)) return [];
    return fs.readdirSync(p).filter(f => f.endsWith('.cpp')).map(f => f.replace('.cpp', '')).sort();
}
function buildBojLangTags(id, cppIds, javaIds, pythonIds) {
    const tags = [];
    if (cppIds.has(id))    tags.push(`[\`C++\`](./baekjoon/cpp/solutions/${id}.cpp)`);
    if (javaIds.has(id))   tags.push(`[\`Java\`](./baekjoon/java/src/main/java/boj/boj_${id}/Main.java)`);
    if (pythonIds.has(id)) tags.push(`[\`Python\`](./baekjoon/python/${id}.py)`);
    return tags.join(' ');
}
function replaceSection(content, startTag, endTag, newRows) {
    const startIdx = content.indexOf(startTag);
    const endIdx   = content.indexOf(endTag);
    if (startIdx === -1 || endIdx === -1) return content;
    return content.slice(0, startIdx + startTag.length) + '\n' + newRows.join('\n') + '\n' + content.slice(endIdx);
}

// ── 메타데이터 수집 ─────────────────────────────────────────────────────
const TEMP = process.env.TEMP || process.env.TMP || '/tmp';
const cppMeta = parseMetaFromReadme(path.join(TEMP, 'ps-cpp', 'README.md'));
const pyMeta  = parseMetaFromReadme(path.join(ROOT, 'baekjoon-python', 'README.md'));

// 병합 (C++ 우선, Python으로 보완)
const metaMap = new Map([...cppMeta]);
for (const [id, val] of pyMeta) {
    if (!metaMap.has(id)) metaMap.set(id, val);
}

console.log(`메타데이터 총 ${metaMap.size}개 문제`);

// ── 파일 스캔 ──────────────────────────────────────────────────────────
const cppIds    = getBojCppIds();
const javaIds   = getBojJavaIds();
const pythonIds = getBojPythonIds();

const bojIds = [...new Set([...cppIds, ...javaIds, ...pythonIds])]
    .sort((a, b) => parseInt(a) - parseInt(b));

console.log(`BOJ 총 ${bojIds.length}개 문제`);

// ── BOJ 행 생성 ────────────────────────────────────────────────────────
const bojRows = [];
for (const id of bojIds) {
    const langTags = buildBojLangTags(id, cppIds, javaIds, pythonIds);
    if (metaMap.has(id)) {
        const { img, title, url } = metaMap.get(id);
        bojRows.push(`| ${id} | ${img} [${title}](${url}) | ${langTags} | [해설](https://whqtker.github.io/posts/백준-${id}/) |`);
    } else {
        bojRows.push(`| ${id} | [${id}](https://www.acmicpc.net/problem/${id}) | ${langTags} | [해설](https://whqtker.github.io/posts/백준-${id}/) |`);
    }
}

// ── 프로그래머스 행 ────────────────────────────────────────────────────
const progRows = getProgCppNames().map(name =>
    `| ${name} | [\`C++\`](./programmers/cpp/${name}.cpp) |`
);

// ── SWEA 행 ────────────────────────────────────────────────────────────
const sweaIds  = [...getSweaJavaIds()].sort((a, b) => parseInt(a) - parseInt(b));
const sweaRows = sweaIds.map(id =>
    `| ${id} | [\`Java\`](./swea/java/src/main/java/swea/swea_${id}/Solution.java) |`
);

// ── README 업데이트 ────────────────────────────────────────────────────
const readmePath = path.join(ROOT, 'README.md');
let content = fs.readFileSync(readmePath, 'utf8');
content = replaceSection(content, '<!-- BOJ_TABLE_START -->', '<!-- BOJ_TABLE_END -->', bojRows);
content = replaceSection(content, '<!-- PROG_TABLE_START -->', '<!-- PROG_TABLE_END -->', progRows);
content = replaceSection(content, '<!-- SWEA_TABLE_START -->', '<!-- SWEA_TABLE_END -->', sweaRows);
fs.writeFileSync(readmePath, content);

console.log('README.md 시드 완료');
console.log(`  백준: ${bojRows.length}개, 프로그래머스: ${progRows.length}개, SWEA: ${sweaRows.length}개`);
