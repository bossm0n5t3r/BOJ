import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] ropes = new int[N];
        int i, max = 0;
        for (i = 0; i < N; i++) {
            ropes[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(ropes);
        for (i = 0; i < N; i++) {
            if (max < ropes[i] * (N - i)) {
                max = ropes[i] * (N - i);
            }
        }
        System.out.println(max);
    }
}