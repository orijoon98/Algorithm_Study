package programmers.level2;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class prog_구명보트 {

    public int solution(int[] people, int limit) {
        int answer = 0;

        Deque<Integer> weight = new ArrayDeque<>();

        Arrays.sort(people);
        for (int i = 0; i < people.length; i++) {
            weight.addLast(people[i]);
        }

        while (!weight.isEmpty()) {
            int heavy = weight.pollLast();
            if (!weight.isEmpty()) {
                int light = weight.pollFirst();
                if (heavy + light <= limit) {
                    answer++;
                } else {
                    answer++;
                    weight.addFirst(light);
                }
            } else {
                answer++;
            }
        }

        return answer;
    }
}
