package programmers.level1;

import java.util.HashMap;
import java.util.Map;

public class prog_추억_점수 {
	public int[] solution(String[] name, int[] yearning, String[][] photo) {
		int[] answer = new int[photo.length];

		Map<String, Integer> scoreMap = new HashMap<>();
		for (int i = 0; i < name.length; i++) {
			scoreMap.put(name[i], yearning[i]);
		}

		for (int i = 0; i < photo.length; i++) {
			String[] photoInfo = photo[i];
			int score = 0;
			for (int j = 0; j < photoInfo.length; j++) {
				answer[i] += scoreMap.getOrDefault(photoInfo[j], 0);
			}
		}

		return answer;
	}
}
