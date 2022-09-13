package level1;

import java.util.HashMap;
import java.util.Map;

public class prog_완주하지_못한_선수 {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> map = new HashMap<>();
        for (String name : participant) map.put(name, map.getOrDefault(name, 0) + 1);
        for (String name : completion) map.put(name, map.get(name) - 1);
        for (String name : participant) {
            if (map.get(name) == 1) {
                answer = name;
                break;
            }
        }
        return answer;
    }
}
