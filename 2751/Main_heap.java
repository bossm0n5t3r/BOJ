import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main_heap {
    public static void main(String[] args) throws IOException {
        new Main_heap().run();
    }

    void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int [] data = new int [N];
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        heapSort(data, N);
        for (int i : data) {
            sb.append(i + "\n");
        }
        System.out.println(sb.toString());
    }

    void heapSort (int [] data, int N) {
        heapify(data, N);
        int end = N - 1;
        while (end > 0) {
            swap(data, end, 0);
            end--;
            siftDown(data, 0, end);
        }
    }

    void heapify (int [] data, int N) {
        int start = iParent(N - 1);
        while (start >= 0) {
            siftDown(data, start, N - 1);
            start--;
        }
    }

    void siftDown (int [] data, int start, int end) {
        int root = start;
        while (iLeftChild(root) <= end) {
            int child = iLeftChild(root);
            int swap = root;
            if (data[swap] < data[child]) {
                swap = child;
            }
            if (child + 1 <= end && data[swap] < data[child + 1]) {
                swap = child + 1;
            }
            if (swap == root) {
                return;
            } else {
                swap(data, root, swap);
                root = swap;
            }
        }
    }

    void swap (int [] data, int a, int b) {
        int temp = data[a];
        data[a] = data[b];
        data[b] = temp;
    }

    static int iParent (int i) {
        return (i - 1) / 2;
    }

    static int iLeftChild (int i) {
        return 2 * i + 1;
    }

    static int iRightChild (int i) {
        return 2 * i + 2;
    }
}
