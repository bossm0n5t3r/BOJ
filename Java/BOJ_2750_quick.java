/*
 *  Sorting numbers
 *  Using Quick Sort
 *
 *  https://www.acmicpc.net/problem/2750
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_2750_quick {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int [] data = new int [N];
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        BOJ_2750_quick main = new BOJ_2750_quick();
        main.quickSort(data, 0, data.length - 1);
        for (int i : data) {
            System.out.println(i);
        }
    }
    void quickSort(int [] data, int l, int r) {
        int left = l;
        int right = r;
        int pivot = data[(l + r)/2];
        do {
            while (data[left] < pivot) {
                left++;
            }
            while (data[right] > pivot) {
                right--;
            }
            if (left <= right) {
                int temp = data[left];
                data[left] = data[right];
                data[right] = temp;
                left++;
                right--;
            }
        } while (left <= right);
        if (l < right) {
            quickSort(data, l, right);
        }
        if (r > left) {
            quickSort(data, left, r);
        }
    }
}
