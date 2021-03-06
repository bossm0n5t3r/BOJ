import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main_selection {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int [] data = new int [N];
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        Main_selection main = new Main_selection();
        main.selectionSort(data);
        for (int i : data) {
            System.out.println(i);
        }
    }
    
    void selectionSort (int [] arr) {
        int indexMin, temp;
        for (int i = 0; i < arr.length; i++) {
            indexMin = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[indexMin]) {
                    indexMin = j;
                }
            }
            if (indexMin != i) {
                temp = arr[i];
                arr[i] = arr[indexMin];
                arr[indexMin] = temp;
            }
        }
    }
}
