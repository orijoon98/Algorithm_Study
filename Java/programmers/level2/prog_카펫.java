package level2;

public class prog_카펫 {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        for (int i = 1; i <= yellow; i++) {
            if (yellow % i == 0) {
                int width = Math.max(i, yellow / i) + 2;
                int height = Math.min(i, yellow / i) + 2;
                if (width * 2 + height * 2 - 4 == brown) {
                    answer[0] = width;
                    answer[1] = height;
                    break;
                }
            }
        }
        return answer;
    }
}
