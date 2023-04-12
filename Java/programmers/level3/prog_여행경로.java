package programmers.level3;

import java.util.ArrayList;
import java.util.Collections;

public class prog_여행경로 {

    boolean[] visited;
    ArrayList<String> allRoutes;

    public String[] solution(String[][] tickets) {
        String[] answer;
        int cnt = 0;
        visited = new boolean[tickets.length];
        allRoutes = new ArrayList<>();

        dfs("ICN", "ICN", tickets, cnt);

        Collections.sort(allRoutes);
        answer = allRoutes.get(0).split(" ");

        return answer;
    }

    public void dfs(String start, String route, String[][] tickets, int cnt) {
        if (cnt == tickets.length) {
            allRoutes.add(route);
            return;
        }

        for (int i = 0; i < tickets.length; i++) {
            if (start.equals(tickets[i][0]) && !visited[i]) {
                visited[i] = true;
                dfs(tickets[i][1], route + " " + tickets[i][1], tickets, cnt + 1);
                visited[i] = false;
            }
        }
    }
}
