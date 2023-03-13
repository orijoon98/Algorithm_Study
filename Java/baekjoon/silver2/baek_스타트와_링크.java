package baekjoon.silver2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baek_스타트와_링크 {

    static int N;
    static int[][] S = new int[20][20];
    static boolean[] team = new boolean[20];
    static int answer = Integer.MAX_VALUE;

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
                S[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void solution() {
        combination(team, 0, N / 2);
    }

    static void combination(boolean[] visited, int start, int r) {
        if (r == 0) {
            answer = Math.min(answer, calculateDifference(visited));
        } else {
            for (int i = start; i < N; i++) {
                visited[i] = true;
                combination(visited, i + 1, r - 1);
                visited[i] = false;
            }
        }
    }

    static int calculateDifference(boolean[] team) {
        int aTeamScore = 0;
        int bTeamScore = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                if (team[i] == team[j]) {
                    if (team[i]) {
                        aTeamScore += S[i][j];
                    } else {
                        bTeamScore += S[i][j];
                    }
                }
            }
        }
        return Math.abs(aTeamScore - bTeamScore);
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
