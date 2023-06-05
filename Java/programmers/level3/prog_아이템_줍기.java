package programmers.level3;

import java.util.LinkedList;
import java.util.Queue;

public class prog_아이템_줍기 {

	static class CharacterPosition {
		int x;
		int y;
		int moveCnt;

		public CharacterPosition(int x, int y, int moveCnt) {
			this.x = x;
			this.y = y;
			this.moveCnt = moveCnt;
		}
	}

	public static int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
		int answer = 0;
		int[][] board = new int[101][101];
		boolean[][] visited = new boolean[101][101];
		int[] dx = {0, 0, -1, 1};
		int[] dy = {1, -1, 0, 0};

		for (int i = 0; i < rectangle.length; i++) {
			int[] eachRectangle = rectangle[i];
			// 모든 좌표 값의 크기를 2배로 해준다.
			for (int x = eachRectangle[0] * 2; x <= eachRectangle[2] * 2; x++) {
				for (int y = eachRectangle[1] * 2; y <= eachRectangle[3] * 2; y++) {
					board[x][y] = 1;
				}
			}
		}
		// 모서리 영역을 제외한 내부 영역을 0으로 채운다.
		for (int i = 0; i < rectangle.length; i++) {
			int[] eachRectangle = rectangle[i];
			for (int x = eachRectangle[0] * 2 + 1; x <= eachRectangle[2] * 2 - 1; x++) {
				for (int y = eachRectangle[1] * 2 + 1; y <= eachRectangle[3] * 2 - 1; y++) {
					board[x][y] = 0;
				}
			}
		}

		CharacterPosition characterPosition = new CharacterPosition(characterX * 2, characterY * 2, 0);
		Queue<CharacterPosition> q = new LinkedList<>();
		q.add(characterPosition);
		visited[characterX * 2][characterY * 2] = true;

		while (!q.isEmpty()) {
			CharacterPosition tempCharacterPosition = q.poll();
			if (tempCharacterPosition.x == itemX * 2 && tempCharacterPosition.y == itemY * 2) {
				answer = tempCharacterPosition.moveCnt / 2;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nextX = dx[i] + tempCharacterPosition.x;
				int nextY = dy[i] + tempCharacterPosition.y;
				if (nextX < 2 || nextX > 100 || nextY < 2 || nextY > 100) {
					continue;
				}
				if (!visited[nextX][nextY] && board[nextX][nextY] == 1) { // 방문하지 않은 모서리 영역이라면
					q.offer(new CharacterPosition(nextX, nextY, tempCharacterPosition.moveCnt + 1));
					visited[nextX][nextY] = true;
				}
			}
		}

		return answer;
	}
}
