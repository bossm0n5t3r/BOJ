import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

class Main_counting_backward {
    public static void main(String[] args) throws IOException {
        new Main_counting_backward().run();
    }

    void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        int [] data = new int [N];
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        countingSort(data);
        for (int i : data) {
            bw.write(i + "\n");
        }
        bw.close();
    }

    void countingSort(int [] data) {
        int max = 0;
        int [] output = new int[data.length + 1];

        for (int i : data) {
            if (i > max) {
                max = i;
            }
        }

        int [] count = new int [max + 1];
        int [] count_sum = new int [max + 1];

        for (int i : data) {
            count[i]++;
        }

        count_sum[0] = count[0];

        for (int i = 1; i < max + 1; i++) {
            count_sum[i] = count_sum[i-1] + count[i];
        }

        for (int i = data.length - 1; i > -1; i--) {
            output[count_sum[data[i]]] = data[i];
            count_sum[data[i]]--;
        }

        System.arraycopy(output, 1, data, 0, data.length);
    }
}
