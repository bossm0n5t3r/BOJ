/*
 * 	Add cycle
 * 
 * 	https://www.acmicpc.net/problem/1110
 */

package BOJ;
import java.util.*;

public class BOJ_1110 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int start = n;
		int count = 0;
		do {
			n = (n%10)*10 + (n/10 + n%10)%10;
			count++;
		} while (n != start);
		System.out.println(count);				
	}
}
