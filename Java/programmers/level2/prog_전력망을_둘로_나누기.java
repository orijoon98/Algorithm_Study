package programmers.level2;

public class prog_전력망을_둘로_나누기 {

    int n;
    int[][] wires;
    boolean[][] edges = new boolean[101][101];
    boolean[] visited = new boolean[101];
    int connected = 0;
    int[] count = new int[101];
    int answer = Integer.MAX_VALUE;

    public int solution(int n, int[][] wires) {
        this.n = n;
        this.wires = wires;

        initEdges();

        for (int i = 0; i < wires.length; i++) {
            // 전선 하나의 연결을 끊음
            edges[wires[i][0]][wires[i][1]] = false;
            edges[wires[i][1]][wires[i][0]] = false;

            visited = new boolean[101];

            // 연결된 송전탑 개수 구하기
            for (int j = 1; j <= n; j++) {
                connected = 0;
                dfs(j);
                count[j] = connected;
            }

            answer = Math.min(answer, getDifference(count));

            // 전선 다시 연결
            edges[wires[i][0]][wires[i][1]] = true;
            edges[wires[i][1]][wires[i][0]] = true;
        }

        return answer;
    }

    private void initEdges() {
        for (int i = 0; i < wires.length; i++) {
            edges[wires[i][0]][wires[i][1]] = true;
            edges[wires[i][1]][wires[i][0]] = true;
        }
    }

    private void dfs(int start) {
        if (!visited[start]) {
            visited[start] = true;
            connected++;
        }
        for (int i = 1; i <= n; i++) {
            if (edges[start][i] && !visited[i]) {
                dfs(i);
            }
        }
    }

    private int getDifference(int[] count) {
        int min = Integer.MAX_VALUE;
        int max = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] != 0) {
                min = Math.min(min, count[i]);
                max = Math.max(max, count[i]);
            }
        }
        return max - min;
    }
}
