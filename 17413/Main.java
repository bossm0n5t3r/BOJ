import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String S = br.readLine();
        Queue<Character> q = new LinkedList<Character>();
        Stack<Character> s = new Stack<Character>();
        for (int i = 0; i < S.length(); i++) {
            char tmp = S.charAt(i);
            if (tmp == '<') {
                while (!s.empty()) {
                    sb.append(s.pop());
                }
                q.add(tmp);
                for (int j = i + 1; j < S.length(); j++) {
                    char tagInside = S.charAt(j);
                    if (tagInside == '>') {
                        q.add(tagInside);
                        i = j;
                        break;
                    } else {
                        q.add(tagInside);
                    }
                }
                while (!q.isEmpty()) {
                    sb.append(q.poll());
                }
            } else {
                if (tmp != ' ') {
                    s.add(tmp);
                } else {
                    while (!s.empty()) {
                        sb.append(s.pop());
                    }
                    sb.append(tmp);
                }
            }
        }
        while (!s.empty()) {
            sb.append(s.pop());
        }
        System.out.println(sb);
    }
}