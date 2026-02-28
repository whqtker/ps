package boj.boj_1920;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n];

        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int m = Integer.parseInt(br.readLine());

        line = br.readLine();
        st = new StringTokenizer(line);

        for (int i = 0; i < m; i++) {
            int tar = Integer.parseInt(st.nextToken());
            if (Arrays.binarySearch(arr, tar) < 0) {
                bw.write('0');
            }
            else {
                bw.write('1');
            }

            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}
