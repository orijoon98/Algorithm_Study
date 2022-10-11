package level3;

import java.util.*;

public class prog_베스트앨범 {
    public int[] solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();
        Map<String, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            if (map.get(genres[i]) == null) {
                List<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(genres[i], list);
            } else {
                List<Integer> list = map.get(genres[i]);
                list.add(i);
                map.put(genres[i], list);
            }
        }
        List<List<Integer>> genresPlaysList = new ArrayList<>();
        for (String genre : map.keySet()) {
            genresPlaysList.add(map.get(genre));
        }
        // 속한 노래가 많이 재생된 장르순 정렬
        Collections.sort(genresPlaysList, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> o1, List<Integer> o2) {
                int o1Sum = o1.stream().map(i -> plays[i]).mapToInt(Integer::intValue).sum();
                int o2Sum = o2.stream().map(i -> plays[i]).mapToInt(Integer::intValue).sum();
                return o2Sum - o1Sum;
            }
        });
        for (List<Integer> playsList : genresPlaysList) {
            // 재생된 노래 많은순, 고유 번호가 낮은순 정렬
            playsList.sort(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    if (plays[o2] > plays[o1]) {
                        return 1;
                    } else if (plays[o2] < plays[o1]) {
                        return -1;
                    } else {
                        return o1 - o2;
                    }
                }
            });
            // 장르당 최대 두 개씩 베스트 앨범에 추가
            for (int i = 0; i < 2; i++) {
                if (playsList.size() > i) {
                    answer.add(playsList.get(i));
                }
            }
        }
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
