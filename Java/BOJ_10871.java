/*
 * 	Less than X
 * 
 * 	https://www.acmicpc.net/problem/10871
 */

package BOJ;
import java.util.*;

public class BOJ_10871 {
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
