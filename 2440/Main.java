import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				System.out.print(j <= n - i ? "*" : "");
			}
			System.out.println();
		}
	}
}
