package swea.swea_1961;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.nio.Buffer;
import java.util.StringTokenizer;

public class Solution {

    static int n;
    static int[][] arr;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    // 90도 회전
    // 아래에서 위로 열 출력
    static void sol1(int idx) throws IOException {
        for (int i = n - 1; i >= 0; i--) {
            bw.write(Integer.toString(arr[i][idx]));
        }
        bw.write(' ');
    }

    // 180도 회전
    // 왼쪽에서 오른쪽으로 행 출력
    static void sol2(int idx) throws IOException {
        for (int i = n - 1; i >= 0; i--) {
            bw.write(Integer.toString(arr[n - idx - 1][i]));
        }
        bw.write(' ');
    }

    // 270도 회전
    // 위에서 아래로 열 출력
    static void sol3(int idx) throws IOException {
        for (int i = 0; i < n; i++) {
            bw.write(Integer.toString(arr[i][n - idx - 1]));
        }
        bw.write(' ');
    }

    public static void main(String[] args) throws IOException {

        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            bw.write('#' + Integer.toString(test_case));
            bw.newLine();

            n = Integer.parseInt(br.readLine());

            arr = new int[n][n];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 0; i < n; i++) {
                sol1(i);
                sol2(i);
                sol3(i);

                bw.newLine();
            }

            bw.flush();
        }

        bw.close();
    }
}
