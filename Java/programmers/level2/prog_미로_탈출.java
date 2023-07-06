package programmers.level2;

import java.util.LinkedList;
import java.util.Queue;

public class prog_미로_탈출 {

	int[][] board, dist;
	int[] dx = {1, 0, -1, 0};
	int[] dy = {0, 1, 0, -1};
	int xSize, ySize;
	Queue<Pos> queue = new LinkedList<>();
	int answer = 0;

	static class Pos {
		int x;
		int y;

		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public int solution(String[] maps) {
		xSize = maps.length;
		ySize = maps[0].length();
		board = new int[xSize][ySize];
		dist = new int[xSize][ySize];

		for (int i = 0; i < xSize; i++) {
			char[] chars = maps[i].toCharArray();
			for (int j = 0; j < ySize; j++) {
				board[i][j] = chars[j];
			}
		}

		setStart('S');
		bfs('L');
		setStart('L');
		bfs('E');

		return answer;
	}

	private void setStart(char start) {
		queue.clear();
		initDist();
		for (int i = 0; i < xSize; i++) {
			for (int j = 0; j < ySize; j++) {
				if (board[i][j] == start) {
					queue.add(new Pos(i, j));
					dist[i][j] = 0;
					return;
				}
			}
		}
	}

	private void bfs(char destination) {
		if (answer == -1) {
			return;
		}
		while (!queue.isEmpty()) {
			Pos cur = queue.poll();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= xSize || ny >= ySize) {
					continue;
				}
				if (board[nx][ny] == 'X' || dist[nx][ny] >= 0) {
					continue;
				}
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
				queue.add(new Pos(nx, ny));
				if (board[nx][ny] == destination) {
					answer += dist[nx][ny];
					return;
				}
			}
		}
		answer = -1;
	}

	private void initDist() {
		for (int i = 0; i < dist.length; i++) {
			for (int j = 0; j < dist[0].length; j++) {
				dist[i][j] = -1;
			}
		}
	}
}
