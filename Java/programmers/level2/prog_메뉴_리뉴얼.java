package programmers.level2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class prog_메뉴_리뉴얼 {
	Set<String> result = new HashSet<>();
	Map<String, Integer> map = new HashMap<>();
	List<String> answerList = new ArrayList<>();

	public String[] solution(String[] orders, int[] course) {
		for (String order : orders) {
			char[] chars = order.toCharArray();
			Arrays.sort(chars);
			boolean[] visited = new boolean[chars.length];
			for (int courseSize : course) {
				if (courseSize > chars.length) {
					continue;
				}
				combination(chars, visited, 0, chars.length, courseSize);
				for (String str : result) {
					map.put(str, map.getOrDefault(str, 0) + 1);
				}
				result.clear();
			}
		}

		for (int courseSize : course) {
			List<String> tmp = new ArrayList<>();
			for (String str : map.keySet()) {
				if (str.length() == courseSize) {
					tmp.add(str);
				}
			}
			tmp.sort((o1, o2) -> map.get(o2) - map.get(o1));
			if (!tmp.isEmpty()) {
				int maxCnt = map.get(tmp.get(0));
				if (maxCnt < 2) {
					continue;
				}
				tmp = tmp.stream()
					.filter(str -> map.get(str) == maxCnt)
					.collect(Collectors.toList());
				answerList.addAll(tmp);
			}
		}

		Collections.sort(answerList);

		String[] answer = new String[answerList.size()];
		int index = 0;
		for (String str : answerList) {
			answer[index++] = str;
		}

		return answer;
	}

	// nCr
	void combination(char[] chars, boolean[] visited, int start, int n, int r) {
		if (r == 0) {
			String str = "";
			for (int i = 0; i < n; i++) {
				if (visited[i]) {
					str += String.valueOf(chars[i]);
				}
			}
			result.add(str);
			return;
		}
		for (int i = start; i < n; i++) {
			visited[i] = true;
			combination(chars, visited, i + 1, n, r - 1);
			visited[i] = false;
		}
	}
}
