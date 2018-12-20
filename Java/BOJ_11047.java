/*
 * 	Coin 0
 * 
 * 	https://www.acmicpc.net/problem/11047
 */

import java.io.*;

public class BOJ_11047 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] numbers = br.readLine().split(" ");
		int N = Integer.parseInt(numbers[0]);
		int K = Integer.parseInt(numbers[1]);
		int cnt = 0;
		int [] coins = new int [N];
		for (int i = 0; i < N; i++) {
			coins[i] = Integer.parseInt(br.readLine());
		}
		for (int i = N-1; i >= 0; i--) {
			cnt += K / coins[i];
			K %= coins[i];
		}
		System.out.println(cnt);
	}
}
