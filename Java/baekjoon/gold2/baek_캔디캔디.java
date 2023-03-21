package baekjoon.gold2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class baek_캔디캔디 {

    static int M, N;
    static long[] needs;
    static long sum = 0;
    static long result = 0;

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        needs = new long[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            needs[i] = Long.parseLong(st.nextToken());
            sum += needs[i];
        }
    }

    static void solution() {
        Arrays.sort(needs);
        long lack = sum - M;
        for (int i = 0; i < N; i++) {
            // 못 받는 개수를 남은 사람들이랑 최대한 똑같게 만들어야한다.
            long removeCount = Math.min(needs[i], lack / (N - i));
            lack -= removeCount;
            result += removeCount * removeCount;
        }
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(result % (long) Math.pow(2, 64)));
        bw.flush();
    }
}
