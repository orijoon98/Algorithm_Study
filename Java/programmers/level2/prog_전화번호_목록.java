package level2;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class prog_전화번호_목록 {
    public boolean solution(String[] phone_book) {
        List<String> phoneBook = Arrays.stream(phone_book).collect(Collectors.toList());
        Set<Integer> phoneLengths = Arrays.stream(phone_book).map(String::length).collect(Collectors.toSet());
        for (Integer n : phoneLengths) { // 문자열들의 길이를 먼저 파악해서 비교할 길이들을 정함
            HashMap<String, Integer> map = new HashMap<>();
            for (String s : phoneBook) {
                if (s.length() < n) continue;
                if (map.containsKey(s.substring(0, n))) { // 접두어가 같은 문자열이 존재한다는 의미
                    if (phoneBook.contains(s.substring(0, n))) return false;
                }
                map.put(s.substring(0, n), 1); // 길이만큼 잘라서 map 에 저장
            }
        }
        return true;
    }
}
