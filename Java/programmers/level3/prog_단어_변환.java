package programmers.level3;

public class prog_단어_변환 {

    int answer = Integer.MAX_VALUE;

    public int solution(String begin, String target, String[] words) {
        boolean[] visited = new boolean[words.length];
        dfs(begin, target, words, visited, 0);
        return answer == Integer.MAX_VALUE ? 0 : answer;
    }

    private void dfs(String begin, String target, String[] words, boolean[] visited, int depth) {
        if (begin.equals(target)) {
            answer = Math.min(answer, depth);
        }
        for (int i = 0; i < words.length; i++) {
            if (!visited[i] && matchSingleAlphabet(begin, words[i])) {
                boolean[] copy = visited.clone();
                copy[i] = true;
                dfs(words[i], target, words, copy, depth + 1);
            }
        }
    }

    private boolean matchSingleAlphabet(String a, String b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                count++;
            }
        }
        return count == 1;
    }
}
