package programmers.level2;

import java.util.LinkedList;
import java.util.Queue;

public class prog_리코쳇_로봇 {

	private class Pos {
		int x;
		int y;

		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	char[][] board;
	int[][] distance;
	int[] dx = {1, 0, -1, 0};
	int[] dy = {0, 1, 0, -1};
	Queue<Pos> queue = new LinkedList<>();
	Pos target;

	public int solution(String[] board) {
		init(board);
		return bfs();
	}

	private void init(String[] board) {
		this.board = new char[board.length][board[0].length()];
		this.distance = new int[board.length][board[0].length()];

		for (int i = 0; i < board.length; i++) {
			char[] infos = board[i].toCharArray();
			for (int j = 0; j < infos.length; j++) {
				this.board[i][j] = infos[j];
				this.distance[i][j] = -1;
				if (this.board[i][j] == 'R') {
					queue.add(new Pos(i, j));
					this.distance[i][j] = 0;
				}
				if (this.board[i][j] == 'G') {
					target = new Pos(i, j);
				}
			}
		}
	}

	private int bfs() {
		while (!queue.isEmpty()) {
			Pos cur = queue.poll();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				while (nx >= 0 && ny >= 0 && nx < board.length && ny < board[0].length && board[nx][ny] != 'D') {
					int nnx = nx + dx[dir];
					int nny = ny + dy[dir];
					if ((nnx < 0 || nny < 0 || nnx >= board.length || nny >= board[0].length || board[nnx][nny] == 'D')
						&& distance[nx][ny] < 0) {
						distance[nx][ny] = distance[cur.x][cur.y] + 1;
						queue.add(new Pos(nx, ny));
						if (nx == target.x && ny == target.y) {
							return distance[nx][ny];
						}
					}
					nx += dx[dir];
					ny += dy[dir];
				}
			}
		}
		return -1;
	}
}
