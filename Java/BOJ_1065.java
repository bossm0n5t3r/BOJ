/*
 * 	Hansu
 * 
 * 	https://www.acmicpc.net/problem/1065
 */

package BOJ;
import java.util.*;

public class BOJ_1065 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		BOJ_1065 check = new BOJ_1065();
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (check.checkHansu(i)) count++;
		}
		System.out.println(count);
	}
	public boolean checkHansu(int n) {
		int length = (int)(Math.log10(n) + 1);
		if (length < 3) return true;
		else {
			int diff = n%10 - (n/10)%10;
			do {
				n /= 10;
				int temp = n%10 - (n/10)%10;
				if (temp != diff) return false;
			} while (n > 99);
			return true;
		}
	}
}
