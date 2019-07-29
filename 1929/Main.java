import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] input = br.readLine().split(" ");
        int M = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);
        Eratosthenes e = new Eratosthenes(M, N);
        e.operate();
        e.print();
    }
}

class Eratosthenes {
    private int start;
    private int end;
    private boolean [] check;

    public Eratosthenes(int start, int end) {
        this.start = start;
        this.end = end;
        check = new boolean [end + 1];
        check[0] = check[1] = true;
    }

    public void operate() {
        for (int i = 2; i < check.length; i++) {
            if (!check[i]) {
                for (int j = i + i; j < check.length; j += i) {
                    check[j] = true;
                }
            }
        }
    }

    public void print() {
        StringBuffer sb = new StringBuffer();
        for(int i = start; i <= end; i++) {
            if (!check[i]) {
                sb.append(i + "\n");
            }
        }
        System.out.println(sb.toString());
    }
}
