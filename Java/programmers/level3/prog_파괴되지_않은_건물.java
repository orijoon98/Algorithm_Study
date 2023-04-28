package programmers.level3;

public class prog_파괴되지_않은_건물 {
	public int solution(int[][] board, int[][] skill) {
		int answer = 0;
		int[][] prefixSum = new int[board.length + 1][board[0].length + 1]; // 누적합을 위한 보드

		for (int i = 0; i < skill.length; i++) {
			int type = skill[i][0];
			int r1 = skill[i][1];
			int c1 = skill[i][2];
			int r2 = skill[i][3];
			int c2 = skill[i][4];
			int degree = skill[i][5];

			if (type == 1) {
				prefixSum[r1][c1] -= degree;
				prefixSum[r2 + 1][c2 + 1] -= degree;
				prefixSum[r1][c2 + 1] += degree;
				prefixSum[r2 + 1][c1] += degree;
			} else {
				prefixSum[r1][c1] += degree;
				prefixSum[r2 + 1][c2 + 1] += degree;
				prefixSum[r1][c2 + 1] -= degree;
				prefixSum[r2 + 1][c1] -= degree;
			}
		}

		// 위에서 아래로 누적합
		for (int i = 1; i < prefixSum.length; i++) {
			for (int j = 0; j < prefixSum[0].length; j++) {
				prefixSum[i][j] += prefixSum[i - 1][j];
			}
		}

		// 왼쪽에서 오른쪽으로 누적합
		for (int i = 0; i < prefixSum.length; i++) {
			for (int j = 1; j < prefixSum[0].length; j++) {
				prefixSum[i][j] += prefixSum[i][j - 1];
			}
		}

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				board[i][j] += prefixSum[i][j];
				if (board[i][j] > 0) {
					answer++;
				}
			}
		}

		return answer;
	}
}
