import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            Main.checkParentheis(br.readLine());
        }
    }

    public static void checkParentheis(String input) {
        int length = input.length();
        int index = -1;
        while (length > 0) {
            index = input.indexOf("()");
            if (index != -1) {
                input = input.substring(0, index) + input.substring(index + 2, length);
                length = input.length();
            } else {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
