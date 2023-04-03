package baekjoon.silver2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class baek_DFS와_BFS {

    static int N, M, V;
    static boolean[][] edge = new boolean[1001][1001];
    static boolean[] visited = new boolean[1001];
    static List<List<Integer>> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int node1 = Integer.parseInt(st.nextToken());
            int node2 = Integer.parseInt(st.nextToken());
            edge[node1][node2] = true;
            edge[node2][node1] = true;
        }
    }

    static void solution() {
        answer.add(new ArrayList<>());
        answer.add(new ArrayList<>());
        dfs(V);
        visited = new boolean[1001];
        bfs(V);
    }

    static void dfs(int start) {
        answer.get(0).add(start);
        visited[start] = true;
        for (int i = 1; i <= N; i++) {
            if (edge[start][i] && !visited[i]) {
                dfs(i);
            }
        }
    }

    static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        answer.get(1).add(start);
        visited[start] = true;
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int next = 1; next <= N; next++) {
                if (edge[cur][next] && !visited[next]) {
                    queue.add(next);
                    answer.get(1).add(next);
                    visited[next] = true;
                }
            }
        }
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < answer.get(0).size(); i++) {
            bw.write(String.valueOf(answer.get(0).get(i)));
            bw.write(" ");
        }
        bw.write("\n");
        for (int i = 0; i < answer.get(1).size(); i++) {
            bw.write(String.valueOf(answer.get(1).get(i)));
            bw.write(" ");
        }
        bw.flush();
    }
}
