import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);
        int[][] map = new int[N][M];
        int i, j, x;
        for (i = 0; i < N; i++) {
            String[] tmp = br.readLine().split("");
            for (j = 0; j < M; j++) {
                x = Integer.parseInt(tmp[j]);
                map[i][j] = x;
            }
        }
        Bfs bfs = new Bfs(N, M, map);
        bfs.run();
    }
}

class Dot {
    int x;
    int y;
    int w;

    Dot(int x, int y, int w) {
        this.x = x;
        this.y = y;
        this.w = w;
    }
}

class Bfs {
    private int N;
    private int M;
    private int[][] map;
    private int[][][] dist;
    private Queue<Dot> q;

    Bfs(int N, int M, int[][] map) {
        this.N = N;
        this.M = M;
        this.map = map;
        this.dist = new int[N][M][2];
        this.q = new LinkedList<>();
    }

    void run() {
        int i, x, y, w, nx, ny;
        int[] dx = { 0, 1, 0, -1 };
        int[] dy = { -1, 0, 1, 0 };
        q.add(new Dot(0, 0, 0));
        dist[0][0][0] = 1;
        while (!q.isEmpty()) {
            Dot v = q.poll();
            x = v.x;
            y = v.y;
            w = v.w;
            if (x == N - 1 && y == M - 1) {
                System.out.println(dist[x][y][w]);
                return;
            }
            for (i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && dist[nx][ny][w] == 0) {
                    if (map[nx][ny] == 0) {
                        dist[nx][ny][w] = dist[x][y][w] + 1;
                        q.add(new Dot(nx, ny, w));
                    }
                    if (map[nx][ny] == 1 && w == 0) {
                        dist[nx][ny][1] = dist[x][y][w] + 1;
                        q.add(new Dot(nx, ny, 1));
                    }
                }
            }
        }
        System.out.println(-1);
    }
}