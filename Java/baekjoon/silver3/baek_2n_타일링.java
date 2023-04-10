package baekjoon.silver3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

// 2×n 타일링
public class baek_2n_타일링 {

    static int n;
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
    }

    static void solution() {
        int[] fibo = new int[1001];
        fibo[1] = 1;
        fibo[2] = 2;
        for (int i = 3; i <= n; i++) {
            // 모듈로 연산
            fibo[i] = (fibo[i - 1] % 10007) + (fibo[i - 2] % 10007);
        }
        answer = fibo[n] % 10007;
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
