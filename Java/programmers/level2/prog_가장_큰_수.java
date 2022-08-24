package level2;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class prog_가장_큰_수 {
    public String solution(int[] numbers) {
        String answer = "";
        List<String> nums = Arrays.stream(numbers).mapToObj(Integer::toString).collect(Collectors.toList());
        nums.sort((a, b) -> (b + a).compareTo(a + b));
        for (String num : nums) answer += num;
        if (answer.charAt(0) == '0') return "0";
        return answer;
    }
}
