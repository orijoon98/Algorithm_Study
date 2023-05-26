package baekjoon.gold4;

import java.io.*;

public class baek_LCS_2 {

    static char[] A, B;
    static int answer1 = 0;
    static String answer2 = "";

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        A = br.readLine().toCharArray();
        B = br.readLine().toCharArray();
    }

    static void solution() {
        int[][] lcs = new int[A.length + 1][B.length + 1];
        for (int i = 1; i <= A.length; i++) {
            for (int j = 1; j <= B.length; j++) {
                if (A[i - 1] == B[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = Math.max(lcs[i - 1][j], lcs[i][j - 1]);
                }
                answer1 = Math.max(answer1, lcs[i][j]);
            }
        }
        if (answer1 != 0) {
            char[] result = new char[answer1];
            int index = result.length - 1;
            int i = A.length;
            int j = B.length;
            while (index >= 0) {
                if (lcs[i][j] == lcs[i - 1][j]) {
                    i--;
                } else if (lcs[i][j] == lcs[i][j - 1]) {
                    j--;
                } else {
                    result[index] = A[i - 1];
                    index--;
                    i--;
                    j--;
                }
            }
            answer2 = String.valueOf(result);
        }
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer1));
        if (answer1 != 0) {
            bw.newLine();
            bw.write(answer2);
        }
        bw.flush();
    }
}
