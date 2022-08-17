package level2;

import java.util.LinkedList;
import java.util.Queue;

public class prog_프린터 {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Integer> waiting = new LinkedList<>();
        Queue<Integer> tmp = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) {
            waiting.add(i);
        }
        while (true) {
            boolean flag = false; // 가장 앞의 대기목록을 인쇄해야 하는지
            int first = waiting.poll(); // 가장 앞의 대기목록
            tmp.clear();
            while (!waiting.isEmpty()) {
                if (priorities[waiting.peek()] <= priorities[first]) {
                    tmp.add(waiting.poll());
                } else {
                    flag = true; // 우선순위가 더 높은 문서가 존재
                    break;
                }
            }
            tmp.addAll(waiting);
            waiting.clear();
            waiting.addAll(tmp);
            if (!flag) {
                // 첫번째 문서를 인쇄하기 때문에 대기목록에 추가하지 않음
                answer++;
                if (location == first) break;
            } else {
                // 중요도에서 밀리므로 대기목록 마지막에 추가
                waiting.add(first);
            }
        }
        return answer;
    }
}
