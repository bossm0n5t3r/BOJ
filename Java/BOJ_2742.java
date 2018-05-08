/*
 * 	Printing N reverse
 * 
 * 	https://www.acmicpc.net/problem/2742
 */

package BOJ;
import java.util.*;

public class BOJ_2742 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		for (int i = n; i >= 1; i--)
			System.out.println(i);
	}
}