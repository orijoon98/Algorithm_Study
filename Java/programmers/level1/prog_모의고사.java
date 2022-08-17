package level1;

import java.util.ArrayList;
import java.util.List;

public class prog_모의고사 {
    public int[] solution(int[] answers) {
        int[] one = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
        int[] two = {2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5};
        int[] three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int one_cnt = 0;
        int two_cnt = 0;
        int three_cnt = 0;
        for (int i = 0; i < answers.length; i++) {
            if (one[i % one.length] == answers[i]) one_cnt++;
            if (two[i % two.length] == answers[i]) two_cnt++;
            if (three[i % three.length] == answers[i]) three_cnt++;
        }
        int max = Math.max(one_cnt, Math.max(two_cnt, three_cnt));
        List<Integer> answer_ = new ArrayList<>();
        if (max == one_cnt) answer_.add(1);
        if (max == two_cnt) answer_.add(2);
        if (max == three_cnt) answer_.add(3);
        int[] answer = new int[answer_.size()];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = answer_.get(i);
        }
        return answer;
    }
}
