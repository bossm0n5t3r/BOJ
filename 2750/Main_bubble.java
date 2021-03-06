import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main_bubble {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int [] data = new int [N];
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        Main_bubble main = new Main_bubble();
        main.bubbleSort(data);
        for (int i : data) {
            System.out.println(i);
        }
    }

    void bubbleSort (int [] arr) {
        int n = arr.length;
        while (n != 0) {
            int newn = 0;
            for (int i = 1; i < n; i++) {
                if (arr[i-1] > arr[i]) {
                    int temp = arr[i-1];
                    arr[i-1] = arr[i];
                    arr[i] = temp;
                    newn = i;
                }
            }
            n = newn;
        }
    }
}
