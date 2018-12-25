/*
Stack Sequence

https://www.acmicpc.net/problem/1874
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class BOJ_1874 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));        
        int n = Integer.parseInt(br.readLine());
        int [] data = new int [n];
        for (int i = 0; i < n; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }
        StringBuilder sb = new StringBuilder();
        Stack stack = new Stack(n);
        int input = 1;
        boolean checkContain = false;
        for (int i = 0; i < n; i++) {
            while (input <= data[i]) {
                stack.push(input++);
                sb.append("+\n");
            }

            checkContain = stack.contains(data[i]);

            if (checkContain) {
                while (!stack.empty() && stack.peek() >= data[i]) {
                    stack.pop();
                    sb.append("-\n");
                }
            } else {
                System.out.println("NO");
                return;
            }
        }
        System.out.println(sb);
    }
}

class Stack {
    private int top;
    private int maxSize;
    private int [] stack;

    public Stack (int maxSize) {
        this.top = -1;
        this.maxSize = maxSize;
        this.stack = new int [maxSize];
    }

    public boolean empty() {
        return top == -1;
    }

    public boolean full() {
        return top == maxSize - 1;
    }

    public void push(int item) {
        if (!full()) {
            stack[++top] = item;
        }
    }

    public int peek() {
        int value = stack[top];
        if (empty()) {
            value = 0;
        }
        return value;
    }

    public int pop() {
        int item = peek();
        top--;
        return item;
    }

    public boolean contains(int item) {
        boolean result = false;
        if (!empty()) {
            for (int i = 0; i <= top; i++) {
                if (item == stack[i]) {
                    result = true;
                    break;
                }
            }
        }
        return result;
    }
}
