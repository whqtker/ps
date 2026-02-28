package swea.swea_4193;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

    static class Coor implements Comparable<Coor> {
        int x;
        int y;
        int time;

        Coor(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }

        @Override
        public int compareTo(Coor c) {
            return this.time - c.time;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[][] arr;
    static int n;
    static int[][] visited;
    static int[] derX = { -1, 0, 1, 0 };
    static int[] derY = { 0, 1, 0, -1 };

    static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= n || y >= n;
    }

    public static void main(String args[]) throws Exception {

        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n][n];
            visited = new int[n][n];

            for (int i = 0; i < n; i++) {
                String line = br.readLine();
                StringTokenizer st = new StringTokenizer(line);

                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);

            int sx = Integer.parseInt(st.nextToken());
            int sy = Integer.parseInt(st.nextToken());

            line = br.readLine();
            st = new StringTokenizer(line);

            int dx = Integer.parseInt(st.nextToken());
            int dy = Integer.parseInt(st.nextToken());

            visited[sx][sy] = 1;
            PriorityQueue<Coor> pq = new PriorityQueue<Coor>();
            pq.offer(new Coor(sx, sy, 0));

            int ans = -1;

            while (!pq.isEmpty()) {
                Coor cur = pq.poll();
                int cx = cur.x;
                int cy = cur.y;
                int cTime = cur.time;

                if (cx == dx && cy == dy) {
                    ans = cTime;
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = cx + derX[i];
                    int ny = cy + derY[i];

                    if (outOfBound(nx, ny)) continue;
                    if (arr[nx][ny] == 1) continue;
                    if (visited[nx][ny] == 1) continue;

                    if (arr[nx][ny] == 0) {
                        if (visited[nx][ny] == 0 || visited[cx][cy] + 1 <= visited[nx][ny]) {
                            visited[nx][ny] = visited[cx][cy] + 1;
                            pq.offer(new Coor(nx, ny, cTime + 1));
                        }
                    }
                    else if (arr[nx][ny] == 2) {
                        // 소용돌이가 바로 사라진 경우
                        if (cTime % 3 == 2) {
                            visited[nx][ny] = 1;
                            pq.offer(new Coor(nx, ny, cTime + 1));
                        }
                        else {
                            int wait = (cTime % 3 == 0) ? 2 : 1;
                            visited[nx][ny] = 1;
                            pq.offer(new Coor(nx, ny, cTime + wait + 1));
                        }
                    }
                }
            }

            bw.write('#' + Integer.toString(tc) + ' ' + Integer.toString(ans));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}
