package level2;

import java.util.LinkedList;
import java.util.Queue;

public class prog_게임_맵_최단거리 {
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        int[][] dist = new int[n][m];
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        Queue<int[]> queue = new LinkedList<>();
        dist[0][0] = 1;
        queue.add(new int[]{0, 0});
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int curX = cur[0];
                int curY = cur[1];
                int nx = curX + dx[i];
                int ny = curY + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 범위 벗어나는 경우
                if (maps[nx][ny] == 0) continue; // 벽인 경우
                if (dist[nx][ny] >= 1) continue; // 이미 방문한 경우
                dist[nx][ny] = dist[curX][curY] + 1;
                queue.add(new int[]{nx, ny});
                if (nx == n - 1 && ny == m - 1) return dist[nx][ny];
            }
        }
        return -1;
    }
}
