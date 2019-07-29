import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        ArrayList <Integer> data = new ArrayList <Integer> ();
        int max = 0;
        while (true) {
            int temp = Integer.parseInt(br.readLine());
            if (temp == 0) {
                break;
            }
            data.add(temp);
            if (max < temp) {
                max = temp;
            }
        }
        PrimeList pl = new PrimeList(max);
        pl.compute();
        boolean [] pList = pl.getpList();
        for (int n : data) {
            int count = 0;
            for (int i = n + 1; i <= 2 * n; i++) {
                if (pList[i]) {
                    count++;
                }
            }
            sb.append(count + "\n");
        }
        System.out.println(sb.toString());
    }
}

class PrimeList {
    private int max;
    private boolean [] pList;

    public PrimeList (int max) {
        this.max = max;
        pList = new boolean [2 * max + 1];
    }

    public boolean [] getpList() {
        return pList;
    }

    public void compute() {
        for (int i = 0; i <= 2 * max; i++) {
            if (checkPrime(i)) {
                pList[i] = true;
            }
        }
    }

    public boolean checkPrime(int num) {
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
