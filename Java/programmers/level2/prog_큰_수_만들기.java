package level2;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.stream.Collectors;

public class prog_큰_수_만들기 {
    public String solution(String number, int k) {
        String answer = "";

        List<Integer> num = new ArrayList<>();
        for (int i = 0; i < number.length(); i++) {
            num.add(Character.getNumericValue(number.charAt(i)));
        }

        int cnt = 0;
        Stack<Integer> tmp = new Stack<>();
        for (Integer n : num) {
            while (cnt != k && !tmp.empty()) {
                if (tmp.peek() < n) {
                    tmp.pop();
                    cnt++;
                } else break;
            }
            tmp.add(n);
        }

        if (cnt < k) {
            while (cnt != k && !tmp.empty()) {
                tmp.pop();
                cnt++;
            }
        }

        answer = tmp.stream().map(Object::toString).collect(Collectors.joining(""));

        return answer;
    }
}
