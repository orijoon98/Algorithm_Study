package programmers.level2;

public class prog_광물_캐기 {
	int answer = Integer.MAX_VALUE;

	public int solution(int[] picks, String[] minerals) {
		for (int i = 0; i < 3; i++) {
			if (picks[i] > 0) {
				int[] picksCopy = picks.clone();
				picksCopy[i]--;
				dfs(picksCopy, minerals, i, 0, 0);
			}
		}
		return answer;
	}

	private void dfs(int[] picks, String[] minerals, int pick, int index, int sum) {
		for (int i = 0; i < 5; i++) {
			if (index + i >= minerals.length) {
				break;
			}
			if (pick == 0) {
				sum += 1;
			}
			if (pick == 1) {
				if (minerals[index + i].equals("diamond")) {
					sum += 5;
				} else {
					sum += 1;
				}
			}
			if (pick == 2) {
				if (minerals[index + i].equals("diamond")) {
					sum += 25;
				}
				if (minerals[index + i].equals("iron")) {
					sum += 5;
				}
				if (minerals[index + i].equals("stone")) {
					sum += 1;
				}
			}
		}
		index = index + 5;
		if (index >= minerals.length) {
			answer = Math.min(answer, sum);
			return;
		}
		if (picks[0] == 0 && picks[1] == 0 && picks[2] == 0) {
			answer = Math.min(answer, sum);
			return;
		}
		if (sum >= answer) {
			return;
		}
		for (int i = 0; i < 3; i++) {
			if (picks[i] > 0) {
				int[] picksCopy = picks.clone();
				picksCopy[i]--;
				dfs(picksCopy, minerals, i, index, sum);
			}
		}
	}
}
