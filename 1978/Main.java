import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int index = 0, result = 0;
        Prime [] p = new Prime [N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            p[index] = new Prime(Integer.parseInt(st.nextToken()));
            if (p[index].checkPrime()) {
                result++;
            }
            index++;
        }
        System.out.println(result);
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
