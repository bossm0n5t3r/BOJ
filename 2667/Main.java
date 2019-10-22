import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[][] map = new String[N][N];
        int i, j;
        for (i = 0; i < N; i++) {
            map[i] = br.readLine().split("");
        }
        Bfs bfs = new Bfs(N, map);
        bfs.run();
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
    private int N;
    private String[][] map;
    private boolean[][] visited;
    private ArrayList<Integer> houses;
    private Queue<Dot> q;

    Bfs(int N, String[][] map) {
        this.N = N;
        this.map = map;
        this.visited = new boolean[N][N];
        this.houses = new ArrayList<>();
        this.q = new LinkedList<>();
    }

    void run() {
        int[] dx = { 0, 1, 0, -1 };
        int[] dy = { -1, 0, 1, 0 };
        int i, x, y, nx, ny, count;
        Dot v;
        while (check()) {
            v = findNotVisited();
            q.add(v);
            visited[v.x][v.y] = true;
            count = 0;
            while (!q.isEmpty()) {
                v = q.poll();
                x = v.x;
                y = v.y;
                count++;
                for (i = 0; i < 4; i++) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if (!visited[nx][ny] && map[nx][ny].equals("1")) {
                            visited[nx][ny] = true;
                            q.add(new Dot(nx, ny));
                        }
                    }
                }
            }
            houses.add(count);
        }
        Collections.sort(houses);
        System.out.println(houses.size());
        for (int house : houses) {
            System.out.println(house);
        }
    }

    boolean check() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j].equals("1") && !visited[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }

    Dot findNotVisited() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j].equals("1") && !visited[i][j]) {
                    return new Dot(i, j);
                }
            }
        }
        return null;
    }
}