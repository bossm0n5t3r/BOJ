/*
 * 	Adding 1s, 2s, and 3s
 * 
 * 	https://www.acmicpc.net/problem/9095
 */

import java.io.*;

public class BOJ_9095 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			int n = Integer.parseInt(br.readLine());
			System.out.println(new BOJ_9095().compute(n));
		}
	}
	
	public int compute(int n) {
		if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else if (n == 3)
			return 4;
		else
			return compute(n-1) + compute(n-2) + compute(n-3);
	}
}
