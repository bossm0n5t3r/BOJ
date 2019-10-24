import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i, n = Integer.parseInt(br.readLine());
        int[] save = new int[n + 1];
        save[1] = 1;
        if (n > 1) {
            save[2] = 2;
        }
        for (i = 3; i <= n; i++) {
            save[i] = (save[i - 1] + save[i - 2]) % 10007;
        }
        System.out.println(save[n]);
    }
}