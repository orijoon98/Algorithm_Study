package programmers.level3;

import java.util.Arrays;

public class prog_단속카메라 {

    public int solution(int[][] routes) {
        int answer = 0;

        // 차량이 1대라면 필요한 카메라는 1개
        if (routes.length == 1) {
            return answer = 1;
        }

        // 진입 지점 기준 오름차순 정렬
        Arrays.sort(routes, (o1, o2) -> {
            return o1[0] - o2[0];
        });

        // 진입 지점이 같은 경로는 진출 지점 기준 오름차순 정렬
        Arrays.sort(routes, (o1, o2) -> {
            if (o1[0] == o2[0]) {
                return o1[1] - o2[1];
            }
            return 0;
        });

        // 이동 경로 겹치는 부분의 왼쪽 끝과 오른쪽 끝
        int left = routes[0][0];
        int right = routes[0][1];
        answer = 1;

        for (int i = 1; i < routes.length; i++) {
            int start = routes[i][0];
            int end = routes[i][1];
            // 겹치는 부분이 있다면 카메라의 개수를 늘리지 않고 겹치는 부분 갱신
            if (start <= right) {
                if (left < start) {
                    left = start;
                }
                if (right > end) {
                    right = end;
                }
            }
            // 겹치는 부분이 없다면 카메라의 개수를 늘리고 겹치는 부분 새롭게 설정
            else {
                answer++;
                left = start;
                right = end;
            }
        }

        return answer;
    }
}
