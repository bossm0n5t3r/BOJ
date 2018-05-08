/*
 * 	Printing stars - 2
 * 
 * 	https://www.acmicpc.net/problem/2439
 */

package BOJ;
import java.util.*;

public class BOJ_2439 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		/*
		 * 	Code by "yeolpyeong"
		 * 
		 * 	https://github.com/yeolpyeong/boj/blob/master/boj2439.java
		 * 	
		 * 	for (int i = 1; i <= n; i++) {
		 * 		for (int j = 1; j <= n; j++) {
		 * 			System.out.print( j <= n - i ? " " : "*");		<< nice approach
		 * 		}
		 * 		System.out.println();
		 * 	}
		 * 
		 */
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