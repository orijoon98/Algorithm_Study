package programmers.level2;

public class prog_피로도 {

    int answer = 0;
    int k;
    int[][] dungeons;

    public int solution(int k, int[][] dungeons) {
        this.k = k;
        this.dungeons = dungeons;
        int[] order = new int[dungeons.length];
        boolean[] visited = new boolean[dungeons.length];

        permutation(order, visited, dungeons.length, 0);

        return answer;
    }

    private void permutation(int[] order, boolean[] visited, int n, int depth) { // 0부터 n-1까지의 순열
        if (depth == n) {
            bruteforce(order, k);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                order[depth] = i;
                permutation(order, visited, n, depth + 1);
                visited[i] = false;
            }
        }
    }

    private void bruteforce(int[] order, int reset) {
        int count = 0;
        for (int i = 0; i < order.length; i++) {
            int need = dungeons[order[i]][0];
            int spend = dungeons[order[i]][1];
            if (k >= need) {
                k -= spend;
                count++;
            }
        }
        answer = Math.max(answer, count);
        k = reset;
    }
}
