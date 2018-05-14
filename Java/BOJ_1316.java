/*
 *  Group word Checker
 *
 *  https://www.acmicpc.net/problem/1316
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_1316 {
    public static void main (String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int count = 0;
        for (int i = 0; i < N; i++) {
            String temp = br.readLine();
            String [] save = new String [temp.length()];
            int point = 0;
            String [] templist = temp.split("");
            boolean found = false;
            int j = 0;
            while (j < templist.length) {

                /* check whether templist[j] contains in save or not */
                for (int k = 0; k < save.length; k++) {
                    if (k != j && templist[j].equals(save[k])) {
                        found = true;
                    }
                }
                
                /* if templist[j] is found in save and exit */
                /* else if templist[j] is found in save but same with templist[j-1], found should be "false" */
                /* else, contain templist[j] in save */
                if (found && !templist[j].equals(templist[j-1])) {
                    break;
                } else if (j !=0 && templist[j].equals(templist[j-1])) {
                    found = false;
                } else {
                    save[point] = templist[j];
                    point++;
                }
                j++;
            }
            if (!found) {
                count++;
            }
        }
        System.out.println(count);
    }
}
