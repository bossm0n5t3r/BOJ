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

class Dot {
    int x;
    int y;

    public Dot(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Bfs {
    private int[][] data;
    private int[][] map;
    private int N;
    private int M;
    private boolean[][] visited;
    private Queue<Dot> q;

    Bfs(int[][] data, int N, int M) {
        this.data = data;
        this.map = new int[N][M];
        this.N = N;
        this.M = M;
        this.visited = new boolean[N][M];
        this.q = new LinkedList<Dot>();
    }

    void run() {
        int[] dy = { -1, 0, 1, 0 };
        int[] dx = { 0, 1, 0, -1 };
        visited[0][0] = true;
        map[0][0] = 1;
        q.add(new Dot(0, 0));
        while (!q.isEmpty()) {
            Dot p = q.poll();
            if (p.x == N - 1 && p.y == M - 1) {
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (visited[nx][ny] == false && data[nx][ny] == 1) {
                        visited[nx][ny] = true;
                        map[nx][ny] = map[p.x][p.y] + 1;
                        q.offer(new Dot(nx, ny));
                    }
                }
            }
        }
        System.out.println(map[N - 1][M - 1]);
    }
}