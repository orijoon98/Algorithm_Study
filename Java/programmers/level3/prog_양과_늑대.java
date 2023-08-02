package programmers.level3;

import java.util.ArrayList;
import java.util.List;

public class prog_양과_늑대 {

	private class Node {
		int index;
		boolean isSheep;
		List<Node> childs = new ArrayList<>();

		Node(int index, boolean isSheep) {
			this.index = index;
			this.isSheep = isSheep;
		}
	}

	List<Node> nodes = new ArrayList<>();
	int answer = 0;

	public int solution(int[] info, int[][] edges) {
		init(info, edges);
		dfs(nodes.get(0), 0, 0, List.of(nodes.get(0)));
		return answer;
	}

	private void init(int[] info, int[][] edges) {
		for (int i = 0; i < info.length; i++) {
			nodes.add(new Node(i, info[i] == 0));
		}
		for (int[] edge : edges) {
			Node parent = nodes.get(edge[0]);
			Node child = nodes.get(edge[1]);
			parent.childs.add(child);
		}
	}

	private void dfs(Node cur, int sheep, int wolf, List<Node> nextNodes) {
		if (cur.isSheep) {
			sheep++;
		} else {
			wolf++;
		}

		if (wolf >= sheep) {
			return;
		}
		answer = Math.max(answer, sheep);

		List<Node> next = new ArrayList<>(nextNodes);
		next.addAll(cur.childs);
		next.remove(cur);

		for (Node nextNode : next) {
			dfs(nextNode, sheep, wolf, next);
		}
	}
}
