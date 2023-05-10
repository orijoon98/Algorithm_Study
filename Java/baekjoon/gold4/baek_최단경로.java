package baekjoon.gold4;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class baek_최단경로 {

	static class Node {
		int idx;
		int cost;

		Node(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}
	}

	static int V, E, K;
	static List<List<Node>> graph = new ArrayList<>();
	static int[] dist;

	public static void main(String[] args) throws IOException {
		input();
		solution();
		output();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(br.readLine());
		init();
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			graph.get(a).add(new Node(b, cost));
		}
	}

	static void init() {
		dist = new int[V + 1];
		for (int i = 0; i <= V; i++) {
			dist[i] = Integer.MAX_VALUE;
		}
		dist[K] = 0;
		for (int i = 0; i <= V; i++) {
			graph.add(new ArrayList<>());
		}
	}

	static void solution() {
		PriorityQueue<Node> pq = new PriorityQueue<Node>((o1, o2) -> o1.cost - o2.cost);
		pq.add(new Node(K, 0));
		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			if (dist[cur.idx] < cur.cost) {
				continue;
			}
			for (int i = 0; i < graph.get(cur.idx).size(); i++) {
				Node next = graph.get(cur.idx).get(i);
				if (dist[next.idx] > dist[cur.idx] + next.cost) {
					dist[next.idx] = dist[cur.idx] + next.cost;
					pq.add(new Node(next.idx, dist[next.idx]));
				}
			}
		}
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for (int i = 1; i <= V; i++) {
			if (dist[i] == Integer.MAX_VALUE) {
				bw.write("INF");
			} else {
				bw.write(String.valueOf(dist[i]));
			}
			bw.write("\n");
		}
		bw.flush();
	}
}
