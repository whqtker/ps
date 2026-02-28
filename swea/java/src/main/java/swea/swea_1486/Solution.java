package swea.swea_1486;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    static int[] height;
    static int ans;
    static int n, b;
    static int[] visited;

    static void dfs(int sum, int idx) {
        if (sum >= b) {
            ans = Math.min(sum, ans);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                dfs(sum + height[i], i + 1);
                visited[i] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {

        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            ans = Integer.MAX_VALUE;

            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);

            n = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            visited = new int[n];
            height = new int[n];
            
            line = br.readLine();
            st = new StringTokenizer(line);
            for (int i = 0; i < n; i++) {
                height[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 0; i < n; i++) {
                visited[i] = 1;
                dfs(height[i], i + 1);
                visited[i] = 0;
            }

            bw.write('#' + Integer.toString(tc) + ' ' + Integer.toString(ans - b));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}
