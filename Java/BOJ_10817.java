/*
 * 	The second largest number
 * 
 * 	https://www.acmicpc.net/problem/10817
 */

import java.util.*;

public class BOJ_10817 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int [] Arr = new int[3];
		for (int i = 0; i < 3; i++) {
			Arr[i] = sc.nextInt();
		}
		sc.close();
		Arrays.sort(Arr);
		System.out.println(Arr[1]);
	}
}