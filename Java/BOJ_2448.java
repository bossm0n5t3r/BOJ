/*
 *  Printing stars - 11
 *
 *  https://www.acmicpc.net/problem/2448
 */

import java.io.*;

public class BOJ_2448 {
    static char [][] space;
    public static void main(String [] args) throws IOException {
        BOJ_2448 main = new BOJ_2448();
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        space = new char [N][2*N];
        main.printStars(0, 0, N);
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < 2 * N - 1; ++i) {
                if (space[j][i] != '\0')
                    sb.append(space[j][i]);
                else
                    sb.append(' ');
            }
            System.out.println(sb);
            sb.setLength(0);
        }
    }

    static void printStars(int x, int y, int N) {
        if (N == 3) {
            space[y][x+2] = '*';
            space[y+1][x+1] = '*';
            space[y+1][x+3] = '*';
            space[y+2][x] = '*';
            space[y+2][x+1] = '*';
            space[y+2][x+2] = '*';
            space[y+2][x+3] = '*';
            space[y+2][x+4] = '*';
            return;
        }
        int div = N/2;
        printStars(x + div, y, div);
        printStars(x, y + div, div);
        printStars(x + N, y + div, div);
    }
}
