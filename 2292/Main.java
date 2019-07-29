import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int ub = 1, pt = 1;
        while (ub < N) {
            ub += pt * 6;
            pt++;
        }
        System.out.println(pt);
    }
}
