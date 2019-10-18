import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int count = 0, i;
        while (N > 0) {
            i = (int) Math.sqrt(N);
            while (((i * (i + 1)) / 2) <= N) {
                i++;
            }
            i--;
            count += i;
            N -= (i * (i + 1)) / 2;
        }
        System.out.println(count);
    }
}