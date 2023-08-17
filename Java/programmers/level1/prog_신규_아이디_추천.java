package programmers.level1;

public class prog_신규_아이디_추천 {
	public String solution(String new_id) {
		new_id = convertFirst(new_id);
		new_id = convertSecond(new_id);
		new_id = convertThird(new_id);
		new_id = convertForth(new_id);
		new_id = convertFifth(new_id);
		new_id = convertSixth(new_id);
		new_id = convertSeventh(new_id);
		return new_id;
	}

	String convertFirst(String input) {
		return input.toLowerCase();
	}

	String convertSecond(String input) {
		return input.replaceAll("[^a-z0-9_.\\-]", "");
	}

	String convertThird(String input) {
		return input.replaceAll("\\.\\.+", ".");
	}

	String convertForth(String input) {
		input = input.replaceAll("^\\.", "");
		input = input.replaceAll("\\.$", "");
		return input;
	}

	String convertFifth(String input) {
		if (input.equals("")) {
			return "a";
		}
		return input;
	}

	String convertSixth(String input) {
		if (input.length() >= 16) {
			input = input.substring(0, 15);
			input = input.replaceAll("\\.$", "");
		}
		return input;
	}

	String convertSeventh(String input) {
		if (input.length() <= 2) {
			while (input.length() < 3) {
				input = input.concat(String.valueOf(input.charAt(input.length() - 1)));
			}
		}
		return input;
	}
}
