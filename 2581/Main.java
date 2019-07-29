import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());
        int min = 0, sum = 0;
        boolean checkExistPrime = false;
        for (int i = M; i <= N; i++) {
            Prime p = new Prime(i);
            if (p.checkPrime()) {
                checkExistPrime = true;
                if (min == 0) {
                    min = i;
                }
                min = Math.min(min, i);
                sum += i;
            }
        }
        if (checkExistPrime) {
            System.out.println(sum);
            System.out.println(min);
        } else {
            System.out.println(-1);
        }
    }
}

class Prime {
    private int num;

    public Prime (int num) {
        this.num = num;
    }

    public boolean checkPrime() {
        if (num == 1) {
            return false;
        } else if (num == 2) {
            return true;
        }
        int tmp = 2;
        while (tmp * tmp <= num) {
            if (num % tmp == 0) {
                return false;
            }
            tmp++;
        }
        return true;
    }
}
