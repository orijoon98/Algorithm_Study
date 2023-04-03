package programmers.level3;

public class prog_등굣길 {

    public int solution(int m, int n, int[][] puddles) {
        boolean[][] unable = new boolean[m + 1][n + 1];
        for (int i = 0; i < puddles.length; i++) {
            unable[puddles[i][0]][puddles[i][1]] = true;
        }

        // dp[i][j] 는 (i, j) 칸에 도달할 수 있는 최단 경로
        int[][] dp = new int[m + 1][n + 1];

        // 집이 있는 (1, 1)에 도달할 수 있는 경로는 1로 시작
        dp[1][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                if (unable[i][j]) {
                    continue;
                }

                // (i, j) 칸에 도달할 수 있는 경로 = (i-1, j) 왼쪽 칸에 도달할 수 있는 경로 + (i, j - 1) 위 칸에 도달할 수 있는 경로
                // 모듈로 연산 적용
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }

        return dp[m][n];
    }
}
