package programmers.level2;

public class prog_이모티콘_할인행사 {

    int[][] users;
    int[] emoticons;
    int[] sales;
    int[] answer = new int[2];

    public int[] solution(int[][] users, int[] emoticons) {
        this.users = users;
        this.emoticons = emoticons;
        this.sales = new int[emoticons.length];

        recursive(0);

        return answer;
    }

    private void recursive(int index) {
        if (index == emoticons.length) {
            int serviceCount = 0;
            int totalBuyPrice = 0;
            for (int i = 0; i < users.length; i++) {
                int buyPrice = 0;
                for (int j = 0; j < emoticons.length; j++) {
                    int salePrice = 0;
                    if (sales[j] >= users[i][0]) {
                        salePrice = emoticons[j] / 100 * (100 - sales[j]);
                    }
                    buyPrice += salePrice;
                }
                if (buyPrice >= users[i][1]) {
                    serviceCount++;
                } else {
                    totalBuyPrice += buyPrice;
                }
            }
            answer = compareAndSetAnswer(serviceCount, totalBuyPrice);
            return;
        }
        for (int sale = 10; sale <= 40; sale += 10) {
            sales[index] = sale;
            recursive(index + 1);
        }
    }

    private int[] compareAndSetAnswer(int serviceCount, int totalBuyPrice) {
        if (serviceCount > answer[0]) {
            answer[0] = serviceCount;
            answer[1] = totalBuyPrice;
            return answer;
        }
        if (serviceCount == answer[0] && totalBuyPrice > answer[1]) {
            answer[1] = totalBuyPrice;
            return answer;
        }
        return answer;
    }
}
