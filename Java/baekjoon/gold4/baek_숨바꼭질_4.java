package baekjoon.gold4;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class baek_숨바꼭질_4 {

	static final int MAX = 100000;
	static int N, K;
	static int answerTime;
	static List<Integer> answerPath;
	static int[] dp; // dp[i] = 점 i 에 도달할 수 있는 최소 시간
	static Queue<Integer> queue;

	public static void main(String[] args) throws IOException {
		input();
		solution(N, K);
		output();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		init();
	}

	static void init() {
		answerTime = Integer.MAX_VALUE;
		answerPath = new ArrayList<>();
		queue = new LinkedList<>();
		dp = new int[100001];
		Arrays.fill(dp, Integer.MAX_VALUE);
	}

	static void solution(int start, int target) {
		dp[start] = 0; // 시작점은 0초에 도달
		queue.add(start);

		// 최단 시간 구하기
		while (!queue.isEmpty()) {
			int cur = queue.poll();
			if (cur == target) {
				answerTime = dp[cur];
				break;
			}
			int[] next = new int[] {cur - 1, cur + 1, 2 * cur};
			for (int i = 0; i < 3; i++) {
				if (!isInRange(next[i])) {
					continue;
				}
				if (dp[next[i]] != Integer.MAX_VALUE) {
					continue;
				}
				dp[next[i]] = dp[cur] + 1;
				queue.add(next[i]);
			}
		}

		// 최단 경로 구하기
		answerPath.add(target);
		int cur = target;
		int time = answerTime - 1;
		while (true) {
			if (isInRange(cur - 1) && dp[cur - 1] == time) {
				answerPath.add(cur - 1);
				cur -= 1;
			} else if (isInRange(cur + 1) && dp[cur + 1] == time) {
				answerPath.add(cur + 1);
				cur += 1;
			} else if (cur % 2 == 0 && isInRange(cur / 2) && dp[cur / 2] == time) {
				answerPath.add(cur / 2);
				cur /= 2;
			}
			time--;
			if (cur == start) {
				break;
			}
		}
		Collections.reverse(answerPath);
	}

	static boolean isInRange(int n) {
		return 0 <= n && n <= MAX;
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answerTime));
		bw.newLine();
		for (int path : answerPath) {
			bw.write(String.valueOf(path).concat(" "));
		}
		bw.flush();
	}
}
