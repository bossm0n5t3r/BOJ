/*
 * 	Above average
 * 
 * 	https://www.acmicpc.net/problem/4344
 */

import java.util.*;

public class BOJ_4344 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int numOfCases = sc.nextInt();
		while (numOfCases-- > 0) {
			int N = sc.nextInt();
			int [] Arr = new int[N];
			int total = 0;
			int count = 0;
			for (int i = 0; i < N; i++) {
				Arr[i] = sc.nextInt();
				total += Arr[i];
			}
			int average = total / N;
			for (int j = 0; j < N; j++) {
				if (Arr[j] > average)
					count += 1;
			}
			System.out.println(String.format("%.3f", (double) count / N * 100) + "%");
		}
		sc.close();
	}
}
