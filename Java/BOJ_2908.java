/*
 *  FILIP
 *
 *  https://www.acmicpc.net/problem/2908
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_2908 {
    public static void main (String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String temp = br.readLine();
        String [] templist = temp.split(" ");
        int [] group = new int [2];
        for (int i = 0; i < 2; i++) {
            String [] set = templist[i].split("");
            String save = "";
            for (int j = set.length - 1; j > -1; j--) {
                save += set[j];
            }
            group[i] = Integer.parseInt(save);
        }
        System.out.println(group[0] > group [1] ? group[0] : group[1]);
    }
}
