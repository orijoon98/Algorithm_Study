package level2;

class 타겟_넘버 {

    int answer = 0;

    public int solution(int[] numbers, int target) {
        DFS(0, numbers, target, 0);
        return answer;
    }

    private void DFS(int cur, int[] numbers, int target, int result) {
        if (cur == numbers.length) {
            if (result == target) answer++;
            return;
        }
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                DFS(cur + 1, numbers, target, result + numbers[cur]);
            } else {
                DFS(cur + 1, numbers, target, result + -1 * numbers[cur]);
            }
        }
    }
}

