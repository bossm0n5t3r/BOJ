/*
 *  LJESNJAK
 *
 *  https://www.acmicpc.net/problem/2941
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_2941 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String []  croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
        String temp = br.readLine();
        int count = 0, point = 0;
        while (true) {
            int save = point;
            if (point < temp.length() - 2) {
                String subtemp3 = temp.substring(point, point + 3);
                if (croatia[2].equals(subtemp3)) {
                    count++;
                    point += 3;
                }
            }
            if (point < temp.length() - 1) {
                String subtemp2 = temp.substring(point, point + 2);
                for (int i = 0; i < croatia.length; i++) {
                    if (croatia[i].equals(subtemp2)) {
                        count++;
                        point += 2;
                        break;
                    }
                }
            }
            if (save == point) {
                count++;
                point++;
            }
            if (point == temp.length()) break;
        }
        System.out.println(count);
    }
}
