/*
 * 	Printing stars - 4
 * 
 * 	https://www.acmicpc.net/problem/2441
 */

import java.util.*;

public class BOJ_2441 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(i <= j ? "*" : " ");
			}
			System.out.println();
		}
	}
}
