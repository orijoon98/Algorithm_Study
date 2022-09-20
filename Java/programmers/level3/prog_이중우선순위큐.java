package level3;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class prog_이중우선순위큐 {

    private final Queue<Integer> pqAsc = new PriorityQueue<>();
    private final Queue<Integer> pqDesc = new PriorityQueue<>(Comparator.reverseOrder());

    public int[] solution(String[] operations) {
        int[] answer = {0, 0};
        Arrays.stream(operations).forEach(this::operate);
        if (pqAsc.isEmpty() || pqDesc.isEmpty()) return answer;
        answer[0] = pqDesc.peek();
        answer[1] = pqAsc.peek();
        return answer;
    }

    private void operate(String operation) {
        switch (operation) {
            case "D 1": {
                if (!pqAsc.isEmpty() && !pqDesc.isEmpty()) // 최댓값 삭제
                    pqAsc.remove(pqDesc.poll());
                break;
            }
            case "D -1": {
                if (!pqAsc.isEmpty() && !pqDesc.isEmpty()) // 최솟값 삭제
                    pqDesc.remove(pqAsc.poll());
                break;
            }
            default: {
                int number = Integer.parseInt(operation.substring(2));
                pqAsc.add(number);
                pqDesc.add(number);
            }
        }
    }
}
