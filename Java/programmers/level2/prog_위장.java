package level2;

import java.util.HashMap;

public class prog_위장 {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> hm = new HashMap<>();
        for (int i = 0; i < clothes.length; i++) {
            hm.put(clothes[i][1], hm.getOrDefault(clothes[i][1], 0) + 1);
        }
        for (String key : hm.keySet()) {
            answer *= (hm.get(key) + 1);
        }
        answer -= 1;
        return answer;
    }
// 테스트 1번만 시간초과난 풀이
//    private int answer = 0;
//
//    public int solution(String[][] clothes) {
//        HashMap<String, Set<String>> map = new HashMap<>();
//        for (int i = 0; i < clothes.length; i++) {
//            if (map.containsKey(clothes[i][1])) {
//                Set<String> set = map.get(clothes[i][1]);
//                set.add(clothes[i][0]);
//                map.put(clothes[i][1], set);
//            } else {
//                Set<String> set = new HashSet<>();
//                set.add(clothes[i][0]);
//                map.put(clothes[i][1], set);
//            }
//        }
//
//        List<Integer> cnt = new ArrayList<>();
//        for (String key : map.keySet()) {
//            cnt.add(map.get(key).size());
//        }
//
//        int n = cnt.size();
//        int[] array = new int[n];
//        for (int i = 0; i < n; i++) {
//            array[i] = i;
//        }
//        boolean[] visit = new boolean[n];
//        for (int i = 1; i <= n; i++) {
//            combination(array, visit, 0, n, i, cnt);
//        }
//
//        return answer;
//    }
//
//    private void combination(int[] array, boolean[] visit, int start, int n, int r, List<Integer> cnt) {
//        if (r == 0) {
//            List<Integer> result = Arrays.stream(array).filter(i -> visit[i]).boxed().collect(Collectors.toList());
//            int tmp = 1;
//            for (Integer integer : result) {
//                tmp *= cnt.get(integer);
//            }
//            answer += tmp;
//            return;
//        }
//        for (int i = start; i < n; i++) {
//            visit[i] = true;
//            combination(array, visit, i + 1, n, r - 1, cnt);
//            visit[i] = false;
//        }
//    }
}
