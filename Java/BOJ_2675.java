/*
 *  Repeating Characters
 *
 *  https://www.acmicpc.net/problem/2675
 */

import java.io.*;
import java.util.*;

class BOJ_2675 {
    public static void main (String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int R = Integer.parseInt(st.nextToken());
            String str = st.nextToken();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < str.length(); i++) {
                char temp = str.charAt(i);
                for (int j = 0; j < R; j++) {
                    sb.append(temp);
                }
            }
            System.out.println(sb);
        }
    }
}
