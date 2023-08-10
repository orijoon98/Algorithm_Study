package programmers.level2;

import java.util.Arrays;
import java.util.PriorityQueue;

public class prog_호텔_대실 {
	public int solution(String[][] book_time) {
		int answer = 0;

		Arrays.sort(book_time, (o1, o2) -> {
			if (o1[0].equals(o2[0])) {
				return o1[1].compareTo(o2[1]);
			}
			return o1[0].compareTo(o2[0]);
		});

		// 종료 시간 기준 우선순위 큐
		PriorityQueue<Integer> queue = new PriorityQueue<>();

		for (int i = 0; i < book_time.length; i++) {
			int start = convertToMinutes(book_time[i][0]);
			int end = convertToMinutes(book_time[i][1]) + 10;
			while (!queue.isEmpty()) {
				if (queue.peek() <= start) {
					queue.poll();
				} else {
					break;
				}
			}
			queue.add(end);
			answer = Math.max(answer, queue.size());
		}

		return answer;
	}

	int convertToMinutes(String time) {
		String[] infos = time.split(":");
		return 60 * Integer.parseInt(infos[0]) + Integer.parseInt(infos[1]);
	}
}
