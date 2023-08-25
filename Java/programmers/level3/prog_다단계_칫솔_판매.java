package programmers.level3;

import java.util.HashMap;
import java.util.Map;

public class prog_다단계_칫솔_판매 {

	Map<String, Integer> results = new HashMap<>(); // 이익
	Map<String, String> parents = new HashMap<>(); // 추천인
	int[] answer;

	public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
		init(enroll, referral);

		for (int i = 0; i < seller.length; i++) {
			String name = seller[i];
			int money = amount[i] * 100;
			String parent = parents.get(name);
			int parentMoney = money / 10;
			addMoney(name, money - parentMoney);
			while (true) {
				if (parent.equals("-") || parentMoney < 1)
					break;
				name = parent;
				money = parentMoney;
				parent = parents.get(name);
				parentMoney = money / 10;
				addMoney(name, money - parentMoney);
			}
		}

		for (int i = 0; i < enroll.length; i++) {
			answer[i] = results.get(enroll[i]);
		}

		return answer;
	}

	void init(String[] enroll, String[] referral) {
		answer = new int[enroll.length];
		results.put("-", 0);
		for (String s : enroll) {
			results.put(s, 0);
		}
		for (int i = 0; i < referral.length; i++) {
			parents.put(enroll[i], referral[i]);
		}
	}

	void addMoney(String name, int money) {
		results.put(name, results.get(name) + money);
	}
}
