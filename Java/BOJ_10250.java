/*
 *  ACM Hotel
 *
 *  https://www.acmicpc.net/problem/10250
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_10250 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            String [] temp = br.readLine().split(" ");
            int H = Integer.parseInt(temp[0]);
            int N = Integer.parseInt(temp[2]);
            int count = 1;
            while (N > H) {
                N -= H;
                count++;
            }
            System.out.printf("%d%02d\n", N, count);
        }
    }
}
