package programmers.level3;

import java.util.Stack;

public class prog_표_편집 {

	private Stack<Node> stack = new Stack<>();
	int n;
	private int[] pre;
	private int[] next;
	private char[] answer;

	public String solution(int n, int k, String[] cmd) {
		this.n = n;
		answer = new char[n];
		pre = new int[n];
		next = new int[n];
		for (int i = 0; i < n; i++) {
			answer[i] = 'O';
			pre[i] = i - 1;
			next[i] = i + 1;
		}
		next[n - 1] = -1;
		int current = k;

		for (int i = 0; i < cmd.length; i++) {
			String[] command = cmd[i].split(" ");
			switch (command[0]) {
				case "U":
					current = cmdU(current, Integer.parseInt(command[1]));
					break;
				case "D":
					current = cmdD(current, Integer.parseInt(command[1]));
					break;
				case "C":
					current = cmdC(current);
					break;
				case "Z":
					current = cmdZ(current);
					break;
			}
		}

		return String.valueOf(answer);
	}

	private class Node {
		int pre;
		int cur;
		int next;

		Node(int pre, int cur, int next) {
			this.pre = pre;
			this.cur = cur;
			this.next = next;
		}
	}

	private int cmdU(int current, int count) {
		while (count > 0) {
			current = pre[current];
			count--;
		}
		return current;
	}

	private int cmdD(int current, int count) {
		while (count > 0) {
			current = next[current];
			count--;
		}
		return current;
	}

	private int cmdC(int current) {
		if (next[current] != -1) {
			pre[next[current]] = pre[current];
		}
		if (pre[current] != -1) {
			next[pre[current]] = next[current];
		}
		answer[current] = 'X';
		stack.push(new Node(pre[current], current, next[current]));
		if (next[current] == -1) {
			return pre[current];
		}
		return next[current];
	}

	private int cmdZ(int current) {
		Node node = stack.pop();
		if (node.pre != -1) {
			next[node.pre] = node.cur;
		}
		if (node.next != -1) {
			pre[node.next] = node.cur;
		}
		answer[node.cur] = 'O';
		return current;
	}
}
