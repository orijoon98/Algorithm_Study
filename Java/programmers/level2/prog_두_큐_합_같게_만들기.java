package programmers.level2;

import java.util.LinkedList;
import java.util.Queue;

public class prog_두_큐_합_같게_만들기 {
	Queue<Integer> queueOne = new LinkedList<>();
	Queue<Integer> queueTwo = new LinkedList<>();

	public int solution(int[] queue1, int[] queue2) {
		int answer = 0;
		init(queue1, queue2);
		long sum1 = getSum(queue1);
		long sum2 = getSum(queue2);

		while (sum1 != sum2) {
			if (answer > (queue1.length + queue2.length) * 2) {
				return -1;
			}
			if (sum1 > sum2) {
				int tmp = queueOne.poll();
				queueTwo.add(tmp);
				sum1 -= tmp;
				sum2 += tmp;
			} else if (sum1 < sum2) {
				int tmp = queueTwo.poll();
				queueOne.add(tmp);
				sum1 += tmp;
				sum2 -= tmp;
			}
			answer++;
		}

		return answer;
	}

	void init(int[] queue1, int[] queue2) {
		for (int i = 0; i < queue1.length; i++) {
			queueOne.add(queue1[i]);
		}
		for (int i = 0; i < queue2.length; i++) {
			queueTwo.add(queue2[i]);
		}
	}

	long getSum(int[] array) {
		long sum = 0;
		for (int i = 0; i < array.length; i++) {
			sum += array[i];
		}
		return sum;
	}
}
