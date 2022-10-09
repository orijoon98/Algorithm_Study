package level2;

public class prog_k진수에서_소수_개수_구하기 {
    public int solution(int n, int k) {
        int answer = 0;
        String converted = convert(n, k);
        String[] numbers = converted.split("0");
        for (String number : numbers) {
            if (!number.equals("") && isPrime(Long.parseLong(number))) answer++;
        }
        return answer;
    }

    private String convert(int n, int k) {
        StringBuilder result = new StringBuilder();
        while (true) {
            result.append(n % k);
            n = n / k;
            if (n == 0) break;
        }
        return result.reverse().toString();
    }

    private boolean isPrime(long n) {
        if (n < 2) return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
