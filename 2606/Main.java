import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int T = Integer.parseInt(br.readLine());
        int i;
        ArrayList<ArrayList<Integer>> node = new ArrayList<>();
        for (i = 0; i <= N; i++) {
            node.add(new ArrayList<Integer>());
        }
        for (i = 0; i < T; i++) {
            String[] vw = br.readLine().split(" ");
            int v = Integer.parseInt(vw[0]);
            int w = Integer.parseInt(vw[1]);
            node.get(v).add(w);
            node.get(w).add(v);
        }
        Bfs bfs = new Bfs(N, node);
        bfs.run();
    }
}

class Bfs {
    private ArrayList<ArrayList<Integer>> node;
    private Queue<Integer> q;
    private boolean[] checked;

    Bfs(int N, ArrayList<ArrayList<Integer>> node) {
        this.node = node;
        this.q = new LinkedList<>();
        this.checked = new boolean[N + 1];
    }

    void run() {
        q.add(1);
        checked[1] = true;
        int count = -1;
        while (!q.isEmpty()) {
            int v = q.poll();
            count++;
            for (int i : node.get(v)) {
                if (!checked[i]) {
                    checked[i] = true;
                    q.add(i);
                }
            }
        }
        System.out.println(count);
    }
}