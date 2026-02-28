package boj.boj_1916;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static List<int[]>[] graph;
    static int[] dist;

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        graph = (List<int[]>[]) new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new int[]{b, c});
        }

        dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, start});
        dist[start] = 0;

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int cost = cur[0];
            int node = cur[1];

            if (dist[node] < cost) continue;

            for (int i = 0; i < graph[node].size(); i++) {
                int nnode = graph[node].get(i)[0];
                int ncost = graph[node].get(i)[1];

                if (dist[nnode] > cost + ncost) {
                    dist[nnode] = cost + ncost;
                    pq.offer(new int[]{dist[nnode], nnode});
                }
            }
        }

        System.out.println(dist[end]);
    }
}
