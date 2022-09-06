package level1;

import java.util.Arrays;

public class prog_최소직사각형 {
    public int solution(int[][] sizes) {
        int w = 0, h = 0;
        for (int[] size : sizes) {
            Arrays.sort(size);
            w = Math.max(w, size[0]);
            h = Math.max(h, size[1]);
        }
        return w * h;
    }
}
