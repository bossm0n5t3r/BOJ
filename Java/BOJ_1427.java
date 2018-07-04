/*
Sort inside

https://www.acmicpc.net/problem/1427
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

class BOJ_1427 {
    public static void main(String[] args) throws IOException {
        new sortInside().run();
    }
}
class sortInside {
    void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String N = br.readLine();
        char [] data = N.toCharArray();
        Arrays.sort(data);
        for (int i = data.length - 1; i > -1; i--) {
            sb.append(data[i]);
        }
        System.out.println(sb);
    }
}