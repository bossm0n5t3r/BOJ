import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int index = 0;
            while (n > 0) {
                if (n % 2 == 1) {
                    System.out.print(index + " ");
                }
                n /= 2;
                index++;
            }
            System.out.println();
        }
    }
}