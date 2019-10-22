import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = br.readLine().split(" ");
        int N = Integer.parseInt(nk[0]);
        int K = Integer.parseInt(nk[1]);
        if (K <= N) {
            System.out.println(N - K);
        } else {
            Bfs bfs = new Bfs(N, K);
            bfs.run();
        }
    }
}

class Bfs {
    private int N;
    private int K;
    private int[] position;
    private boolean[] visited;
    private Queue<Integer> q;

    Bfs(int N, int K) {
        this.N = N;
        this.K = K;
        this.position = new int[100001];
        this.visited = new boolean[100001];
        this.q = new LinkedList<>();
    }

    void run() {
        int current;
        q.add(N);
        visited[N] = true;
        while (!q.isEmpty()) {
            current = q.poll();
            if (current == K) {
                break;
            }
            if (current - 1 >= 0 && !visited[current - 1]) {
                visited[current - 1] = true;
                position[current - 1] = position[current] + 1;
                q.add(current - 1);
            }
            if (current + 1 <= 100000 && !visited[current + 1]) {
                visited[current + 1] = true;
                position[current + 1] = position[current] + 1;
                q.add(current + 1);
            }
            if (current * 2 <= 100000 && !visited[current * 2]) {
                visited[current * 2] = true;
                position[current * 2] = position[current] + 1;
                q.add(current * 2);
            }
        }
        System.out.println(position[K]);
    }
}