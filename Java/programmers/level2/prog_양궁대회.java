package programmers.level2;

class prog_양궁대회 {

	int n;
	int diff;
	int[] lion;
	int[] apeach;
	int[] answer;

	public int[] solution(int n, int[] info) {
		this.n = n;
		this.diff = 0;
		this.lion = new int[11];
		this.apeach = info;
		this.answer = new int[] {-1};

		dfs(0, 10);

		return answer;
	}

	void dfs(int depth, int start) {
		if (depth == n) {
			int lionScore = 0;
			int apeachScore = 0;
			for (int i = 0; i < 11; i++) {
				if (apeach[i] < lion[i]) {
					lionScore += 10 - i;
				}
				if (apeach[i] >= lion[i] && apeach[i] > 0) {
					apeachScore += 10 - i;
				}
			}
			if (lionScore > apeachScore && (lionScore - apeachScore) > diff) {
				diff = lionScore - apeachScore;
				answer = lion.clone();
			}
			return;
		}
		for (int i = start; i >= 0; i--) {
			lion[i]++;
			dfs(depth + 1, i);
			lion[i]--;
		}
	}
}