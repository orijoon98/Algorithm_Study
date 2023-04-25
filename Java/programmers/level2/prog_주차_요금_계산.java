package programmers.level2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class prog_주차_요금_계산 {

    public int[] solution(int[] fees, String[] records) {
        int defaultTime = fees[0];
        int defaultPrice = fees[1];
        int timeUnit = fees[2];
        int priceUnit = fees[3];

        Set<String> numbers = new HashSet<>(); // 차량 번호 set
        Map<String, String> inTime = new HashMap<>(); // 차량이 들어온 시간 map
        Map<String, Integer> parkingTimes = new HashMap<>(); // 차량별 누적 주차 시간 map
        Map<String, Integer> prices = new HashMap<>(); // 내야할 요금 map

        for (int i = 0; i < records.length; i++) {
            String[] record = records[i].split(" ");
            String time = record[0];
            String number = record[1];
            String status = record[2];

            numbers.add(number); // 차량 번호 저장

            if (status.equals("IN")) { // 차량이 들어온 경우
                inTime.put(number, time);
            } else { // 차량이 나간 경우
                String in = inTime.get(number);
                inTime.remove(number); // 나가지 않은 차량 파악하기 위해 나간 차량은 제거
                int parkingMinute = getParkingMinute(in, time);
                parkingTimes.put(number, parkingTimes.getOrDefault(number, 0) + parkingMinute);
            }
        }

        // 출차 기록이 없는 차량들은 23시 59분에 나간걸로 처리
        for (String number : inTime.keySet()) {
            String in = inTime.get(number);
            int parkingMinute = getParkingMinute(in, "23:59");
            parkingTimes.put(number, parkingTimes.getOrDefault(number, 0) + parkingMinute);
        }

        // 누적 주차 시간으로 각 차량 별 요금 계산
        for (String number : parkingTimes.keySet()) {
            int parkingMinute = parkingTimes.get(number);
            int price = defaultPrice; // 기본 시간 이하인 경우
            if (parkingMinute > defaultTime) { // 기본 시간 초과인 경우
                price += ceil(parkingMinute - defaultTime, timeUnit) * priceUnit;
            }
            prices.put(number, prices.getOrDefault(number, 0) + price);
        }

        int[] answer = new int[numbers.size()];
        List<String> numbersList = new ArrayList<>(numbers);
        Collections.sort(numbersList);
        int index = 0;
        for (String number : numbersList) {
            answer[index++] = prices.get(number);
        }

        return answer;
    }

    private int getParkingMinute(String inTime, String outTime) {
        String[] in = inTime.split(":");
        String[] out = outTime.split(":");
        int totalOutMinute = 60 * Integer.parseInt(out[0]) + Integer.parseInt(out[1]);
        int totalInMinute = 60 * Integer.parseInt(in[0]) + Integer.parseInt(in[1]);
        return totalOutMinute - totalInMinute;
    }

    private int ceil(int dividend, int divisor) {
        if (dividend % divisor == 0) {
            return dividend / divisor;
        }
        return dividend / divisor + 1;
    }
}
