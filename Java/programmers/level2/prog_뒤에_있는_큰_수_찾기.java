package programmers.level2;

public class prog_뒤에_있는_큰_수_찾기 {
	public int[] solution(int[] numbers) {
		int[] answer = new int[numbers.length];
		int[] dp = new int[numbers.length];
		answer[numbers.length - 1] = -1;

		for (int i = numbers.length - 2; i >= 0; i--) {
			for (int j = i + 1; j < numbers.length; j++) {
				if (numbers[i] < numbers[j]) {
					answer[i] = numbers[j];
					dp[i] = j;
					break;
				} else {
					if (answer[j] == -1) {
						answer[i] = -1;
						break;
					}
					if (dp[j] != 0) {
						j = dp[j] - 1;
					}
				}
				if (j == numbers.length - 1) {
					answer[i] = -1;
				}
			}
		}

		return answer;
	}
}
