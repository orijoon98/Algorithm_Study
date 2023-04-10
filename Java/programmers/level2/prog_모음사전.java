package programmers.level2;

public class prog_모음사전 {

    int answer = 0;
    int cnt = 0;
    String[] order = {"A", "E", "I", "O", "U"};

    public int solution(String word) {
        dfs("", word);
        return answer;
    }

    void dfs(String word, String target) {
        if (word.equals(target)) {
            answer = cnt;
            return;
        }
        if (word.length() == 5) {
            return;
        }
        for (int i = 0; i < 5; i++) {
            cnt++;
            dfs(word.concat(order[i]), target);
        }
    }
}
