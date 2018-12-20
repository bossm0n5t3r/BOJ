/*
 * 	Printing stars - 1
 * 
 * 	https://www.acmicpc.net/problem/2438
 */

import java.util.*;

public class BOJ_2438 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		String stars = "";
		for (int i = 1; i <= n; i++) {
			System.out.println(stars += "*");
		}
	}
}