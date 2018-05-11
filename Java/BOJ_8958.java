/*
 *  OX Quiz
 *
 *  https://www.acmicpc.net/problem/8958
 */

import java.util.*;

public class BOJ_8958 {
    public static void main(String [] args) {
        BOJ_8958 main = new BOJ_8958();
        Scanner sc = new Scanner(System.in);
        int length = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < length; i++) {
            String temp = sc.nextLine();
            System.out.println(main.scoreCase(temp));
        }
        sc.close();
    }
    public int scoreCase(String temp) {
        int length = temp.length();
        int [] Arr = new int[length];
        int point = 0;
        int score = 0;
        for (int i = 0; i < length; i++) {
            if (temp.charAt(i) == 'O')
                Arr[point]++;
            else
                point++;
        }
        for (int i : Arr)
            score += i * (i + 1) / 2;
        return score;
    }
}
