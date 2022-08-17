package level2;

import java.util.Arrays;

public class prog_H_Index {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        int left = 0;
        int right = 1000;
        while (left <= right) {
            int middle = (left + right) / 2;
            int above = 0;
            for (int i = 0; i < citations.length; i++) {
                if (citations[i] >= middle) above++;
            }
            if (above >= middle) {
                answer = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return answer;
    }
}
