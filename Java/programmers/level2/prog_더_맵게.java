package level2;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

class 더_맵게 {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        Queue<Integer> priorityQueue = new PriorityQueue<>();
        Arrays.stream(scoville)
                .forEach(priorityQueue::add);
        while (true) {
            int a = priorityQueue.peek(); // 가장 맵지 않은 음식의 스코빌 지수
            if (a >= K) break; // 가장 맵지 않은 음식의 스코빌 지수가 K 이상이면 종료
            priorityQueue.poll();
            if (priorityQueue.isEmpty()) {
                answer = -1;
                break;
            }
            int b = priorityQueue.peek(); // 두 번째로 맵지 않은 음식의 스코빌 지수
            priorityQueue.poll();
            priorityQueue.add(a + 2 * b); // 섞는다
            answer++;
        }
        return answer;
    }
}
