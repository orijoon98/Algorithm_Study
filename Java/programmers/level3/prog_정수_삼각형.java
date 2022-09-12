package level3;

public class prog_정수_삼각형 {
    public int solution(int[][] triangle) {
        int answer = 0;

        int[][] sums = new int[triangle.length][];
        for (int i = 0; i < triangle.length; i++) {
            sums[i] = new int[triangle[i].length];
        }

        sums[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.length; i++) {
            for (int j = 0; j < triangle[i].length; j++) {
                int cur = triangle[i][j];
                int left = 0;
                int right = 0;
                if (checkIndex(i - 1, j - 1, triangle.length, triangle[i - 1].length)) {
                    left = sums[i - 1][j - 1];
                }
                if (checkIndex(i - 1, j, triangle.length, triangle[i - 1].length)) {
                    right = sums[i - 1][j];
                }
                sums[i][j] = Math.max(left + cur, right + cur);
                answer = Math.max(answer, sums[i][j]);
            }
        }

        return answer;
    }

    private boolean checkIndex(int i, int j, int iSize, int jSize) {
        return i >= 0 && i < iSize && j >= 0 && j < jSize;
    }
}
