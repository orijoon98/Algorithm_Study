package programmers.level3;

public class prog_입국심사 {

    int n;
    int[] times;

    public long solution(int n, int[] times) {
        this.n = n;
        this.times = times;
        return binarySearch(0, Long.MAX_VALUE);
    }

    private long binarySearch(long left, long right) {
        long middle = (left + right) / 2;
        while (left <= right) {
            if (calculate(middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
            middle = (left + right) / 2;
        }
        return left;
    }

    private boolean calculate(long time) {
        long sum = 0;
        for (int i = 0; i < times.length; i++) {
            sum += time / times[i];
            if (sum >= n) {
                return true;
            }
        }
        return false;
    }
}
