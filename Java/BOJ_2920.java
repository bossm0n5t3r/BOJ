/*
 *  NOTE
 *
 *  https://www.acmicpc.net/problem/2920
 */

import java.util.*;

public class BOJ_2920 {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        int [] Arr = new int[8];
        for (int i = 0; i < 8; i++)
            Arr[i] = sc.nextInt();
        sc.close();
        if (Arr[0] != 1 && Arr[0] != 8) {
            System.out.println("mixed");
            return;
        }
        for (int i = 0; i < 7; i++) {
            if (Math.abs(Arr[i] - Arr[i+1]) != 1) {
                System.out.println("mixed");
                return;
            }
        }
        if (Arr[0] == 1) {
            System.out.println("ascending");
            return;
        }
        else {
            System.out.println("descending");
            return;
        }
    }
}

