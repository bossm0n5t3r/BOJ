import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] data = br.readLine().split(" ");
        int tmp, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            tmp = Integer.parseInt(data[i]);
            min = min > tmp ? tmp : min;
            max = max < tmp ? tmp : max;
        }
        System.out.println(min * max);
    }
}