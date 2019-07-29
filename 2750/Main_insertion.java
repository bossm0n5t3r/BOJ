import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main_insertion {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int [] data = new int [N];
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        Main_insertion main = new Main_insertion();
        main.insertionSort(data);
        for (int i : data) {
            System.out.println(i);
        }
    }

    void insertionSort (int [] arr) {
        int index = 1;
        while (index < arr.length) {
            int x = arr[index];
            int temp = index - 1;
            while (temp >= 0 && arr[temp] > x) {
                arr[temp + 1] = arr[temp];
                temp--;
            }
            arr[temp + 1] = x;
            index++;
        }
    }
}
