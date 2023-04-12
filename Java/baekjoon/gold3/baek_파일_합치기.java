package baekjoon.gold3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baek_파일_합치기 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int T, K;
    static int[] files;
    static int[] sum; // sum[i] 는 i 번째 파일까지의 비용 합
    static int[][] dp; // dp[i][j] 는 i 부터 j 까지 합쳤을 때 최소비용
    static int answer;

    public static void main(String[] args) throws IOException {
        inputT();
        for (int t = 0; t < T; t++) {
            input();
            answer = solution(1, K);
            output();
        }
    }

    static void inputT() throws IOException {
        T = Integer.parseInt(br.readLine());
    }

    static void input() throws IOException {
        K = Integer.parseInt(br.readLine());
        init();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= K; i++) {
            files[i] = Integer.parseInt(st.nextToken());
            sum[i] = sum[i - 1] + files[i];
        }
    }

    static void init() {
        files = new int[K + 1];
        sum = new int[K + 1];
        dp = new int[K + 1][K + 1];
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
    }

    static int solution(int start, int end) {
        if (dp[start][end] != Integer.MAX_VALUE) {
            return dp[start][end];
        }
        if (start == end) {
            return dp[start][end] = 0;
        }
        for (int i = start; i < end; i++) {
            dp[start][end] = Math.min(dp[start][end], solution(start, i) + solution(i + 1, end));
        }
        return dp[start][end] += sum[end] - sum[start - 1];
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer).concat("\n"));
        bw.flush();
    }
}
