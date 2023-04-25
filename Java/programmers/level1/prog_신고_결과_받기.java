package programmers.level1;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class prog_신고_결과_받기 {

    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        Map<String, Set<String>> reportMap = new HashMap<>();
        Map<String, Integer> reportCountMap = new HashMap<>();

        for (int i = 0; i < report.length; i++) {
            String[] user = report[i].split(" ");
            Set<String> reportSet = reportMap.getOrDefault(user[0], new HashSet<>());
            if (!reportSet.contains(user[1])) {
                reportCountMap.put(user[1], reportCountMap.getOrDefault(user[1], 0) + 1);
            }
            reportSet.add(user[1]);
            reportMap.put(user[0], reportSet);
        }

        for (int i = 0; i < id_list.length; i++) {
            Set<String> reportSet = reportMap.getOrDefault(id_list[i], new HashSet<>());
            int cnt = 0;
            for (String user : reportSet) {
                if (reportCountMap.getOrDefault(user, 0) >= k) {
                    cnt++;
                }
            }
            answer[i] = cnt;
        }

        return answer;
    }
}
