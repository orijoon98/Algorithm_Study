package programmers.level2;

public class prog_문자열_압축 {

    public int solution(String s) {
        int answer = s.length();

        // 자르는 단위 1 부터 문자열의 길이 / 2 까지
        for (int i = 1; i <= s.length() / 2; i++) {
            StringBuilder compressed = new StringBuilder();
            int cnt = 1;
            for (int start = i; start < s.length(); start += i) {
                String current = s.substring(start - i, start);
                if (start + i <= s.length()) {
                    String next = s.substring(start, start + i);
                    if (next.equals(current)) {
                        cnt++;
                        // 예외 케이스
                        if (start + i == s.length()) {
                            if (cnt == 1) {
                                compressed.append(current);
                            } else {
                                compressed.append(cnt).append(current);
                                cnt = 1;
                            }
                        }
                    }
                    // 이전 패턴과 일치하지 않을 경우
                    else {
                        // cnt 가 1 이상인 경우에만 압축 문자열에 포함
                        if (cnt == 1) {
                            compressed.append(current);
                        } else {
                            compressed.append(cnt).append(current);
                            cnt = 1;
                        }
                        // 예외 케이스
                        if (start + i == s.length()) {
                            compressed.append(next);
                        }
                    }
                }
                // 자르는 단위의 길이가 안돼서 비교 불가능한 경우
                else {
                    if (cnt == 1) {
                        compressed.append(current);
                    } else {
                        compressed.append(cnt).append(current);
                        cnt = 1;
                    }
                    compressed.append(s.substring(start));
                }
            }

            answer = Math.min(answer, compressed.length());
        }

        return answer;
    }
}
