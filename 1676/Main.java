import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int tmp, cntOfTwo = 0, cntOfFive = 0;
        while (N > 0) {
            tmp = N;
            while (tmp % 2 == 0) {
                cntOfTwo++;
                tmp /= 2;
            }
            while (tmp % 5 == 0) {
                cntOfFive++;
                tmp /= 5;
            }
            N--;
        }
        System.out.println(cntOfTwo > cntOfFive ? cntOfFive : cntOfTwo);
    }
}