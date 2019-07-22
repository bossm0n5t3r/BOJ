/*
Sorting Coordinates

https://www.acmicpc.net/problem/11650
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class BOJ_11650 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        int[][] coordinates = new int[N][2];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            coordinates[i][0] = Integer.parseInt(st.nextToken());
			coordinates[i][1] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(coordinates, new Comparator<int[]>() {
            public int compare(int[] p1, int[] p2) {
                int xComp = Integer.compare(p1[0], p2[0]);
                if (xComp == 0) {
                    return Integer.compare(p1[1], p2[1]);
                } else {
                    return xComp;
                }
            }
        });
        for (int[] point : coordinates) {
            bw.write(point[0] + " " + point[1] + "\n");
        }
        bw.flush();
        bw.close();
    }
}