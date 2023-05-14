package baekjoon.gold4;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class baek_행성_연결 {

	static class Edge {
		int a;
		int b;
		long cost;

		Edge(int a, int b, long cost) {
			this.a = a;
			this.b = b;
			this.cost = cost;
		}
	}

	static int N;
	static long[][] C;
	static int[] parent;
	static long answer;

	public static void main(String[] args) throws IOException {
		input();
		solution();
		output();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		init();
		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int j = 1; j <= N; j++) {
				C[i][j] = Long.parseLong(st.nextToken());
			}
		}
	}

	static void init() {
		C = new long[N + 1][N + 1];
		parent = new int[N + 1];
		for (int i = 0; i <= N; i++) {
			parent[i] = i;
		}
	}

	static void solution() {
		List<Edge> edges = new ArrayList<>();
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				edges.add(new Edge(i, j, C[i][j]));
			}
		}
		Collections.sort(edges, (o1, o2) -> (int)(o1.cost - o2.cost)); // 간선 비용 오름차순 정렬
		int cnt = 0;
		for (Edge edge : edges) {
			if (find(edge.a) != find(edge.b)) {
				union(edge.a, edge.b);
				cnt++;
				answer += edge.cost;
			}
			if (cnt == N - 1) { // 선택된 간선의 개수가 N - 1 만큼 되면 종료
				break;
			}
		}
	}

	static int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		return find(parent[x]);
	}

	static void union(int x, int y) {
		x = find(x);
		y = find(y);
		if (x <= y) {
			parent[y] = x;
		} else {
			parent[x] = y;
		}
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answer));
		bw.flush();
	}
}
