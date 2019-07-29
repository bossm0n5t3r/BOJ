import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int upperbound = 2000;
		int [] save = new int[5001];
		for (int i = 0; i < n + 1; i++)
			save[i] = upperbound;
		save[3] = 1;
		save[5] = 1;
		for (int j = 6; j < n + 1; j++)
			save[j] = Math.min(save[j - 3], save[j - 5]) + 1;
		System.out.println(save[n] < upperbound ? save[n] : -1);
	}
}
