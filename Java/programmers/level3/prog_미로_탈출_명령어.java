package programmers.level3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class prog_미로_탈출_명령어 {
	class Direction {
		String command;
		int dx;
		int dy;

		Direction(String command, int dx, int dy) {
			this.command = command;
			this.dx = dx;
			this.dy = dy;
		}
	}

	int N, M, R, C;
	char[][] board;
	List<Direction> directions = new ArrayList<>();
	boolean flag = false; // 답이 나오면 바로 dfs 종료
	String answer = "impossible";

	public String solution(int n, int m, int x, int y, int r, int c, int k) {
		init(n, m, x, y, r, c);
		dfs(x, y, k, "");
		return answer;
	}

	void init(int n, int m, int x, int y, int r, int c) {
		N = n;
		M = m;
		R = r;
		C = c;
		// 사전 순서로 넣기
		directions.add(new Direction("d", 1, 0));
		directions.add(new Direction("l", 0, -1));
		directions.add(new Direction("r", 0, 1));
		directions.add(new Direction("u", -1, 0));
		board = new char[n + 1][m + 1];
		for (int i = 1; i <= n; i++) {
			Arrays.fill(board[i], '.');
		}
		board[x][y] = 'S';
		board[r][c] = 'E';
	}

	void dfs(int x, int y, int cnt, String commands) {
		if (cnt == 0 || flag) {
			if (board[x][y] == 'E') {
				answer = commands;
				flag = true;
			}
			return;
		}
		for (Direction dir : directions) {
			if (flag)
				return;
			int nx = x + dir.dx;
			int ny = y + dir.dy;
			if (nx < 1 || ny < 1 || nx > N || ny > M)
				continue;
			if (getDistance(nx, ny) > cnt || (cnt - getDistance(nx, ny)) % 2 == 0)
				continue;
			dfs(nx, ny, cnt - 1, commands + dir.command);
		}
		if (flag)
			return;
	}

	int getDistance(int x, int y) {
		return Math.abs(R - x) + Math.abs(C - y);
	}
}
