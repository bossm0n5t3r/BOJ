import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i, N = Integer.parseInt(br.readLine());
        long[] save = new long[N + 1];
        save[1] = 1;
        if (N > 1) {
            save[2] = 1;
        }
        for (i = 3; i <= N; i++) {
            save[i] = save[i - 1] + save[i - 2];
        }
        System.out.println(save[N]);
    }
}