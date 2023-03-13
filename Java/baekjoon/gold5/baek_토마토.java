package baekjoon.gold5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class baek_토마토 {

    static int M, N;
    static int board[][] = new int[1000][1000];
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static Queue<Pos> queue = new LinkedList<>();
    static int answer = -1;

    static class Pos {

        int x;
        int y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


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
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 1) {
                    queue.add(new Pos(i, j));
                }
            }
        }
    }

    static void solution() {
        bfs();
        getAnswer();
    }

    static void bfs() {
        while (!queue.isEmpty()) {
            Pos cur = queue.poll();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                if (board[nx][ny] == -1) {
                    continue;
                }
                if (board[nx][ny] > 0) {
                    continue;
                }
                board[nx][ny] = board[cur.x][cur.y] + 1;
                queue.add(new Pos(nx, ny));
            }
        }
    }

    static void getAnswer() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) {
                    answer = -1;
                    return;
                }
                answer = Math.max(answer, board[i][j]);
            }
        }
        answer -= 1;
    }

    static void output() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
