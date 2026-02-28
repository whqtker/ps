package boj.boj_1012;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[][] graph;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean[][] visited;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            graph = new int[n + 1][m + 1];
            visited = new boolean[n + 1][m + 1];

            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                graph[a][b] = 1;
            }

            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!visited[i][j] && graph[i][j] == 1) {
                        cnt++;
                        visited[i][j] = true;
                        Queue<int[]> q = new ArrayDeque<>();
                        q.offer(new int[]{i, j});

                        while (!q.isEmpty()) {
                            int[] cur = q.poll();
                            int x = cur[0];
                            int y = cur[1];

                            for (int l = 0; l < 4; l++) {
                                int nx = x + dx[l];
                                int ny = y + dy[l];

                                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                                if (visited[nx][ny]) continue;
                                if (graph[nx][ny] == 0) continue;

                                visited[nx][ny] = true;
                                q.offer(new int[]{nx, ny});
                            }
                        }
                    }
                }
            }

            sb.append(Integer.toString(cnt)).append('\n');
        }

        System.out.println(sb.toString());
    }
}
