import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int i, M, N, K;
        while (T-- > 0) {
            String[] mnk = br.readLine().split(" ");
            M = Integer.parseInt(mnk[0]);
            N = Integer.parseInt(mnk[1]);
            K = Integer.parseInt(mnk[2]);
            int[][] field = new int[M][N];
            for (i = 0; i < K; i++) {
                Dot v = makeDot(br.readLine());
                field[v.x][v.y] = 1;
            }
            Bfs bfs = new Bfs(M, N, field);
            bfs.run();
            /**
             * Dfs dfs = new Dfs(M, N, field); dfs.run();
             */
        }
    }

    static Dot makeDot(String str) {
        String[] tmp = str.split(" ");
        return new Dot(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]));
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
    private int[][] field;
    private boolean[][] visited;
    private Queue<Dot> q;

    Bfs(int M, int N, int[][] field) {
        this.M = M;
        this.N = N;
        this.field = field;
        this.visited = new boolean[M][N];
        this.q = new LinkedList<>();
    }

    void run() {
        int i, x, y, nx, ny, bug = 0;
        int[] dx = { 0, 1, 0, -1 };
        int[] dy = { -1, 0, 1, 0 };
        Dot v = findCabbage();
        while (v != null) {
            bug += 1;
            q.add(v);
            visited[v.x][v.y] = true;
            while (!q.isEmpty()) {
                v = q.poll();
                x = v.x;
                y = v.y;
                for (i = 0; i < 4; i++) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && field[nx][ny] == 1 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.add(new Dot(nx, ny));
                    }
                }
            }
            v = findCabbage();
        }
        System.out.println(bug);
    }

    Dot findCabbage() {
        int i, j;
        Dot v = null;
        outloop: for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    v = new Dot(i, j);
                    break outloop;
                }
            }
        }
        return v;
    }
}

class Dfs {
    private int M;
    private int N;
    private int[][] field;
    private boolean[][] visited;

    Dfs(int M, int N, int[][] field) {
        this.M = M;
        this.N = N;
        this.field = field;
        this.visited = new boolean[M][N];
    }

    void run() {
        int bug = 0;
        Dot v = findCabbage();
        while (v != null) {
            bug += 1;
            dfs(field, visited, v);
            v = findCabbage();
        }
        System.out.println(bug);
    }

    void dfs(int[][] field, boolean[][] visited, Dot v) {
        int i, x, y, nx, ny;
        int[] dx = { 0, 1, 0, -1 };
        int[] dy = { -1, 0, 1, 0 };
        x = v.x;
        y = v.y;
        if (visited[x][y]) {
            return;
        }
        visited[x][y] = true;
        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && field[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(field, visited, new Dot(nx, ny));
            }
        }
    }

    Dot findCabbage() {
        int i, j;
        Dot v = null;
        outloop: for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    v = new Dot(i, j);
                    break outloop;
                }
            }
        }
        return v;
    }
}