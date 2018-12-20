/*
 *	Print out each 10 alphabets
 * 
 * 	https://www.acmicpc.net/problem/11721
 */

import java.util.*;

public class BOJ_11721 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		String temp = sc.nextLine();
		sc.close();
		/*
		 * 	Code by "yeolpyeong"
		 * 
		 * 	https://github.com/yeolpyeong/boj/blob/master/boj11721.java
		 * 
		 * 	while (temp.length() > 10) {
		 * 		System.out.println(temp.substring(0,10));
		 * 		temp = temp.substring(10);
		 * 	}
		 * 	System.out.println(temp);
		 */
		int i = 0;
		int length = temp.length();
		while (i < length) {
			String str = "";
			if (i <= length - 10) {
				for (int j = i; j < i + 10; j++)
					str += temp.charAt(j);
				System.out.println(str);
			} else {
				for (int j = i; j < length; j++)
					str += temp.charAt(j);
				System.out.println(str);
			}
			i += 10;
		}
	}
}
