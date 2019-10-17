import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Iterator;
import java.util.ListIterator;
import java.util.Collections;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nmv = br.readLine().split(" ");
        int N = Integer.parseInt(nmv[0]);
        int M = Integer.parseInt(nmv[1]);
        int V = Integer.parseInt(nmv[2]);
        Graph g = new Graph(N);
        for (int i = 0; i < M; i++) {
            String[] tmp = br.readLine().split(" ");
            int v = Integer.parseInt(tmp[0]);
            int w = Integer.parseInt(tmp[1]);
            g.addEdge(v, w);
        }
        g.sort();
        Dfs d = new Dfs(g, N, V);
        d.run();
        System.out.println();
        Bfs b = new Bfs(g, N, V);
        b.run();
    }
}

class Graph {
    private int N;
    private LinkedList<Integer>[] adj;

    Graph(int N) {
        this.N = N;
        adj = new LinkedList[N + 1];
        for (int i = 1; i <= N; ++i) {
            adj[i] = new LinkedList<Integer>();
        }
    }

    void addEdge(int v, int w) {
        adj[v].add(w);
        adj[w].add(v);
    }

    void sort() {
        for (int i = 1; i <= N; i++) {
            Collections.sort(adj[i]);
        }
    }

    ListIterator<Integer> adj(int v) {
        return adj[v].listIterator();
    }
}

class Bfs {
    private Graph g;
    private int N;
    private int V;
    private boolean[] visited;
    private Queue<Integer> q;

    Bfs(Graph g, int N, int V) {
        this.g = g;
        this.N = N;
        this.V = V;
        this.q = new LinkedList<Integer>();
    }

    void run() {
        visited = new boolean[N + 1];
        visited[V] = true;
        q.add(V);
        while (!q.isEmpty()) {
            V = q.poll();
            System.out.print(V + " ");
            Iterator<Integer> i = g.adj(V);
            while (i.hasNext()) {
                int n = i.next();
                if (!visited[n]) {
                    visited[n] = true;
                    q.add(n);
                }
            }
        }
    }
}

class Dfs {
    private Graph g;
    private int N;
    private int V;
    private boolean[] visited;

    Dfs(Graph g, int N, int V) {
        this.g = g;
        this.N = N;
        this.V = V;
    }

    void run() {
        visited = new boolean[N + 1];
        dfs(V, visited);
    }

    void dfs(int v, boolean[] visited) {
        visited[v] = true;
        System.out.print(v + " ");
        Iterator<Integer> i = g.adj(v);
        while (i.hasNext()) {
            int n = i.next();
            if (!visited[n]) {
                dfs(n, visited);
            }
        }
    }
}