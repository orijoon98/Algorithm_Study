package baekjoon.gold3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class baek_아기_상어 {

	static class Pos {
		int x;
		int y;
		int distance;

		Pos(int x, int y, int distance) {
			this.x = x;
			this.y = y;
			this.distance = distance;
		}

		public int getX() {
			return x;
		}

		public int getY() {
			return y;
		}

		public int getDistance() {
			return distance;
		}
	}

	static int N;
	static int[][] board;
	static int distance[][];
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int answer = 0;
	static Pos babyStart; // 아기 상어 위치
	static int babySize = 2; // 아기 상어 크기
	static int babyEat = 0; // 아기 상어 물고기 먹은 수

	public static void main(String[] args) throws IOException {
		input();
		solution();
		output();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		init();
		for (int i = 0; i < N; i++) {
			String[] input = br.readLine().split(" ");
			for (int j = 0; j < input.length; j++) {
				board[i][j] = Integer.parseInt(input[j]);
				if (board[i][j] == 9) {
					babyStart = new Pos(i, j, 0);
					board[i][j] = 0;
				}
			}
		}
	}

	static void init() {
		board = new int[N][N];
		distance = new int[N][N];
		initDistance();
	}

	static void initDistance() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				distance[i][j] = -1;
			}
		}
	}

	static void solution() {
		Pos next;
		while ((next = bfs(babyStart.x, babyStart.y)) != null) {
			babyEat++;
			if (babySize == babyEat) {
				babySize++;
				babyEat = 0;
			}
			babyStart = next;
			board[next.x][next.y] = 0;
			answer += next.distance;
			initDistance();
		}
	}

	// 아기 상어 시작 위치에서 먹을 수 있는 가장 가까운 물고기 위치 반환
	static Pos bfs(int x, int y) {
		List<Pos> result = new ArrayList<>();
		Queue<Pos> queue = new LinkedList<>();
		queue.add(new Pos(x, y, 0));
		distance[x][y] = 0;
		while (!queue.isEmpty()) {
			Pos cur = queue.poll();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
					continue;
				}
				if (distance[nx][ny] >= 0) {
					continue;
				}
				if (board[nx][ny] > babySize) { // 크기가 더 큰 물고기가 있는 칸은 지나갈 수 없음
					continue;
				}
				distance[nx][ny] = distance[cur.x][cur.y] + 1;
				queue.add(new Pos(nx, ny, distance[nx][ny]));
				if (isFish(board[nx][ny]) && board[nx][ny] < babySize) { // 먹을 수 있는 물고기라면
					result.add(new Pos(nx, ny, distance[nx][ny]));
				}
			}
		}
		result.sort(Comparator.comparing(Pos::getDistance).thenComparing(Pos::getX).thenComparing(Pos::getY));
		if (result.isEmpty()) {
			return null;
		}
		return result.get(0);
	}

	static boolean isFish(int number) {
		return 1 <= number && number <= 6;
	}

	static void output() throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answer));
		bw.flush();
	}
}
