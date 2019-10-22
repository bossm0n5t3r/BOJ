import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long T = Long.parseLong(br.readLine());
        int n = parse(br.readLine());
        String[] tmpA = br.readLine().split(" ");
        int m = parse(br.readLine());
        String[] tmpB = br.readLine().split(" ");
        int[] A = new int[n + 1];
        int[] B = new int[m + 1];
        for (int i = 1; i <= n; i++) {
            A[i] = parse(tmpA[i - 1]);
        }
        for (int i = 1; i <= m; i++) {
            B[i] = parse(tmpB[i - 1]);
        }
        ArrayList<Long> partialSumA = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            long sum = A[i];
            partialSumA.add(sum);
            for (int j = i + 1; j <= n; j++) {
                sum += A[j];
                partialSumA.add(sum);
            }
        }
        int count = 0;
        for (long tmp : partialSumA) {
            int start = 0, end = 0;
            long sum = 0, target = T - tmp;
            while (target > 0) {
                if (sum >= target) {
                    sum = sum - B[start++];
                } else if (end == m) {
                    break;
                } else {
                    sum = sum + B[end++];
                }
                if (sum == target) {
                    System.out.println(tmp + " : " + start + ", " + end);
                    count++;
                }
            }
        }

        System.out.println(count);
    }

    private static int parse(String str) {
        return Integer.parseInt(str);
    }
}