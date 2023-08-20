package programmers.level3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class prog_합승_택시_요금 {
	class Edge {
		int n;
		int cost;

		Edge(int n, int cost) {
			this.n = n;
			this.cost = cost;
		}
	}

	int N;
	List<List<Edge>> nodes = new ArrayList<>();
	int answer = Integer.MAX_VALUE;

	public int solution(int n, int s, int a, int b, int[][] fares) {
		init(n, fares);

		int[] together = dijkstra(s);

		for (int i = 1; i <= n; i++) {
			int[] alone = dijkstra(i);
			int total = together[i] + alone[a] + alone[b];
			answer = Math.min(answer, total);
		}

		return answer;
	}

	void init(int n, int[][] fares) {
		N = n;
		for (int i = 0; i <= n; i++) {
			nodes.add(new ArrayList<>());
		}
		for (int[] fare : fares) {
			int a = fare[0];
			int b = fare[1];
			int cost = fare[2];
			nodes.get(a).add(new Edge(b, cost));
			nodes.get(b).add(new Edge(a, cost));
		}
	}

	int[] dijkstra(int start) {
		int[] distance = new int[N + 1];
		Arrays.fill(distance, Integer.MAX_VALUE);
		PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
		distance[start] = 0;
		pq.add(new Edge(start, 0));

		while (!pq.isEmpty()) {
			Edge cur = pq.poll();
			if (distance[cur.n] < cur.cost) {
				continue;
			}
			List<Edge> edges = nodes.get(cur.n);
			for (Edge edge : edges) {
				if (distance[edge.n] > cur.cost + edge.cost) {
					distance[edge.n] = cur.cost + edge.cost;
					pq.add(new Edge(edge.n, distance[edge.n]));
				}
			}
		}

		return distance;
	}
}
