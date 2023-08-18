package programmers.level2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class prog_튜플 {
	public int[] solution(String s) {
		int[] answer;
		List<String> list = new ArrayList<>();
		List<List<Integer>> lists = new ArrayList<>();

		String[] strings = s.split("\\{");
		for (int i = 0; i < strings.length; i++) {
			strings[i] = strings[i].replaceAll("[,\\}]", " ");
			if (strings[i].length() > 0) {
				list.add(strings[i]);
			}
		}

		for (String str : list) {
			List<Integer> numberList = new ArrayList<>();
			String[] numbers = str.split(" ");
			for (String number : numbers) {
				numberList.add(Integer.parseInt(number));
			}
			lists.add(numberList);
		}

		Collections.sort(lists, (o1, o2) -> o1.size() - o2.size());

		Set<Integer> set = new HashSet<>();
		answer = new int[lists.size()];
		for (int i = 0; i < lists.size(); i++) {
			List<Integer> numbers = lists.get(i);
			for (int number : numbers) {
				if (!set.contains(number)) {
					set.add(number);
					answer[i] = number;
					break;
				}
			}
		}

		return answer;
	}
}
