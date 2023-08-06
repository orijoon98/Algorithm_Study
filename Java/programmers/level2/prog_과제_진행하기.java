package programmers.level2;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Stack;

public class prog_과제_진행하기 {

	private class Plan {
		String name;
		int start; // 분으로 계산
		int playTime;

		Plan(String name, String start, String playTime) {
			String[] timeInfo = start.split(":");
			this.name = name;
			this.start = 60 * Integer.parseInt(timeInfo[0]) + Integer.parseInt(timeInfo[1]);
			this.playTime = Integer.parseInt(playTime);
		}

		void minusPlayTime(int time) {
			this.playTime -= time;
		}
	}

	public String[] solution(String[][] plans) {
		List<String> answer = new ArrayList<>();

		// Plan 리스트 초기화
		List<Plan> planList = new ArrayList<>();
		for (String[] plan : plans) {
			planList.add(new Plan(plan[0], plan[1], plan[2]));
		}

		// 과제 시작 시간 순 정렬
		planList.sort(Comparator.comparing(plan -> plan.start));

		// 첫번째 과제 시작
		Plan runningPlan = planList.remove(0);
		int time = runningPlan.start;
		Stack<Plan> pausedPlans = new Stack<>(); // 잠시 멈춘 과제

		while (!planList.isEmpty()) {
			int finishTime = time + runningPlan.playTime; // 진행중인 과제가 끝날 시간
			Plan nextPlan = planList.get(0);
			// 진행중인 과제를 멈춰야하는 경우
			if (finishTime > nextPlan.start) {
				// 진행중이던 프로젝트 시간 계산 후 멈추기
				int passedTime = nextPlan.start - time;
				runningPlan.minusPlayTime(passedTime);
				pausedPlans.push(runningPlan);
				// 멈춘 후 다음 과제 시작
				runningPlan = planList.remove(0);
				time = nextPlan.start;
			}
			// 진행중인 과제를 끝내고 다음 과제를 시작할 수 있는 경우
			else {
				answer.add(runningPlan.name);
				// 멈춘 과제가 있는 경우
				if (!pausedPlans.isEmpty()) {
					runningPlan = pausedPlans.pop();
					time = finishTime;
				} else {
					runningPlan = planList.remove(0);
					time = nextPlan.start;
				}
			}
		}
		answer.add(runningPlan.name);
		while (!pausedPlans.isEmpty()) {
			answer.add(pausedPlans.pop().name);
		}

		return answer.toArray(new String[answer.size()]);
	}
}
