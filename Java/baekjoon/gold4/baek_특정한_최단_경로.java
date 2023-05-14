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

public class baek_특정한_최단_경로 {

	static class Node { // idx 로 이동하는데 드는 비용 cost
		int idx;
		int cost;

		Node(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}
	}

	static int N, E, v1, v2;
	static List<List<Node>> graph = new ArrayList<>();
	static int answer = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {
		input();
		solution();
		output();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		init();
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			graph.get(a).add(new Node(b, c));
			graph.get(b).add(new Node(a, c));
		}
		st = new StringTokenizer(br.readLine(), " ");
		v1 = Integer.parseInt(st.nextToken());
		v2 = Integer.parseInt(st.nextToken());
	}

	static void init() {
		for (int i = 0; i <= N; i++) {
			graph.add(new ArrayList<>());
		}
	}

	static void solution() {
		int[] distFrom1 = dijkstra(1);
		int[] distFromV1 = dijkstra(v1);
		int[] distFromV2 = dijkstra(v2);

		// 1 -> v1 -> v2 -> N 중 1 -> v2 -> v1 -> N 최솟값
		if (hasPath(distFrom1, v1) && hasPath(distFromV1, v2) && hasPath(distFromV2, N)) {
			answer = Math.min(answer, distFrom1[v1] + distFromV1[v2] + distFromV2[N]);
		}
		if (hasPath(distFrom1, v2) && hasPath(distFromV2, v1) && hasPath(distFromV1, N)) {
			answer = Math.min(answer, distFrom1[v2] + distFromV2[v1] + distFromV1[N]);
		}

		// 경로가 없다면 -1
		if (answer == Integer.MAX_VALUE) {
			answer = -1;
		}
	}

	static int[] dijkstra(int from) {
		int[] dist = new int[N + 1];
		for (int i = 0; i <= N; i++) {
			dist[i] = Integer.MAX_VALUE;
		}
		dist[from] = 0;
		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
		pq.add(new Node(from, 0));
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
		return dist;
	}

	static boolean hasPath(int[] dist, int idx) {
		return dist[idx] != Integer.MAX_VALUE;
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answer));
		bw.flush();
	}
}
