package programmers.level3;

public class prog_표현_가능한_이진트리 {

	boolean flag = true;

	public int[] solution(long[] numbers) {
		int[] answer = new int[numbers.length];

		for (int i = 0; i < numbers.length; i++) {
			String binary = Long.toBinaryString(numbers[i]);
			int treeLength = getTreeLength(binary.length());
			String converted = convert(binary, treeLength);
			if (representable(converted)) {
				answer[i] = 1;
			} else {
				answer[i] = 0;
			}
		}

		return answer;
	}

	// 포화 이진트리로 표현하기 위한 개수
	int getTreeLength(int length) {
		// 0~1 -> 1
		// 2~3 -> 3
		// 4~7 -> 7
		// 8~15 -> 15
		return (int)Math.pow(2, log2(length) + 1) - 1;
	}

	int log2(int x) {
		return (int)(Math.log(x) / Math.log(2));
	}

	// 포화 이진트리로 수정
	String convert(String binary, int length) {
		StringBuilder sb = new StringBuilder();
		int cnt = length - binary.length();
		while (cnt > 0) {
			sb.append("0");
			cnt--;
		}
		sb.append(binary);
		return sb.toString();
	}

	boolean representable(String binary) {
		char[] array = binary.toCharArray();
		int root = array.length / 2;
		int level = log2(array.length + 1);
		int[] childs = getChilds(root, level);
		check(array, root, childs, level);
		boolean result = flag;
		flag = true;
		return result;
	}

	int[] getChilds(int parent, int level) {
		if (level == 1) {
			return new int[0];
		}
		int diff = (int)Math.pow(2, level - 2);
		return new int[] {parent - diff, parent + diff};
	}

	void check(char[] array, int parent, int[] childs, int level) {
		if (childs.length == 0) {
			return;
		}
		if (array[parent] == '0') {
			if (array[childs[0]] == '1')
				flag = false;
			if (array[childs[1]] == '1')
				flag = false;
		}
		check(array, childs[0], getChilds(childs[0], level - 1), level - 1);
		check(array, childs[1], getChilds(childs[1], level - 1), level - 1);
	}
}
