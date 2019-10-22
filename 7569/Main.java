import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] mnh = br.readLine().split(" ");
        int M = Integer.parseInt(mnh[0]);
        int N = Integer.parseInt(mnh[1]);
        int H = Integer.parseInt(mnh[2]);
        int[][][] box = new int[H][N][M];
        Queue<Dot> q = new LinkedList<>();
        boolean[][][] visited = new boolean[H][N][M];
        int i, j, k, v, check = 0;
        for (k = 0; k < H; k++) {
            for (j = 0; j < N; j++) {
                String[] tmp = br.readLine().split(" ");
                for (i = 0; i < M; i++) {
                    v = Integer.parseInt(tmp[i]);
                    box[k][j][i] = v;
                    if (v == 1) {
                        q.add(new Dot(k, j, i));
                    }
                    if (v == 0) {
                        check++;
                    } else {
                        visited[k][j][i] = true;
                    }
                }
            }
        }
        if (check == 0) {
            System.out.println(0);
        } else {
            Bfs bfs = new Bfs(H, N, M, box, q, visited);
            bfs.run();
        }
    }
}

class Dot {
    int x;
    int y;
    int z;

    Dot(int z, int y, int x) {
        this.z = z;
        this.y = y;
        this.x = x;
    }
}

class Bfs {
    private int H;
    private int N;
    private int M;
    private int[][][] box;
    private boolean[][][] visited;
    private Queue<Dot> q;
    private int[][][] date;

    Bfs(int H, int N, int M, int[][][] box, Queue<Dot> q, boolean[][][] visited) {
        this.H = H;
        this.N = N;
        this.M = M;
        this.box = box;
        this.visited = visited;
        this.q = q;
        this.date = new int[H][N][M];
    }

    void run() {
        int[] dz = { -1, 0, 0, 0, 0, 1 };
        int[] dy = { 0, -1, 0, 1, 0, 0 };
        int[] dx = { 0, 0, 1, 0, -1, 0 };
        int i, x, y, z, nx, ny, nz, max = 0;
        Dot v;
        while (!q.isEmpty()) {
            v = q.poll();
            z = v.z;
            y = v.y;
            x = v.x;
            for (i = 0; i < 6; i++) {
                nz = z + dz[i];
                ny = y + dy[i];
                nx = x + dx[i];
                if (nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M && box[nz][ny][nx] == 0
                        && !visited[nz][ny][nx]) {
                    visited[nz][ny][nx] = true;
                    date[nz][ny][nx] = date[z][y][x] + 1;
                    max = max > date[nz][ny][nx] ? max : date[nz][ny][nx];
                    q.add(new Dot(nz, ny, nx));
                }
            }
        }
        v = null;
        outerloop: for (z = 0; z < H; z++) {
            for (y = 0; y < N; y++) {
                for (x = 0; x < M; x++) {
                    if (!visited[z][y][x] && box[z][y][x] == 0) {
                        v = new Dot(z, y, x);
                        break outerloop;
                    }
                }
            }
        }
        if (v != null) {
            System.out.println(-1);
        } else {
            System.out.println(max);
        }
    }
}