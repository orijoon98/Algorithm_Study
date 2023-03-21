package baekjoon.silver2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baek_종이의_개수 {

    static int N;
    static int[][] paper = new int[2200][2200]; // 3의 7제곱 = 2187
    static int[] answer = new int[3];

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void solution() {
        cut(0, 0, N);
    }

    static boolean check(int x, int y, int n) {
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (paper[x][y] != paper[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    static void cut(int x, int y, int n) {
        if (check(x, y, n)) {
            answer[paper[x][y] + 1]++;
            return;
        }
        int m = n / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cut(x + i * m, y + j * m, m);
            }
        }
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer[0]));
        bw.write("\n");
        bw.write(String.valueOf(answer[1]));
        bw.write("\n");
        bw.write(String.valueOf(answer[2]));
        bw.flush();
    }
}
