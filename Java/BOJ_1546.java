/*
 *	Mean value
 *
 *	https://www.acmicpc.net/problem/1546
 */

import java.util.*;

public class BOJ_1546 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Double total = 0.0;
		Double max = 0.0;
		Double [] Arr = new Double[N];
		for (int i = 0; i < N; i++) {
			Arr[i] = sc.nextDouble();
			max = Math.max(max, Arr[i]);
		}
		sc.close();
		for (int j = 0; j < N; j++) {
			total += (Arr[j] / max) * 100;
		}
		System.out.println(String.format("%.2f", total / N));
	}
}
