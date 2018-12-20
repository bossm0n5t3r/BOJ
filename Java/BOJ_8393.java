/*
 * 	Sum
 * 
 * 	https://www.acmicpc.net/problem/8393
 */

import java.util.*;

public class BOJ_8393 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += i;
		System.out.println(sum);
	}
}
