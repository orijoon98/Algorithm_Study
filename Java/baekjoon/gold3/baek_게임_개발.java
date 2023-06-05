package baekjoon.gold3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class baek_게임_개발 {

	static int N;
	static int[] time; // i 번 건물을 짓는데 걸리는 시간
	static List<List<Integer>> necessary = new ArrayList<>(); // i 번 건물을 짓는데 필요한 건물
	static int[] indegree; // 위상정렬에 사용할 진입차수 저장 배열

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
			time[i] = Integer.parseInt(st.nextToken());
			while (st.hasMoreTokens()) {
				String token = st.nextToken();
				if (!token.equals("-1")) {
					necessary.get(Integer.parseInt(token)).add(i);
					indegree[i]++;
				}
			}
		}
	}

	static void init() {
		time = new int[N + 1];
		indegree = new int[N + 1];
		for (int i = 0; i <= N; i++) {
			necessary.add(new ArrayList<>());
		}
	}

	static void solution() {
		PriorityQueue<Integer> pq = new PriorityQueue<>(((o1, o2) -> time[o1] - time[o2]));

		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				pq.add(i);
			}
		}

		while (!pq.isEmpty()) {
			int cur = pq.poll();
			for (int i = 0; i < necessary.get(cur).size(); i++) {
				int next = necessary.get(cur).get(i);
				indegree[next]--;
				if (indegree[next] == 0) {
					time[next] += time[cur];
					pq.add(next);
				}
			}
		}
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for (int i = 1; i <= N; i++) {
			bw.write(String.valueOf(time[i]));
			bw.newLine();
		}
		bw.flush();
	}
}
