package baekjoon.gold5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class baek_ABCDE {

	static int N, M;
	static List<Integer>[] friend;
	static boolean[] visited;
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		input();
		solution();
		output();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		friend = new List[N];
		for (int i = 0; i < N; i++) {
			friend[i] = new ArrayList<>();
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			friend[a].add(b);
			friend[b].add(a);
		}
	}

	static void solution() {
		for (int i = 0; i < N; i++) {
			if (answer == 1) {
				break;
			}
			visited = new boolean[N];
			visited[i] = true;
			dfs(i, 0);
		}
	}

	static void dfs(int start, int depth) {
		if (depth == 4) {
			answer = 1;
			return;
		}
		for (int i = 0; i < friend[start].size(); i++) {
			int next = friend[start].get(i);
			if (!visited[next]) {
				visited[next] = true;
				dfs(next, depth + 1);
				visited[next] = false;
			}
		}
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answer));
		bw.flush();
	}
}
