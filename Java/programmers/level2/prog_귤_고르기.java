package programmers.level2;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class prog_귤_고르기 {

    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < tangerine.length; i++) {
            map.put(tangerine[i], map.getOrDefault(tangerine[i], 0) + 1);
        }
        int[] counts = new int[map.keySet().size()];
        int index = 0;
        for (Integer key : map.keySet()) {
            counts[index++] = map.get(key);
        }
        Arrays.sort(counts);
        for (int i = counts.length - 1; i >= 0; i--) {
            k -= counts[i];
            answer++;
            if (k <= 0) {
                break;
            }
        }
        return answer;
    }
}
