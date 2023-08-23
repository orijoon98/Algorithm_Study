package programmers.level3;

import java.util.Arrays;

public class prog_인사고과 {
	public int solution(int[][] scores) {
		int answer = 1;
		int[] wanho = scores[0];
		int wanhoSum = scores[0][0] + scores[0][1];

		// 근무태도 내림차순, 동료평가점수 오름차순 정렬
		Arrays.sort(scores, (o1, o2) -> {
			if (o1[0] == o2[0]) {
				return o1[1] - o2[1];
			}
			return o2[0] - o1[0];
		});

		int max = 0; // 동료평가점수 최대값

		for (int i = 0; i < scores.length; i++) {
			if (max > scores[i][1]) { // 인센티브를 받지 못하는 경우
				if (scores[i][0] == wanho[0] && scores[i][1] == wanho[1]) {
					return -1;
				}
				continue;
			} else {
				max = scores[i][1];
				if (scores[i][0] + scores[i][1] > wanhoSum) {
					answer++;
				}
			}
		}

		return answer;
	}
}
