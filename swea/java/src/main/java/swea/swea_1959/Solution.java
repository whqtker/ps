package swea.swea_1959;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution {

    // 파라미터의 a가 더 작은 배열
    static int solve(int[] a, int[] b) {
        int ret = 0;

        for (int i = 0; i < b.length - a.length + 1; i++) {
            int tmp = 0;

            for (int j = 0; j < a.length; j++) {
                tmp += a[j] * b[j + i];
            }

            ret = Math.max(ret, tmp);
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[] a = new int[n];
            int[] b = new int[m];

            line = br.readLine();
            st = new StringTokenizer(line);

            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt((st.nextToken()));
            }

            line = br.readLine();
            st = new StringTokenizer(line);

            for (int i = 0; i < m; i++) {
                b[i] = Integer.parseInt((st.nextToken()));
            }

            int ans;
            if (n < m) {
                ans = solve(a, b);
            }
            else {
                ans = solve(b, a);
            }

            bw.write('#' + Integer.toString(test_case) + ' ' + Integer.toString(ans));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}
