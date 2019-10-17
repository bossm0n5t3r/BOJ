import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Queue;
import java.util.LinkedList;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);
        int[][] data = new int[N][M];
        for (int i = 0; i < N; i++) {
            String[] tmp = br.readLine().split("");
            for (int j = 0; j < M; j++) {
                data[i][j] = Integer.parseInt(tmp[j]);
            }
        }
        boolean[][] visited = new boolean[N][M];
        Queue<int[]> q = new LinkedList<int[]>();
        visited[0][0] = true;
        q.add(new int[] { 0, 0 });
        
    }
}