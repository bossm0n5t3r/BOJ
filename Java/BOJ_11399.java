/*
 * 	ATM
 * 
 * 	https://www.acmicpc.net/problem/11399
 */

package dynamicProgramming;

import java.io.*;
import java.util.Arrays;

public class BOJ_11399 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int sum = 0;
		int [] data = new int [N];
		String [] inputData = br.readLine().split(" ");
		for (int idx = 0; idx < N; idx++) {
			data[idx] = Integer.parseInt(inputData[idx]);
		}
		Arrays.sort(data);
		for (int i : data) {
			sum += i * (N--);
		}
		System.out.println(sum);
	}
}
