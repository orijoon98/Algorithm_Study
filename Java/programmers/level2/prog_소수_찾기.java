package level2;

import java.util.HashSet;
import java.util.Set;

public class prog_소수_찾기 {

    private int answer = 0;
    private Set<Integer> set = new HashSet<>();

    public int solution(String numbers) {
        char[] chars = numbers.toCharArray();
        char[] output = new char[chars.length];
        boolean[] visited = new boolean[chars.length];
        for (int i = 1; i <= chars.length; i++) {
            permutation(chars, output, visited, 0, chars.length, i);
        }
        for (Integer number : set) {
            if (isPrimeNumber(number)) answer++;
        }
        return answer;
    }

    private void permutation(char[] arr, char[] output, boolean[] visited, int depth, int n, int r) {
        if (depth == r) {
            StringBuilder number = new StringBuilder();
            for (int i = 0; i < r; i++) {
                number.append(output[i]);
            }
            set.add(Integer.parseInt(number.toString()));
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                output[depth] = arr[i];
                permutation(arr, output, visited, depth + 1, n, r);
                visited[i] = false;
            }
        }
    }

    private boolean isPrimeNumber(int number) {
        if (number < 2) return false;
        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) return false;
        }
        return true;
    }
}
