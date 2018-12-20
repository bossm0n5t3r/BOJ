/*
 *	Arithmetic operations
 *
 *	https://www.acmicpc.net/problem/10869
 */

import java.util.*;

public class BOJ_10869 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		System.out.print((a+b)+"\n"+(a-b)+"\n"+(a*b)+"\n"+(a/b)+"\n"+(a%b));
		sc.close();
	}
}
