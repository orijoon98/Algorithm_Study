package programmers.level4;

import java.util.Arrays;

public class prog_징검다리 {

	public int solution(int distance, int[] rocks, int n) {
		int answer = 0;
		int left = 0, right = distance;

		Arrays.sort(rocks);

		while (left <= right) {
			int mid = (left + right) / 2;
			if (getRemovedRockCnt(rocks, mid, distance) <= n) {
				answer = mid;
				left = mid + 1;
			} else
				right = mid - 1;

		}

		return answer;
	}

	private int getRemovedRockCnt(int[] rocks, int mid, int distance) {
		int before = 0;
		int end = distance;

		int removeCnt = 0;
		for (int i = 0; i < rocks.length; i++) {
			if (rocks[i] - before < mid)
				removeCnt++;
			else
				before = rocks[i];
		}
		if (end - before < mid)
			removeCnt++;

		return removeCnt;
	}
}
