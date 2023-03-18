package programmers.level2;

public class prog_괄호_변환 {

    public String solution(String input) {
        if (correct(input)) {
            return input;
        }
        return algorithm(input);
    }

    private String algorithm(String input) {
        // 알고리즘 1번
        if (input.equals("")) {
            return "";
        }

        // 알고리즘 2번
        String[] divided = divide(input);
        String u = divided[0];
        String v = divided[1];

        // 알고리즘 3번
        if (correct(u)) {
            // 알고리즘 3-1번
            return u.concat(algorithm(v));
        }

        // 알고리즘 4번
        else {
            // 알고리즘 4-1, 4-2, 4-3, 4-4, 4-5번
            return "(".concat(algorithm(v)).concat(")").concat(convert(u));
        }
    }

    private String[] divide(String input) {
        String[] result = new String[2];
        int left = 0;
        int right = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '(') {
                left++;
            }
            if (input.charAt(i) == ')') {
                right++;
            }
            sb.append(input.charAt(i));
            if (left == right) {
                result[0] = sb.toString();
                result[1] = input.substring(i + 1);
                break;
            }
        }
        return result;
    }

    private boolean correct(String input) {
        int check = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '(') {
                check++;
            } else {
                check--;
                if (check < 0) {
                    return false;
                }
            }
        }
        return true;
    }

    private String convert(String input) {
        StringBuilder result = new StringBuilder();
        for (int i = 1; i < input.length() - 1; i++) {
            if (input.charAt(i) == '(') {
                result.append(")");
            }
            if (input.charAt(i) == ')') {
                result.append("(");
            }
        }
        return result.toString();
    }
}
