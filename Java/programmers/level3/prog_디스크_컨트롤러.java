package level3;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class prog_디스크_컨트롤러 {
    public int solution(int[][] jobs) {
        int cur = 0; // 현재 시간
        int time = 0; // 작업 총 소요 시간
        List<List<Integer>> waiting = new ArrayList<>();
        for (int[] job : jobs) {
            List<Integer> list = new ArrayList<>();
            list.add(job[0]);
            list.add(job[1]);
            waiting.add(list);
        }
        waiting.sort((Comparator.comparingInt(o -> o.get(0)))); // 작업 요청 시간순 정렬
        List<Integer> process = new ArrayList<>(); // 진행중인 작업
        PriorityQueue<List<Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(o -> o.get(1))); // 소요 시간에 대한 힙 (소요 시간 작은 작업 우선)
        while (true) {
            if (!process.isEmpty()) { // 현재 진행중인 작업이 있을 경우
                process.set(1, process.get(1) - 1); // 작업 소요 시간 경과
                if (process.get(1) == 0) { // 작업이 끝난 경우
                    time += cur - process.get(0); // 작업 총 소요 시간 += (현재 시간 - 작업 요청 시간)
                    process.clear();
                }
                if (waiting.isEmpty() && minHeap.isEmpty() && process.isEmpty()) break; // 작업 모두 종료시 종료
            }
            while (!waiting.isEmpty() && waiting.get(0).get(0) <= cur) { // 현재 시간이나 전에 요청된 작업이 있을 경우
                minHeap.add(waiting.get(0)); // waiting -> minHeap 으로 이동
                waiting.remove(0);
            }
            if (process.isEmpty()) { // 현재 진행중인 작업이 없을 경우
                if (!minHeap.isEmpty()) { // 소요 시간이 가장 적은 작업 시작
                    process.add(minHeap.peek().get(0));
                    process.add(minHeap.poll().get(1)); // process에 요청 시간, 소요 시간 추가
                }
            }
            cur++; // 현재 시간 증가
        }
        return time / jobs.length;
    }
}
