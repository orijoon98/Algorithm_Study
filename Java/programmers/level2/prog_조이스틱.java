package level2;

public class prog_조이스틱 {

    private int move = 100; // 커서 좌우 방향 최소 횟수

    public int solution(String name) {
        int answer = 0;
        char[] alphabets = name.toCharArray();
        boolean[] done = new boolean[alphabets.length]; // 변경 완료 상태값
        int doneCnt = 0;
        // 커서 위 아래 최소 횟수
        for (int i = 0; i < alphabets.length; i++) {
            if (alphabets[i] == 'A') {
                done[i] = true;
                doneCnt++;
            }
            answer += Math.min(alphabets[i] - 'A', 26 - (alphabets[i] - 'A'));
        }
        // 커서 좌우 방향 최소 횟수 찾기
        recursive(done, doneCnt, 0, 0);
        answer += move;
        return answer;
    }

    private void recursive(boolean[] done, int doneCnt, int cur, int move) {
        if (done.length == doneCnt) {
            this.move = Math.min(this.move, move);
            return;
        }
        for (int i = 0; i < done.length; i++) {
            if (!done[i]) {
                boolean[] newDone = done.clone();
                newDone[i] = true;
                recursive(newDone, doneCnt + 1, i, move + Math.min(Math.abs(i - cur), done.length - Math.abs(i - cur)));
            }
        }
    }
}
