/*
Sorting numbers 3
Using Radix Sort
LSD Implementation

https://www.acmicpc.net/problem/10989

!!! NOTICE !!!
It's NOT A SOLUTION of Problem 10989 !!!
Error : MEMORY EXCEEDED
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.ArrayList;

class BOJ_10989_radix_lsd {
    public static void main(String[] args) throws IOException {
        new RadixSort().run();
    }
}
class RadixSort {
    public void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        ArrayList <Integer> data = new ArrayList <Integer>();
        for (int i = 0; i < N; i++) {
            data.add(Integer.parseInt(br.readLine()));
        }
        int base = 10;
        radixSort(data, base);
        for (int i : data) {
            bw.write(i + "\n");
        }
        bw.close();
    }
    public void radixSort(ArrayList <Integer> data, int base) {
        ArrayList <Integer> temp = data;
        int maxValue = Collections.max(data);
        int iter = 0;
        while ((int)Math.pow(base, iter) <= maxValue) {
            temp = buckets_to_list(list_to_buckets(temp, base, iter));
            iter++;
        }
        Collections.copy(data, temp);
    }
    public ArrayList <ArrayList <Integer>> list_to_buckets(ArrayList <Integer> data, int base, int iteration) {
        ArrayList <ArrayList <Integer>> buckets = new ArrayList <ArrayList <Integer>>();

        // initialise buckets as ArrayList of ArrayLists
        for (int i = 0; i < base; i++) {
            buckets.add(new ArrayList <Integer> ());
        }
        for (int i : data) {
            int digit = (i / (int)Math.pow(base, iteration)) % base;
            buckets.get(digit).add(i);
        }
        for (int i = buckets.size() - 1; i > -1; i--) {
            ArrayList <Integer> temp = buckets.get(i);
            if (temp.isEmpty()) {
                buckets.remove(temp);
            }
        }
        return buckets;
    }
    public ArrayList <Integer> buckets_to_list(ArrayList <ArrayList <Integer>> buckets) {
        ArrayList <Integer> data = new ArrayList <Integer> ();
        for (ArrayList <Integer> i : buckets) {
            for (int j : i) {
                data.add(j);
            }
        }
        return data;
    }
}