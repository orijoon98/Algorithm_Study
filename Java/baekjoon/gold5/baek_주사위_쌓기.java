package baekjoon.gold5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baek_주사위_쌓기 {

    static int n;
    static int[][] dices = new int[10000][6];
    static int[] opposite = {5, 3, 4, 1, 2, 0}; // 각 면의 반대면
    static boolean[] sides = new boolean[6]; // 위 아랫면은 false, 옆 면은 true
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        input();
        solution();
        output();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < 6; j++) {
                dices[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void solution() {
        if (n == 1) {
            answer = 6;
            return;
        }
        for (int start = 1; start <= 6; start++) { // start 는 1번 주사위의 윗면
            int sum = 0;
            int up = getNextUpAndSetSides(dices[0], start);
            sum += getMax(dices[0], sides);
            for (int i = 1; i < n; i++) { // 2번 주사위부터 n번 주사위까지
                up = getNextUpAndSetSides(dices[i], up);
                sum += getMax(dices[i], sides);
            }
            answer = Math.max(answer, sum);
        }
    }

    static int getNextUpAndSetSides(int[] dice, int up) { // 윗면에 일치하는 아랫면을 찾아 윗면을 리턴하고 사이드 면을 설정
        for (int i = 0; i < 6; i++) {
            sides[i] = true;
        }
        for (int i = 0; i < 6; i++) {
            if (dice[i] == up) {
                sides[i] = false;
                sides[opposite[i]] = false; // 전 주사위의 윗면과 일치하는 아랫면과 윗면 false 처리
                return dice[opposite[i]]; // 반댓면인 윗면의 숫자를 리턴
            }
        }
        return -1; // 나올 경우 없음
    }

    static int getMax(int[] dice, boolean[] side) {
        int max = 0;
        for (int i = 0; i < 6; i++) {
            if (side[i]) {
                max = Math.max(max, dice[i]);
            }
        }
        return max;
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
