import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i, k;
        while (true) {
            String[] input = br.readLine().split(" ");
            k = input.length - 1;
            if (k == 0) {
                break;
            }
            int[] candidates = new int[k];
            for (i = 1; i <= k; i++) {
                candidates[i - 1] = Integer.parseInt(input[i]);
            }
            boolean[] visited = new boolean[k];
            combination(candidates, visited, 0, k, 6);
            System.out.println();
        }
    }

    static void combination(int[] candidates, boolean[] visited, int start, int end, int r) {
        if (r == 0) {
            for (int i = 0; i < end; i++) {
                if (visited[i]) {
                    System.out.print(candidates[i] + " ");
                }
            }
            System.out.println();
            return;
        }
        for (int i = start; i < end; i++) {
            visited[i] = true;
            combination(candidates, visited, i + 1, end, r - 1);
            visited[i] = false;
        }
    }
}