package baekjoon.silver1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baek_안전_영역 {

	static int N;
	static int[][] board;
	static boolean[][] visited;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		input();
		solution();
		output();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		init();
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}

	static void init() {
		board = new int[N][N];
		visited = new boolean[N][N];
	}

	static void resetVisited() {
		visited = new boolean[N][N];
	}

	static void solution() {
		for (int depth = 0; depth <= 100; depth++) {
			resetVisited();
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (!visited[i][j] && board[i][j] > depth) {
						dfs(i, j, depth);
						cnt++;
					}
				}
			}
			answer = Math.max(answer, cnt);
		}
	}

	static void dfs(int x, int y, int depth) {
		visited[x][y] = true;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				continue;
			}
			if (visited[nx][ny] || board[nx][ny] <= depth) {
				continue;
			}
			dfs(nx, ny, depth);
		}
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answer));
		bw.flush();
	}
}
