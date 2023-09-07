package programmers.level3;

public class prog_스티커_모으기_2 {
	public int solution(int sticker[]) {
		int answer = 0;

		if (sticker.length == 1)
			return sticker[0];

		// dp[i] = i 번째까지의 최대 합
		int[] dp = new int[sticker.length];

		// 초기화 : 처음부터 시작
		dp[0] = sticker[0];
		dp[1] = Math.max(sticker[0], sticker[1]);

		for (int i = 0; i < sticker.length - 2; i++) {
			dp[i + 2] = Math.max(dp[i] + sticker[i + 2], dp[i + 1]);
		}

		// 첫 스티커를 사용한 경우는 마지막 스티커를 사용할 수 없음
		answer = dp[sticker.length - 2];

		// 초기화 : 두번째부터 시작
		dp = new int[sticker.length];
		dp[0] = 0;
		dp[1] = sticker[1];

		for (int i = 0; i < sticker.length - 2; i++) {
			dp[i + 2] = Math.max(dp[i] + sticker[i + 2], dp[i + 1]);
		}

		// 첫 스티커를 사용하지 않은 경우는 마지막 스티커를 사용할 수 있음
		answer = Math.max(answer, dp[sticker.length - 1]);

		return answer;
	}

}
