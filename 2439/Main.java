import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int count = 1;
		while (count <= n) {
			int i = count;
			int j = n - i;
			String stars = "";
			for (int k = 0; k < j; k++)
				stars += " ";
			for (int l = 0; l < i; l++)
				stars += "*";
			System.out.println(stars);
			count += 1;
		}
	}
}
