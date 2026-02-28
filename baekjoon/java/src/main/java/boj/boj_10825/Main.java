package boj.boj_10825;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());

        String[][] arr = new String[n][4];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine().split(" ");
        }

        Arrays.sort(arr, (a, b) -> {
            int ka = Integer.parseInt(a[1]);
            int kb = Integer.parseInt(b[1]);
            int ea = Integer.parseInt(a[2]);
            int eb = Integer.parseInt(b[2]);
            int ma = Integer.parseInt(a[3]);
            int mb = Integer.parseInt(b[3]);

            if (ka != kb) {
                return Integer.compare(kb, ka);
            }

            if (ea != eb) {
                return Integer.compare(ea, eb);
            }

            if (ma != mb) {
                return Integer.compare(mb, ma);
            }

            return a[0].compareTo(b[0]);
        });

        for (int i = 0; i < n; i++) {
            sb.append(arr[i][0]).append('\n');
        }
        System.out.println(sb.toString());
    }
}
