import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int i;
        while (T-- > 0) {
            String[] nk = br.readLine().split(" ");
            int N = Integer.parseInt(nk[0]);
            int K = Integer.parseInt(nk[1]);
            String[] tmpConstruct = br.readLine().split(" ");
            int[] constructTimes = new int[N + 1];
            for (i = 1; i <= N; i++) {
                constructTimes[i] = Integer.parseInt(tmpConstruct[i - 1]);
            }
            ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
            for (i = 0; i < N + 1; i++) {
                graph.add(new ArrayList<Integer>());
            }
            for (i = 0; i < K; i++) {
                String[] vw = br.readLine().split(" ");
                int v = Integer.parseInt(vw[0]);
                int w = Integer.parseInt(vw[1]);
                graph.get(w).add(v);
            }
            int W = Integer.parseInt(br.readLine());
            TopologicalSort ts = new TopologicalSort(W, N, graph, constructTimes);
            ts.run();
        }
    }
}

class TopologicalSort {
    private int W;
    private int N;
    private int[] constructTimes;
    private ArrayList<ArrayList<Integer>> graph;
    private HashSet<Integer> s;
    private boolean[] checked;

    TopologicalSort(int W, int N, ArrayList<ArrayList<Integer>> graph, int[] constructTimes) {
        this.W = W;
        this.N = N;
        this.graph = graph;
        this.constructTimes = constructTimes;
        this.s = new HashSet<>();
        this.checked = new boolean[N + 1];
    }

    void run() {
        int v, time = 0, maxTime;
        HashSet<Integer> tmp = new HashSet<>();
        s.add(W);
        while (!s.isEmpty()) {
            maxTime = 0;
            Iterator<Integer> i = s.iterator();
            tmp.clear();
            while (i.hasNext()) {
                v = i.next();
                if (checked[v]) {
                    continue;
                }
                checked[v] = true;
                maxTime = maxTime > constructTimes[v] ? maxTime : constructTimes[v];
                tmp.addAll(graph.get(v));
            }
            s.clear();
            s.addAll(tmp);
            time += maxTime;
        }
        System.out.println(time);
    }
}