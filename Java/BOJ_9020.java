/*
Goldbach’s Conjecture

https://www.acmicpc.net/problem/9020
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_9020 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Goldbach g = null;
        int [] result = null;
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            g = new Goldbach(Integer.parseInt(br.readLine()));
            g.compute();
            result = g.getresult();
            sb.append(result[0] + " " + result[1] + "\n");
        }
        System.out.println(sb.toString());
    }
}
class Goldbach {
    private int n;
    private int [] result = new int [2];

    public Goldbach(int n) {
        this.n = n;
    }

    public int [] getresult() {
        return result;
    }

    public void compute() {
        for (int i = n / 2; i >= 2; i--) {
            int j = n - i;
            if (checkPrime(i) && checkPrime(j)) {
                result[0] = i;
                result[1] = j;
                break;
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