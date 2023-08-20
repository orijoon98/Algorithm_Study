package programmers.level2;

import java.util.HashSet;
import java.util.Set;

public class prog_롤케이크_자르기 {
	public int solution(int[] topping) {
		int answer = 0;

		int[] dpLeft = new int[topping.length]; // 0 부터 i 까지의 종류 수
		int[] dpRight = new int[topping.length]; // i 부터 끝까지의 종류 수

		Set<Integer> set = new HashSet<>();

		for (int i = 0; i < topping.length; i++) {
			set.add(topping[i]);
			dpLeft[i] = set.size();
		}

		set.clear();

		for (int i = topping.length - 1; i >= 0; i--) {
			set.add(topping[i]);
			dpRight[i] = set.size();
		}

		for (int i = 0; i < topping.length - 1; i++) {
			if (dpLeft[i] == dpRight[i + 1]) {
				answer++;
			}
		}

		return answer;
	}
}
