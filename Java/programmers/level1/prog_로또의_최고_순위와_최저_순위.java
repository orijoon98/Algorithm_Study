package programmers.level1;

import java.util.ArrayList;
import java.util.List;

public class prog_로또의_최고_순위와_최저_순위 {

    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];

        List<Integer> winNumbers = new ArrayList<>();

        for (int i = 0; i < win_nums.length; i++) {
            winNumbers.add(win_nums[i]);
        }

        int maxMatch = 0;
        int minMatch = 0;
        for (int i = 0; i < lottos.length; i++) {
            if (winNumbers.contains(lottos[i])) {
                maxMatch++;
                minMatch++;
            }
            if (lottos[i] == 0) {
                maxMatch++;
            }
        }

        answer[0] = getRank(maxMatch);
        answer[1] = getRank(minMatch);

        return answer;
    }

    private int getRank(int match) {
        if (match == 6) {
            return 1;
        }
        if (match == 5) {
            return 2;
        }
        if (match == 4) {
            return 3;
        }
        if (match == 3) {
            return 4;
        }
        if (match == 2) {
            return 5;
        }
        return 6;
    }
}
