import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int L = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        int people = L * P;
        String[] data = br.readLine().split(" ");
        for (String candidates : data) {
            int tmp = Integer.parseInt(candidates);
            System.out.print(tmp - people + " ");
        }
        System.out.println();
    }
}