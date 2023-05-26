package baekjoon.gold3;

import java.io.*;

public class baek_LCS_3 {

    static char[] A, B, C;
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        A = br.readLine().toCharArray();
        B = br.readLine().toCharArray();
        C = br.readLine().toCharArray();
    }

    static void solution() {
        int[][][] lcs = new int[A.length + 1][B.length + 1][C.length + 1];
        for (int i = 1; i <= A.length; i++) {
            for (int j = 1; j <= B.length; j++) {
                for (int k = 1; k <= C.length; k++) {
                    if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1]) {
                        lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
                    } else {
                        lcs[i][j][k] = Math.max(lcs[i - 1][j][k], Math.max(lcs[i][j - 1][k], lcs[i][j][k - 1]));
                    }
                    answer = Math.max(answer, lcs[i][j][k]);
                }
            }
        }
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
