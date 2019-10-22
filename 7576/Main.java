import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] mn = br.readLine().split(" ");
        int M = Integer.parseInt(mn[0]);
        int N = Integer.parseInt(mn[1]);
        int[][] box = new int[N][M];
        Queue<Dot> q = new LinkedList<>();
        boolean[][] visited = new boolean[N][M];
        int i, j, v, check = 0;
        for (i = 0; i < N; i++) {
            String[] tmp = br.readLine().split(" ");
            for (j = 0; j < M; j++) {
                v = Integer.parseInt(tmp[j]);
                box[i][j] = v;
                if (v == 1) {
                    q.add(new Dot(i, j));
                }
                if (v == 0) {
                    check++;
                } else {
                    visited[i][j] = true;
                }
            }
        }
        if (check == 0) {
            System.out.println(0);
        } else {
            Bfs bfs = new Bfs(M, N, box, q, visited);
            bfs.run();
        }
    }
}

class Dot {
    int x;
    int y;

    Dot(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Bfs {
    private int M;
    private int N;
    private int[][] box;
    private boolean[][] visited;
    private Queue<Dot> q;
    private int[][] date;

    Bfs(int M, int N, int[][] box, Queue<Dot> q, boolean[][] visited) {
        this.M = M;
        this.N = N;
        this.box = box;
        this.visited = visited;
        this.q = q;
        this.date = new int[N][M];
    }

    void run() {
        int[] dx = { 0, 1, 0, -1 };
        int[] dy = { -1, 0, 1, 0 };
        int i, x, y, nx, ny, max = 0;
        Dot v;
        while (!q.isEmpty()) {
            v = q.poll();
            x = v.x;
            y = v.y;
            for (i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (box[nx][ny] == 0 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        date[nx][ny] = date[x][y] + 1;
                        max = max > date[nx][ny] ? max : date[nx][ny];
                        q.add(new Dot(nx, ny));
                    }
                }
            }
        }
        v = null;
        outerloop: for (x = 0; x < N; x++) {
            for (y = 0; y < M; y++) {
                if (!visited[x][y] && box[x][y] == 0) {
                    v = new Dot(x, y);
                    break outerloop;
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