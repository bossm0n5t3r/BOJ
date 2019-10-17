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
        Bfs bfs = new Bfs(data, N, M);
        bfs.run();
    }
}

class Bfs {
    private int[][] data;
    private int N;
    private int M;
    private boolean[][] visited;
    private Queue<int[]> q;

    Bfs(int[][] data, int N, int M) {
        this.data = data;
        this.N = N;
        this.M = M;
        this.visited = new boolean[N][M];
        this.q = new LinkedList<int[]>();
    }

    void run() {
        visited[0][0] = true;
        q.add(new int[] { 0, 0, 1 });
        while (!q.isEmpty()) {
            int[] current = q.poll();
            if ((current[0] == N - 1) && (current[1] == M - 1)) {
                System.out.println(current[2]);
                break;
            }
            if ((current[0] - 1 >= 0) && (data[current[0] - 1][current[1]] == 1)) {
                if (!visited[current[0] - 1][current[1]]) {
                    visited[current[0] - 1][current[1]] = true;
                    q.add(new int[] { current[0] - 1, current[1], current[2] + 1 });
                }
            }
            if ((current[0] < N - 1) && (data[current[0] + 1][current[1]] == 1)) {
                if (!visited[current[0] + 1][current[1]]) {
                    visited[current[0] + 1][current[1]] = true;
                    q.add(new int[] { current[0] + 1, current[1], current[2] + 1 });
                }
            }
            if ((current[1] - 1 >= 0) && (data[current[0]][current[1] - 1] == 1)) {
                if (!visited[current[0]][current[1] - 1]) {
                    visited[current[0]][current[1] - 1] = true;
                    q.add(new int[] { current[0], current[1] - 1, current[2] + 1 });
                }
            }
            if ((current[1] < M - 1) && (data[current[0]][current[1] + 1] == 1)) {
                if (!visited[current[0]][current[1] + 1]) {
                    visited[current[0]][current[1] + 1] = true;
                    q.add(new int[] { current[0], current[1] + 1, current[2] + 1 });
                }
            }
        }
    }
}