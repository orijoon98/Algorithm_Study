package level2;

public class prog_택배_배달과_수거하기 {

    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;

        int delivery = 0;
        int pickup = 0;

        for (int i = n - 1; i >= 0; i--) {

            int cnt = 0;

            delivery -= deliveries[i];
            pickup -= pickups[i];

            while (delivery < 0 || pickup < 0) {
                delivery += cap;
                pickup += cap;
                cnt += 1;
            }

            answer += (long) (i + 1) * 2 * cnt;
        }

        return answer;
    }
}
