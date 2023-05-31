package baekjoon.gold3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class baek_사회망_서비스 {

	static int N;
	static boolean[] visited;
	static List<Integer>[] graph;
	static int[][] dp; // [i][j] 일 때, i: 노드 번호, j : 0 -> 해당 노드가 얼리어댑터가 아닐 때, j : 1 -> 해당 노드가 얼리어댑터일 때
	static int answer;

	public static void main(String[] args) throws IOException {
		input();
		solution();
		output();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		init();
		for (int i = 1; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			graph[start].add(end);
			graph[end].add(start);
		}
	}

	static void init() {
		dp = new int[N + 1][2];
		visited = new boolean[N + 1];
		graph = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			graph[i] = new ArrayList<>();
		}
	}

	static void solution() {
		dfs(1); // 트리 구조이기 때문에 1부터 시작
		answer = Math.min(dp[1][0], dp[1][1]);
	}

	static void dfs(int number) {
		visited[number] = true;
		dp[number][0] = 0; // 해당 number가 얼리어답터가 아닌 경우
		dp[number][1] = 1; // 해당 number가 얼리어답터인 경우(우선 시작 시 해당 지점 얼리어답터이므로 개수 1)

		for (int child : graph[number]) {
			if (!visited[child]) { // dfs 중복 방문 방지
				dfs(child); // dfs 재귀호출을 통해 자식 노드의 dp 값을 미리 구한다.
				dp[number][0] += dp[child][1]; // 자식 노드가 무조건 얼리어답터여야한다.
				dp[number][1] += Math.min(dp[child][0], dp[child][1]);
				// 왜냐하면 최소의 얼리어답터 인원을 뽑기 때문에 자식 노드가 얼리어답터 일수도, 아닐수도 있다.
			}
		}
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answer));
		bw.flush();
	}
}
