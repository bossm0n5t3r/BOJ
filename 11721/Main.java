import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		String temp = sc.nextLine();
		sc.close();
		while (temp.length() > 10) {
			System.out.println(temp.substring(0, 10));
			temp = temp.substring(10);
		}
		System.out.println(temp);
	}
}
