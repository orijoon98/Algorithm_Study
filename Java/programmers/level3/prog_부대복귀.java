package programmers.level3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class prog_부대복귀 {
	int N;
	int[] distance;
	List<List<Integer>> roadList = new ArrayList<>();

	public int[] solution(int n, int[][] roads, int[] sources, int destination) {
		int[] answer = new int[sources.length];
		N = n;

		// road 세팅
		for (int i = 0; i <= n; i++)
			roadList.add(new ArrayList<>());
		for (int[] road : roads) {
			int a = road[0];
			int b = road[1];
			roadList.get(a).add(b);
			roadList.get(b).add(a);
		}

		for (int i = 0; i < sources.length; i++) {
			answer[i] = bfs(sources[i], destination);
		}

		return answer;
	}

	int bfs(int start, int destination) {
		if (start == destination)
			return 0;
		Queue<Integer> queue = new LinkedList<>();
		distance = new int[N + 1];
		Arrays.fill(distance, -1);
		distance[start] = 0;
		queue.add(start);

		while (!queue.isEmpty()) {
			int cur = queue.poll();
			for (int next : roadList.get(cur)) {
				if (distance[next] >= 0)
					continue;
				distance[next] = distance[cur] + 1;
				queue.add(next);
				if (next == destination) {
					return distance[next];
				}
			}
		}

		return -1;
	}
}
