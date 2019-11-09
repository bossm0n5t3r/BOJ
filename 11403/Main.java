import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i, N = Integer.parseInt(br.readLine());
        LinkedList<Integer>[] node = new LinkedList[N];
        for (i = 0; i < N; i++) {
            node[i] = new LinkedList<Integer>();
        }
        for (i = 0; i < N; i++) {
            String[] vector = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                if (vector[j].equals("1")) {
                    node[i].add(j);
                }
            }
        }
        StringBuffer sb = new StringBuffer();
        for (i = 0; i < N; i++) {
            String[] visited = new String[N];
            Arrays.fill(visited, "0");
            dfs(node, visited, i);
            sb.append(String.join(" ", visited));
            sb.append("\n");
        }
        System.out.println(sb);
    }

    static String bfs(int N, LinkedList<Integer>[] node, int i) {
        String[] visited = new String[N];
        Arrays.fill(visited, "0");
        Queue<Integer> q = new LinkedList<>();
        q.add(i);
        int v;
        while (!q.isEmpty()) {
            v = q.poll();
            for (int w : node[v]) {
                if (visited[w].equals("0")) {
                    visited[w] = "1";
                    q.add(w);
                }
            }
        }
        String result = String.join(" ", visited);
        return result;
    }

    static void dfs(LinkedList<Integer>[] node, String[] visited, int v) {
        for (int w : node[v]) {
            if (visited[w].equals("0")) {
                visited[w] = "1";
                dfs(node, visited, w);
            }
        }
    }
}