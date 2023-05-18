package baekjoon.gold4;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class baek_해킹 {

	static class Node {
		int idx;
		int time;

		Node(int idx, int time) {
			this.idx = idx;
			this.time = time;
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int T;
	static int n, d, c;
	static ArrayList<Node>[] nodes;
	static int[] distance;
	static int count, totalTime;

	public static void main(String[] args) throws IOException {
		inputT();
		for (int t = 0; t < T; t++) {
			input();
			solution();
			output();
		}
	}

	static void inputT() throws IOException {
		T = Integer.parseInt(br.readLine());
	}

	static void init() {
		nodes = new ArrayList[n + 1];
		distance = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			nodes[i] = new ArrayList<>();
			distance[i] = Integer.MAX_VALUE;
		}
		count = 0;
		totalTime = 0;
	}

	static void input() throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		init();
		for (int i = 0; i < d; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			nodes[b].add(new Node(a, s));
		}
	}

	static void solution() {
		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.time - o2.time);
		pq.add(new Node(c, 0));
		distance[c] = 0;
		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			if (cur.time > distance[cur.idx]) {
				continue;
			}
			for (Node next : nodes[cur.idx]) {
				if (distance[next.idx] > distance[cur.idx] + next.time) {
					distance[next.idx] = distance[cur.idx] + next.time;
					pq.add(new Node(next.idx, distance[next.idx]));
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (distance[i] != Integer.MAX_VALUE) {
				count++;
				totalTime = Math.max(totalTime, distance[i]);
			}
		}
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(count));
		bw.write(" ");
		bw.write(String.valueOf(totalTime));
		bw.write("\n");
		bw.flush();
	}
}
