import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            int [][] data = new int [N][2];
            for (int j = 0; j < N; j++) {
                String [] tmp = br.readLine().split(" ");
                data[j][0] = Integer.parseInt(tmp[0]);
                data[j][1] = Integer.parseInt(tmp[1]);
            }
            int count = new Main().movingCount(data, N);
            System.out.println(count * 10);
        }
    }

    int movingCount (int [][] data, int N) {
        int result = 0;
        int [] rooms = new int [400];
        for (int i = 0; i < N; i++) {
            int start = data[i][0];
            int end = data[i][1];
            if (start > end) {
                int tmp = start;
                start = end;
                end = tmp;
            }
            if (start % 2 == 0) {
                start--;
            }
            if (end % 2 == 1) {
                end++;
            }
            for (int j = start; j <= end; j++) {
                rooms[j-1]++;
            }
        }
        Arrays.sort(rooms);
        result = rooms[rooms.length - 1];
        return result;
    }
}
