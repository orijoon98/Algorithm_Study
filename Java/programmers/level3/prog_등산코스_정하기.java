package programmers.level3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class prog_등산코스_정하기 {

	class Node {
		int number;
		List<Edge> edges;
		boolean isGate;
		boolean isSummit;

		Node(int number) {
			this.number = number;
			this.edges = new ArrayList<>();
			this.isGate = false;
			this.isSummit = false;
		}
	}

	class Edge {
		Node node;
		int cost;

		Edge(Node node, int cost) {
			this.node = node;
			this.cost = cost;
		}
	}

	Node[] nodes;
	boolean[] visited;
	int summitNumber = 0;
	int intensity = Integer.MAX_VALUE;

	public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
		visited = new boolean[n + 1];
		initNodes(n, paths, gates, summits);
		dijkstra(n, gates, summits);
		return new int[] {summitNumber, intensity};
	}

	void dijkstra(int n, int[] gates, int[] summits) {
		int[] intensity = new int[n + 1];
		Arrays.fill(intensity, Integer.MAX_VALUE);
		PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
		for (int gate : gates) {
			pq.add(new Edge(nodes[gate], 0));
			intensity[gate] = 0;
		}
		while (!pq.isEmpty()) {
			Edge cur = pq.poll();
			if (cur.node.isSummit) {
				continue;
			}
			if (intensity[cur.node.number] < cur.cost) {
				continue;
			}
			for (Edge next : nodes[cur.node.number].edges) {
				if (next.node.isGate) {
					continue;
				}
				int cost = (next.cost == Integer.MAX_VALUE) ? cur.cost : Math.max(cur.cost, next.cost);
				if (intensity[next.node.number] > cost) {
					intensity[next.node.number] = cost;
					pq.add(new Edge(next.node, intensity[next.node.number]));
				}
			}
		}
		Arrays.sort(summits);
		for (int summit : summits) {
			if (intensity[summit] < this.intensity) {
				this.intensity = intensity[summit];
				summitNumber = summit;
			}
		}
	}

	void initNodes(int n, int[][] paths, int[] gates, int[] summits) {
		nodes = new Node[n + 1];
		for (int i = 1; i <= n; i++) {
			nodes[i] = new Node(i);
		}
		for (int i = 0; i < paths.length; i++) {
			Node a = nodes[paths[i][0]];
			Node b = nodes[paths[i][1]];
			int cost = paths[i][2];
			a.edges.add(new Edge(b, cost));
			b.edges.add(new Edge(a, cost));
		}
		for (int i = 0; i < gates.length; i++) {
			Node node = nodes[gates[i]];
			node.isGate = true;
		}
		for (int i = 0; i < summits.length; i++) {
			Node node = nodes[summits[i]];
			node.isSummit = true;
		}
	}
}
