package programmers.level2;

public class prog_행렬_테두리_회전하기 {

	int[][] board;
	int min;

	public int[] solution(int rows, int columns, int[][] queries) {
		int[] answer = new int[queries.length];
		int index = 0;

		initBoard(rows, columns);

		for (int i = 0; i < queries.length; i++) {
			min = Integer.MAX_VALUE;
			int[] query = queries[i];
			rotate(query[0], query[1], query[2], query[3]);
			answer[index++] = min;
		}

		return answer;
	}

	private void initBoard(int rows, int columns) {
		board = new int[rows + 1][columns + 1];
		int number = 1;
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= columns; j++) {
				board[i][j] = number++;
			}
		}
	}

	private void rotate(int x1, int y1, int x2, int y2) {
		int[][] copyBoard = copy(board);
		board[x1][y1] = copyBoard[x1 + 1][y1];
		min = Math.min(min, copyBoard[x1 + 1][y1]);
		for (int j = y1 + 1; j <= y2; j++) {
			board[x1][j] = copyBoard[x1][j - 1];
			min = Math.min(min, copyBoard[x1][j - 1]);
		}
		board[x1][y2] = copyBoard[x1][y2 - 1];
		min = Math.min(min, copyBoard[x1][y2 - 1]);
		for (int i = x1 + 1; i <= x2; i++) {
			board[i][y2] = copyBoard[i - 1][y2];
			min = Math.min(min, copyBoard[i - 1][y2]);
		}
		board[x2][y2] = copyBoard[x2 - 1][y2];
		min = Math.min(min, copyBoard[x2 - 1][y2]);
		for (int j = y2 - 1; j >= y1; j--) {
			board[x2][j] = copyBoard[x2][j + 1];
			min = Math.min(min, copyBoard[x2][j + 1]);
		}
		board[x2][y1] = copyBoard[x2][y1 + 1];
		min = Math.min(min, copyBoard[x2][y1 + 1]);
		for (int i = x2 - 1; i >= x1; i--) {
			board[i][y1] = copyBoard[i + 1][y1];
			min = Math.min(min, copyBoard[i + 1][y1]);
		}
	}

	private int[][] copy(int[][] arr) {
		int[][] result = new int[arr.length][arr[0].length];
		for (int i = 0; i < result.length; i++) {
			for (int j = 0; j < result[0].length; j++) {
				result[i][j] = arr[i][j];
			}
		}
		return result;
	}
}
