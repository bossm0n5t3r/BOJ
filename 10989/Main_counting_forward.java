import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

class Main_counting_forward {
    public static void main(String[] args) throws IOException {
        new Main_counting_forward().run();
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
        int max = 0, total = 0;
        int [] output = new int[data.length + 1];

        for (int i : data) {
            if (i > max) {
                max = i;
            }
        }

        int [] count = new int [max + 1];

        for (int i : data) {
            count[i]++;
        }

        for (int i = 0; i < max + 1; i++) {
            int oldCount = count[i];
            count[i] = total;
            total += oldCount;
        }

        for (int i = 0; i < data.length; i++) {
            output[count[data[i]]] = data[i];
            count[data[i]]++;
        }

        System.arraycopy(output, 0, data, 0, data.length);
    }
}
