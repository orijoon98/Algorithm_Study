package programmers.level2;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class prog_거리두기_확인하기 {

	String[][] board = new String[5][5];
	int[][] dist = new int[5][5];
	int[] dx = {1, 0, -1, 0};
	int[] dy = {0, 1, 0, -1};
	Queue<Pos> queue = new LinkedList<>();
	List<Pos> list = new ArrayList<>();
	int[] answer = new int[5];

	public int[] solution(String[][] places) {

		for (int i = 0; i < 5; i++) {
			init(places[i]);
			answer[i] = bfs();
		}

		return answer;
	}

	private class Pos {
		int x;
		int y;

		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	private void init(String[] place) {
		list.clear();
		for (int i = 0; i < place.length; i++) {
			String[] status = place[i].split("");
			for (int j = 0; j < status.length; j++) {
				board[i][j] = status[j];
				if (status[j].equals("P")) {
					list.add(new Pos(i, j));
				}
			}
		}
	}

	private void initBfs() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				dist[i][j] = -1;
			}
		}
		queue.clear();
	}

	private int bfs() {
		for (Pos start : list) {
			initBfs();
			queue.add(new Pos(start.x, start.y));
			dist[start.x][start.y] = 0;
			while (!queue.isEmpty()) {
				Pos cur = queue.poll();
				if (dist[cur.x][cur.y] == 2) // 3 이상의 거리부터는 확인할 필요 없음
					break;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
						continue;
					if (dist[nx][ny] >= 0 || board[nx][ny].equals("X"))
						continue;
					dist[nx][ny] = dist[cur.x][cur.y] + 1;
					queue.add(new Pos(nx, ny));
					if (board[nx][ny].equals("P")) {
						return 0;
					}
				}
			}
		}
		return 1;
	}
}
