import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = br.readLine().split(" ");
        int N = Integer.parseInt(nk[0]);
        int K = Integer.parseInt(nk[1]);
        int[] W = new int[N];
        int[] V = new int[N];
        for (int i = 0; i < N; i++) {
            String[] tmp = br.readLine().split(" ");
            W[i] = Integer.parseInt(tmp[0]);
            V[i] = Integer.parseInt(tmp[1]);
        }
        System.out.println(knapSack(K, W, V, N));
    }

    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    static int knapSack(int K, int[] W, int[] V, int N) {
        int i, j;
        int[][] save = new int[N + 1][K + 1];
        for (i = 0; i <= N; i++) {
            for (j = 0; j <= K; j++) {
                if (i == 0 || j == 0)
                    save[i][j] = 0;
                else if (W[i - 1] <= j)
                    save[i][j] = max(V[i - 1] + save[i - 1][j - W[i - 1]], save[i - 1][j]);
                else
                    save[i][j] = save[i - 1][j];
            }
        }
        return save[N][K];
    }
}