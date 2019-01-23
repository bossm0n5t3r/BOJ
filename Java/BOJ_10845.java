/*
Queue

https://www.acmicpc.net/problem/10845
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

class BOJ_10845 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Queue queue = new Queue();
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            if (input.length == 2) {
                queue.push(Integer.parseInt(input[1]));
            } else {
                if ("pop".equals(input[0])) {
                    System.out.println(queue.pop());
                } else if ("size".equals(input[0])) {
                    System.out.println(queue.size());
                } else if ("empty".equals(input[0])) {
                    System.out.println(queue.empty());
                } else if ("front".equals(input[0])) {
                    System.out.println(queue.front());
                } else if ("back".equals(input[0])) {
                    System.out.println(queue.back());
                }
            }
        }
    }

    public static class Queue {
        private List<Integer> queue;
        
        public Queue() {
            this.queue = new ArrayList<Integer>();
        }

        public void push(int X) {
            queue.add(X);
        }

        public int pop() {
            int result = -1;
            if (!queue.isEmpty()) {
                result = queue.get(0);
                queue.remove(0);
            }
            return result;
        }

        public int size() {
            return queue.size();
        }

        public int empty() {
            if (queue.size() == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        public int front() {
            int result = -1;
            if (!queue.isEmpty()) {
                result = queue.get(0);
            }
            return result;
        }

        public int back() {
            int result = -1;
            if (!queue.isEmpty()) {
                result = queue.get(queue.size() - 1);
            }
            return result;
        }
    }
}