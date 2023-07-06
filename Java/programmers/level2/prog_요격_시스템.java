package programmers.level2;

import java.util.Arrays;

public class prog_요격_시스템 {
	public int solution(int[][] targets) {
		int answer = 0;

		Arrays.sort(targets, (o1, o2) -> {
			if (o1[1] == o2[1]) {
				return o1[0] - o2[0];
			}
			return o1[1] - o2[1];
		});

		int end = 0;
		for (int i = 0; i < targets.length; i++) {
			if (targets[i][0] >= end) {
				end = targets[i][1];
				answer++;
			}
		}

		return answer;
	}

	private void print(int[][] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.printf("%s %s\n", arr[i][0], arr[i][1]);
		}
	}
}
