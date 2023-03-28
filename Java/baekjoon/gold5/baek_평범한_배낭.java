package baekjoon.gold5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baek_평범한_배낭 {

    static int N, K;
    static int[][] WV = new int[101][2];
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int W = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            WV[i][0] = W;
            WV[i][1] = V;
        }
    }

    static void solution() {
        answer = knapsack();
    }

    static int knapsack() {
        int[][] value = new int[N + 1][K + 1]; // value[i][w]란 i개의 물건을 담고 배낭의 무게 한도가 w일때 최적의 이익
        // 물건이 0개거나 무게 한도가 0이면 이익은 0
        for (int i = 1; i <= N; i++) {
            for (int w = 1; w <= K; w++) {
                if (WV[i][0] > w) { // 현재 물건을 담을 수 없는 경우
                    // i번째 물건이 배낭의 한도보다 무거우면 넣을 수 없으므로 i번째 보석을 뺀 i-1개의 물건을 넣었을 때의 최적의 이익
                    value[i][w] = value[i - 1][w];
                } else {
                    // i번째 물건을 넣기 위해 i번째 물건의 무게만큼 무게를 비웠을 때의 최적값에 i번째 물건의 가치를 더한 값과 i번째 물건을 넣지 않았을 때의 가치 중 더 큰 값
                    value[i][w] = Math.max(WV[i][1] + value[i - 1][w - WV[i][0]], value[i - 1][w]);
                }
            }
        }
        return value[N][K];
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
