package baekjoon.gold5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class baek_숨바꼭질_3 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int N, K;
	static int[] dist = new int[100001]; // 수빈이의 위치에서 idx 까지 이동하는 최소시간
	static int answer;

	public static void main(String[] args) throws IOException {
		input();
		solution();
		output();
	}

	static void input() throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
	}

	static void solution() {
		for (int i = 0; i < dist.length; i++) {
			dist[i] = Integer.MAX_VALUE;
		}
		PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> dist[o1] - dist[o2]);
		dist[N] = 0;
		pq.add(N);
		while (!pq.isEmpty()) {
			int cur = pq.poll();
			if (cur == K) {
				break;
			}
			if (able(2 * cur, dist[cur])) {
				dist[2 * cur] = dist[cur];
				pq.add(2 * cur);

			}
			if (able(cur + 1, dist[cur] + 1)) {
				dist[cur + 1] = dist[cur] + 1;
				pq.add(cur + 1);
			}
			if (able(cur - 1, dist[cur] + 1)) {
				dist[cur - 1] = dist[cur] + 1;
				pq.add(cur - 1);
			}
		}
		answer = dist[K];
	}

	static boolean able(int n, int cost) {
		return n >= 0 && n <= 100000 && dist[n] > cost;
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answer));
		bw.flush();
	}
}
