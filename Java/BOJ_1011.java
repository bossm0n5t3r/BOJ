/*
 *  Fly me to the Alpha Centauri
 *
 *  https://www.acmicpc.net/problem/1011
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_1011 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String [] temp = br.readLine().split(" ");
            int dist = Integer.parseInt(temp[1]) - Integer.parseInt(temp[0]);
            int check = (int) Math.sqrt(dist);
            if (dist - Math.pow(check, 2) > check) {
                System.out.println(2 * check + 1);
            } else if (dist - Math.pow(check, 2) > 0){
                System.out.println(2 * check);
            } else {
                System.out.println(2 * check - 1);
            }
        }
    }
}
