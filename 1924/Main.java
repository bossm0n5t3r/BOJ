import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int d = sc.nextInt();
		sc.close();
		String [] namesOfDays = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
		int [] daysOfMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (m == 1 && d == 1)
			System.out.println(namesOfDays[1]);
		else {
			int count = 0;
			for (int i = 1; i < m; i++)
				count += daysOfMonths[i-1];
			count += d;
			System.out.println(namesOfDays[count%7]);
		}	
	}
}
