/*
 *  Sorting numbers
 *  Using Merge Sort
 *  Bottom-Up Implementation
 *
 *  https://www.acmicpc.net/problem/2750
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_2750 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int [] data = new int [N];
        int [] temp = new int [N];
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        BOJ_2750 main = new BOJ_2750();
        main.mergeSort(data, temp, N);
        for (int i : data) {
            System.out.println(i);
        }
    }
    void mergeSort (int [] A, int [] B, int N) {
        for (int width = 1; width < N; width *= 2) {
            for (int i = 0; i < N; i += 2 * width) {
                BottomUpMerge(A, i, Math.min(i + width, N), Math.min(i + 2 * width, N), B);
            }
            copyArray(B, A, N);
        }
    }
    void BottomUpMerge (int [] A, int iLeft, int iRight, int iEnd, int [] B) {
        int i = iLeft, j = iRight;
        for (int k = iLeft; k < iEnd; k++) {
            if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
        }
    }
    void copyArray (int [] B, int [] A, int N) {
        for (int i = 0; i < N; i++) {
            A[i] = B[i];
        }
    }
}