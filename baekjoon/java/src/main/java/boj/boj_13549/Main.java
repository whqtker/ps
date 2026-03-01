package boj.boj_13549;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static final int LIMIT = 1000001;

    public static void main(String[] args) throws IOException {
        // 위치를 노드, 걸린 시간을 간선으로 간주하면 BFS로 풀 수 있다. 최간 시간을 구하는 것이기 때문.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n, k;
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        int[] visited = new int[LIMIT];
        Queue<Integer> q = new ArrayDeque<>();
        visited[n] = 1;
        q.offer(n);

        while (!q.isEmpty()) {
            int x = q.poll();

            if (x == k) break;

            if (2 * x < LIMIT && visited[2 * x] == 0) {
                visited[2 * x] = visited[x];
                q.offer(2 * x);
            }

            if (x - 1 >= 0 && visited[x - 1] == 0) {
                visited[x - 1] = visited[x] + 1;
                q.offer(x - 1);
            }

            if (x + 1 < LIMIT && visited[x + 1] == 0) {
                visited[x + 1] = visited[x] + 1;
                q.offer(x + 1);
            }
        }

        sb.append(visited[k] - 1);
        System.out.println(sb);
    }
}
