package programmers.level3;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class prog_가장_먼_노드 {

    int n;
    int[] distance;
    Map<Integer, List<Integer>> edge = new HashMap<>();

    public int solution(int n, int[][] edge) {
        this.n = n;
        this.distance = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            distance[i] = -1;
        }
        for (int i = 0; i < edge.length; i++) {
            List<Integer> a = this.edge.getOrDefault(edge[i][0], new ArrayList<>());
            List<Integer> b = this.edge.getOrDefault(edge[i][1], new ArrayList<>());
            a.add(edge[i][1]);
            b.add(edge[i][0]);
            this.edge.put(edge[i][0], a);
            this.edge.put(edge[i][1], b);
        }

        bfs();

        return getAnswer(this.distance);
    }

    private void bfs() {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        distance[1] = 0;

        while (!queue.isEmpty()) {
            int current = queue.poll();
            List<Integer> edge = this.edge.get(current);
            for (int next : edge) {
                if (distance[next] < 0) {
                    queue.add(next);
                    distance[next] = distance[current] + 1;
                }
            }
        }
    }

    private int getAnswer(int[] distance) {
        int max = 0;
        for (int i = 0; i < distance.length; i++) {
            max = Math.max(max, distance[i]);
        }

        int count = 0;
        for (int i = 0; i < distance.length; i++) {
            if (distance[i] == max) {
                count++;
            }
        }

        return count;
    }
}
