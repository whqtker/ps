package boj.boj_1260;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();

    static List<Integer>[] graph;
    static boolean[] visited;

    static void dfs(int cur) {

        visited[cur] = true;
        sb.append(cur).append(' ');

        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur].get(i);

            if (!visited[nxt]) {
                dfs(nxt);
            }
        }
    }

    static void bfs(int start) {

        Arrays.fill(visited, false);
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur).append(' ');

            for (int i = 0; i < graph[cur].size(); i++) {
                int nxt = graph[cur].get(i);

                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.offer(nxt);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {

        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            line = br.readLine();
            st = new StringTokenizer(line);

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }

        for (int i = 1; i <= n; i++) {
            Collections.sort(graph[i]);
        }

        dfs(v);
        sb.append('\n');
        bfs(v);

        bw.write(sb.toString());
        bw.flush();
    }
}
