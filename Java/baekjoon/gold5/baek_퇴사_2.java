package baekjoon.gold5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baek_퇴사_2 {

    static int N;
    static int[] T;
    static int[] P;
    // dp[i] 는 i 일에 최대 수익
    static int[] dp;
    static int answer;

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        init();
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            T[i] = Integer.parseInt(st.nextToken());
            P[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void init() {
        T = new int[N + 1];
        P = new int[N + 1];
        dp = new int[N + 1];
    }

    static void solution() {
        for (int i = 1; i <= N; i++) {
            int finish = i + T[i] - 1; // 상담이 완료되는 날
            if (finish <= N) {
                dp[finish] = Math.max(dp[finish], answer + P[i]);
            }
            answer = Math.max(answer, dp[i]); // 현재 날까지의 최대 수익
        }
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
