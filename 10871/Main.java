import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		while (N-- > 0) {
			int next = sc.nextInt();
			if (next < X)
				System.out.print(next + " ");
		}
		sc.close();
	}
}
