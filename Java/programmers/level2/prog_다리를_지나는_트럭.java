package level2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class prog_다리를_지나는_트럭 {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        List<Integer> waiting = Arrays.stream(truck_weights).boxed().collect(Collectors.toList());
        List<Integer> passed = new ArrayList<>();
        List<Integer> passing = new ArrayList<>();
        List<Integer> passingTime = new ArrayList<>();
        int trucks = waiting.size();

        while (passed.size() != trucks) {
            answer++; // 1초 증가

            // 다리를 건너고 있는 트럭이 있는 경우 머문 시간이 1초인 트럭들은 다리를 지난 트럭으로 변경
            while (!passing.isEmpty()) {
                if (passingTime.get(0) == bridge_length) {
                    passed.add(passing.get(0)); // 트럭이 다리를 건넜다
                    passing.remove(0);
                    passingTime.remove(0);
                } else break;
            }

            int passingWeight = 0; // 현재 다리를 건너는 트럭의 총 무게
            for (Integer n : passing) passingWeight += n;

            // 트럭이 한 대 더 올라갈 수 있고 올라가도 다리가 무게를 견딜 수 있는 경우
            if (!waiting.isEmpty() && passing.size() < bridge_length && waiting.get(0) + passingWeight <= weight) {
                passing.add(waiting.remove(0)); // 트럭이 다리를 건넌다
                passingTime.add(0); // 올라간 트럭이 다리에 머문 시간
            }

            // 다리를 건너고 있는 모든 트럭이 머문 시간 1초 증가
            passingTime = passingTime.stream().map(integer -> integer + 1).collect(Collectors.toList());
        }

        return answer;
    }
}
