/*
 * 	Printing N
 * 
 * 	https://www.acmicpc.net/problem/2741
 */

package BOJ;
import java.util.*;

public class BOJ_2741 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		for (int i = 1; i <= n; i++)
			System.out.println(i);
	}
}
