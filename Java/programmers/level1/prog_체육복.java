package level1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class prog_체육복 {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        List<Integer> lost_ = Arrays.stream(lost).boxed().collect(Collectors.toList());
        List<Integer> reserve_ = Arrays.stream(reserve).boxed().collect(Collectors.toList());
        List<Integer> reserved = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            // 여벌 체육복이 있는 학생이 체육복을 도난당한 경우
            if (lost_.contains(i) && reserve_.contains(i)) {
                reserved.add(i);
            }
        }

        // 체육복을 도난당했는데 여벌 체육복이 있는 경우 고려할 필요 없음
        lost_ = lost_.stream().filter(i -> !reserved.contains(i)).collect(Collectors.toList());

        for (int i = 1; i <= n; i++) {
            // 체육복을 도난당한 경우
            if (lost_.contains(i)) {
                // 앞번호의 학생에게 체육복을 빌릴 수 있는 경우
                if (reserve_.contains(i - 1) && !reserved.contains(i - 1)) {
                    answer++;
                    reserved.add(i - 1);
                }
                // 뒷번호의 학생에게 체육복을 빌릴 수 있는 경우
                else if (reserve_.contains(i + 1) && !reserved.contains(i + 1)) {
                    answer++;
                    reserved.add(i + 1);
                }
            }
            // 체육복을 가져왔거나 도난 당했지만 여벌 체육복이 있는 경우
            else {
                answer++;
            }
        }
        return answer;
    }
}
