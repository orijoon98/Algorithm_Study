package programmers.level3;

public class prog_광고_삽입 {
	public String solution(String play_time, String adv_time, String[] logs) {
		int answerSecond = 0;
		long answerSum = 0;
		int playSecond = convertSeconds(play_time);
		int advSecond = convertSeconds(adv_time);
		int[] sum = new int[playSecond + 1]; // sum[i] = i 초에 겹치는 재생 구간 수

		for (int i = 0; i < logs.length; i++) {
			String[] tokens = logs[i].split("-");
			int start = convertSeconds(tokens[0]);
			int end = convertSeconds(tokens[1]);
			for (int j = start; j < end; j++) {
				sum[j]++;
			}
		}

		long total = 0; // 누적합
		for (int i = 0; i < advSecond; i++) {
			total += sum[i];
		}
		answerSum = total;

		for (int i = 0, j = advSecond; j < playSecond; i++, j++) {
			total = total - sum[i] + sum[j];
			if (total > answerSum) {
				answerSum = total;
				answerSecond = i + 1;
			}
		}

		return convertSeconds(answerSecond);
	}

	int convertSeconds(String time) {
		String[] tokens = time.split(":");
		int hour = Integer.parseInt(tokens[0]) * 60 * 60;
		int minute = Integer.parseInt(tokens[1]) * 60;
		int second = Integer.parseInt(tokens[2]);
		return hour + minute + second;
	}

	String convertSeconds(int seconds) {
		int hour = seconds / 3600;
		int minute = seconds % 3600 / 60;
		int second = seconds % 60;
		return String.format("%02d:%02d:%02d", hour, minute, second);
	}
}
