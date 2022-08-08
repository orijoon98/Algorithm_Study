package level1;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class prog_폰켓몬 {
    public int solution(int[] nums) {
        int N = nums.length;
        Set<Integer> set = new HashSet<>();
        Arrays.stream(nums)
                .forEach(set::add);
        return Math.min(N / 2, set.size());
    }
}
