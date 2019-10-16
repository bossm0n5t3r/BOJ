import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Collections;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) throws IOException {
        new statistics().run();
    }
}

class statistics {
    public void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer> data = new ArrayList<Integer>();
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, sum = 0;
        for (int i = 0; i < N; i++) {
            int value = Integer.parseInt(br.readLine());
            sum += value;
            max = Math.max(max, value);
            min = Math.min(min, value);
            data.add(value);
        }
        int range = max - min;
        int maxAbs = Math.max(Math.abs(max), Math.abs(min));
        int[] count = new int[2 * maxAbs + 1];
        Collections.sort(data);
        int median = data.get(data.size() / 2);
        int maxCount = 0, check = 0, mode = 0;
        for (int value : data) {
            count[value + maxAbs] += 1;
            maxCount = Math.max(maxCount, count[value + maxAbs]);
        }
        for (int i = 0; i < count.length; i++) {
            if (maxCount == count[i]) {
                mode = i - maxAbs;
                check++;
            }
            if (check == 2) {
                break;
            }
        }
        System.out.println((int) Math.ceil((double) sum / data.size() - 0.5f));
        System.out.println(median);
        System.out.println(mode);
        System.out.println(range);
    }
}
