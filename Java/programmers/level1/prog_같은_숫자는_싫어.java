package level1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class prog_같은_숫자는_싫어 {
    public int[] solution(int[] arr) {
        List<Integer> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.stream(arr).boxed().forEach(list::add);
        int tmp = list.get(0);
        ans.add(tmp);
        for (int i = 1; i < list.size(); i++) {
            if (tmp != list.get(i)) {
                tmp = list.get(i);
                ans.add(tmp);
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
