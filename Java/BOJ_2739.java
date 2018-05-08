/*
 *	Multiplication table
 *
 *	https://www.acmicpc.net/problem/2739
 */

package BOJ;
import java.util.*;

public class BOJ_2739 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		for (int i = 1; i <= 9; i++)
			System.out.println(n+" * "+i+" = "+n*i);
	}
}
