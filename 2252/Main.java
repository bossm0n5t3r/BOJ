import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);
        int i;
        int[] cntOfLink = new int[N + 1];
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (i = 0; i < N + 1; i++) {
            graph.add(new ArrayList<Integer>());
        }
        for (i = 0; i < M; i++) {
            String[] vw = br.readLine().split(" ");
            int v = Integer.parseInt(vw[0]);
            int w = Integer.parseInt(vw[1]);
            graph.get(v).add(w);
            cntOfLink[w]++;
        }
        TopologicalSort ts = new TopologicalSort(N, graph, cntOfLink);
        ts.run();
    }
}

class TopologicalSort {
    private int N;
    private int[] cntOfLink;
    private ArrayList<ArrayList<Integer>> graph;
    private Queue<Integer> q;

    TopologicalSort(int N, ArrayList<ArrayList<Integer>> graph, int[] cntOfLink) {
        this.N = N;
        this.graph = graph;
        this.cntOfLink = cntOfLink;
        this.q = new LinkedList<Integer>();
    }

    void run() {
        int i, v;
        for (i = 1; i <= N; i++) {
            if (cntOfLink[i] == 0) {
                q.add(i);
            }
        }
        for (i = 0; i < N; i++) {
            v = q.poll();
            System.out.print(v + " ");
            for (int nextV : graph.get(v)) {
                cntOfLink[nextV]--;
                if (cntOfLink[nextV] == 0) {
                    q.add(nextV);
                }
            }
        }
    }
}