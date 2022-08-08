package level2;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class prog_기능_개발 {
    public int[] solution(int[] progresses, int[] speeds) {

        // 각 progress의 작업이 끝나기까지 남은 일수 구하기
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < progresses.length; i++) {
            queue.add((int) Math.ceil((100.0 - progresses[i]) / speeds[i]));
        }

        List<Integer> list = new ArrayList<>();
        while (!queue.isEmpty()) {
            int tmp = queue.poll(); // 가장 앞에 남아있는 기능이 배포되는 날
            int cnt = 1;
            while (!queue.isEmpty()) {
                if (queue.peek() <= tmp) { // 이후의 기능들이 더 일찍 혹은 같이 배포된다면 함께 배포
                    queue.remove();
                    cnt++;
                } else {
                    break;
                }
            }
            list.add(cnt);
        }

        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }

        return answer;
    }
}
