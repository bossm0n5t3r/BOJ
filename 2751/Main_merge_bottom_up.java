import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main_merge_bottom_up {
    public static void main(String[] args) throws IOException {
        new Main_merge_bottom_up().run();
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
