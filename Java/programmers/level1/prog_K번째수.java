package programmers.level1;

import java.util.Arrays;

public class prog_K번째수 {

    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int index = 0;

        for (int n = 0; n < commands.length; n++) {
            int i = commands[n][0];
            int j = commands[n][1];
            int k = commands[n][2];
            int[] slicedArray = slice(array, i, j);
            Arrays.sort(slicedArray);
            answer[index++] = slicedArray[k - 1];
        }

        return answer;
    }

    private int[] slice(int[] array, int i, int j) {
        int[] result = new int[j - i + 1];
        int index = 0;
        for (int n = 0; n < array.length; n++) {
            if (n >= i - 1 && n <= j - 1) {
                result[index++] = array[n];
            }
        }
        return result;
    }
}
