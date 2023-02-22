package level1;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class prog_개인정보_수집_유효기간 {

    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> answer = new ArrayList<>();

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy.MM.dd");
        LocalDate todayLocalDate = LocalDate.parse(today, formatter);

        Map<String, String> termsMap = new HashMap<>();
        Arrays.stream(terms).forEach(term -> {
            String[] splitTerm = term.split(" ");
            termsMap.put(splitTerm[0], splitTerm[1]);
        });

        for (int i = 0; i < privacies.length; i++) {
            String[] splitPrivacies = privacies[i].split(" ");
            String date = splitPrivacies[0];
            String term = splitPrivacies[1];
            LocalDate localDate = LocalDate.parse(date, formatter);
            LocalDate dueDate = localDate.plusMonths(Long.valueOf(termsMap.get(term))).minusDays(1);
            if (dueDate.getDayOfMonth() > 28) {
                dueDate = dueDate.withDayOfMonth(28);
            }
            if (todayLocalDate.isAfter(dueDate)) {
                answer.add(i + 1);
            }
        }

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
