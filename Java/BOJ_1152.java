/*
 *  Counting the number of words
 *
 *  https://www.acmicpc.net/problem/1152
 */

import java.util.*;

public class BOJ_1152 {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        String temp = sc.nextLine();
        if (temp != null && temp.trim().length() > 0) {
            String [] Arr = temp.trim().split(" ");
            System.out.println(Arr.length);
        } else
            System.out.println(0);
        sc.close();
    }
}

/*  Code by "yeolpyeong"
 *
 *  https://github.com/yeolpyeong/boj/blob/master/boj1152.java
 *
 *  import java.io.BufferedReader;
 *  import java.io.IOException;
 *  import java.io.InputStreamReader;
 *  import java.util.StringTokenizer;
 *
 *  public class Main {
 *      public static void main(String [] args) throws IOException {
 *          BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 *          StringTokenizer st = new StringTokenizer(br.readLine(), " ");
 *          System.out.print(st.countTokens());
 */
