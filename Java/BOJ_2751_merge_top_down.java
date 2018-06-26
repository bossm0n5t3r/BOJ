/*
 *  Sorting numbers 2
 *  Using Merge Sort
 *  Top-Down Implementation
 *
 *  https://www.acmicpc.net/problem/2751
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BOJ_2751_merge_top_down {
    public static void main(String[] args) throws IOException {
        new BOJ_2751_merge_top_down().run();
    }

    void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int [] data = new int [N];
        int [] temp = new int [N];
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        mergeSort(data, temp, N);
        for (int i : data) {
            sb.append(i + "\n");
        }
        System.out.println(sb.toString());
    }

    void mergeSort (int [] A, int [] B, int N) {
        copyArray(A, 0, N, B);
        TopDownSplitMerge(B, 0, N, A);
    }

    void TopDownSplitMerge (int [] B, int iBegin, int iEnd, int [] A) {
        if (iEnd - iBegin < 2)
            return;
        int iMiddle = (iEnd + iBegin) / 2;

        TopDownSplitMerge(A, iBegin, iMiddle, B);
        TopDownSplitMerge(A, iMiddle, iEnd, B);

        TopDownMerge(B, iBegin, iMiddle, iEnd, A);
    }

    void TopDownMerge (int [] A, int iBegin, int iMiddle, int iEnd, int [] B) {
        int i = iBegin, j = iMiddle;
        for (int k = iBegin; k < iEnd; k++) {
            if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
        }
    }

    void copyArray (int [] A, int iBegin, int iEnd, int [] B) {
        for (int k = iBegin; k < iEnd; k++) {
            B[k] = A[k];
        }
    }
}