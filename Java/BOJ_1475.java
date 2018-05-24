/*
 *  Room No.
 *
 *  https://www.acmicpc.net/problem/1475
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_1475 {
    public static void main (String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] temp = br.readLine().replace("9", "6").split("");
        int [] save = new int [9];
        for (String i : temp) {
            save[Integer.parseInt(i)]++;
        }
        int max = 0;
        save[6] = save[6] / 2 + save[6] % 2;
        for (int i = 0; i < 9; i++) {
            if (save[i] > max) {
                max = save[i];
            }
        }
        System.out.println(max);
    }
}
