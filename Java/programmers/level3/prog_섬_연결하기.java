package level3;

import java.util.Arrays;
import java.util.Comparator;

public class prog_섬_연결하기 {
    int[] parents;

    public int solution(int n, int[][] costs) {
        int answer = 0;
        int selected = 0;
        // 간선 비용 낮은순으로 정렬
        Arrays.sort(costs, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });
        // 루트 노드 배열 초기화
        parents = new int[n];
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        for (int i = 0; i < costs.length; i++) {
            if (find(costs[i][0]) != find(costs[i][1])) {
                selected++;
                union(costs[i][0], costs[i][1]);
                answer += costs[i][2];
            }
            if (selected == n - 1) break;
        }
        return answer;
    }

    private void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x > y) parents[x] = y;
        else parents[y] = x;
    }

    private int find(int x) {
        if (parents[x] == x) return x;
        return find(parents[x]);
    }
}
