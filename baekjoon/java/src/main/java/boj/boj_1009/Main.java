package boj.boj_1009;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();

            int k = a;
            a %= 10;
            for (int j = 0; j < b - 1; j++) {
                a *= k;
                a %= 10;
            }

            System.out.println(a == 0 ? 10 : a);
        }
    }
}
