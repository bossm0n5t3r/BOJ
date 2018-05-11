/*
 *  Find Alphabet
 *
 *  https://www.acmicpc.net/problem/10809
 */

import java.util.*;

public class BOJ_10809 {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        String temp = sc.nextLine();
        sc.close();
        for (int i = 97; i < 123; i++)
            System.out.print(temp.indexOf((char)i)+" ");
        }
}
