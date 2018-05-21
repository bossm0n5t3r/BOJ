/*
 *  Fractional number
 *
 *  https://www.acmicpc.net/problem/1193
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_1193 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int X = Integer.parseInt(br.readLine());
        int count = 1;
        while (count < X) {
            X -= count;
            count++;
        }
        if (count % 2 == 1)
            System.out.println((count - X + 1) + "/" + X);
        else
            System.out.println(X + "/" + (count - X + 1));
    }
}
