package level3;

public class prog_네트워크 {

    private boolean[] visit;

    public int solution(int n, int[][] computers) {
        int answer = 0;
        visit = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                answer++;
                DFS(i, n, computers);
            }
        }

        return answer;
    }

    private void DFS(int start, int n, int[][] computers) {
        visit[start] = true;
        for (int j = 0; j < n; j++) {
            if (start == j) continue;
            if (computers[start][j] == 1 && !visit[j]) {
                DFS(j, n, computers);
            }
        }
    }
}
