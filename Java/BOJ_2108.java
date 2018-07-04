/*
Statistics

https://www.acmicpc.net/problem/2108
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Collections;
import java.util.ArrayList;
import java.util.HashSet;

class BOJ_2108 {
    public static void main(String[] args) throws IOException {
        new statistics().run();
    }
}
class statistics {
    public void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList <Integer> data = new ArrayList <Integer> ();
        for (int i = 0; i < N; i++) {
            data.add(Integer.parseInt(br.readLine()));
        }
        System.out.println(arithmeticMean(data));
        System.out.println(median(data));
        System.out.println(mode(data));
        System.out.println(range(data));
    }
    public int arithmeticMean(ArrayList <Integer> data) {
        int sum = 0;
        for (int i : data) {
            sum += i;
        }
        return (int) Math.ceil( (float) sum / data.size() - 0.5f);
    }
    public int median(ArrayList <Integer> data) {
        Collections.sort(data);
        return data.get(data.size() / 2);
    }
    public int mode(ArrayList <Integer> data) {
        int maxValue = 0, maxCount = 0, check = 0, result = 0;

        // Copy ArrayList to int []
        int [] temp = new int [data.size()];
        for (int i = 0; i < data.size(); i++) {
            temp[i] = data.get(i);
        }

        // Find max value of int []
        for (int i : temp) {
            if (maxValue < Math.abs(i)) {
                maxValue = Math.abs(i);
            }
        }

        // Check the count of each element of int [] and find max count of it
        int [] count = new int [2 * maxValue + 1];
        for (int i : temp) {
            count[i + maxValue]++;
            maxCount = Math.max(maxCount, count[i + maxValue]);
        }

        // Find the mode value of int []
        for (int i = 0; i < count.length; i++) {
            if (maxCount == count[i]) {
                result = i - maxValue;
                check++;
            }
            if (check == 2) {
                break;
            }
        }
        return result;
    }
    public int range(ArrayList <Integer> data) {
        return Collections.max(data) - Collections.min(data);
    }
}
