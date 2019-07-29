import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] data = br.readLine().split("");
        Stack<String> stack = new Stack<String>();
        int sum = 0;
        // 중간에 괄호가 제대로 닫히지 않은 경우을 체크
        int check = 0;
        
        for (int i = 0; i < data.length; i++) {
            // 괄호가 제대로 닫히지 않은 경우 0
            if (check == -1) {
                System.out.println(0);
                return;
            }

            String tmp = data[i];
            if ("(".equals(tmp) || "[".equals(tmp)) {
                stack.push(tmp);                
            } else {
                // 열지도 않았는데, 닫기부터 시작한 경우 0
                if (stack.isEmpty()) {
					System.out.println(0);
					return;
				}
                if (")".equals(tmp)) {
                    String last = stack.peek();
                    if ("(".equals(last)) {
                        stack.pop();
                        stack.push("2");
                    } else {
                        check = stackInnerLoop(stack, "(", "[", 2);
                    }
                } else {
                    String last = stack.peek();
                    if ("[".equals(last)) {
                        stack.pop();
                        stack.push("3");
                    } else {
                        check = stackInnerLoop(stack, "[", "(", 3);
                    }
                }
            }
        }
        
        while (!stack.empty()) {
            String top = stack.peek();
            if ("(".equals(top) || ")".equals(top) || "[".equals(top) || "]".equals(top)) {
                System.out.println(0);
                return;
            }
            sum += Integer.parseInt(stack.pop());
        }
        System.out.println(sum);
    }

    public static int stackInnerLoop(Stack<String> stack, String correct, String wrong, int value) {
        int result = 0;

        while (!stack.empty()) {
            String top = stack.peek();
            // 열고 닫는게 다른 경우
            if (wrong.equals(top)) {
                return -1;
            // 열고 닫는게 같은 경우
            } else if (correct.equals(top)) {
                result *= value;
                stack.pop();
                stack.push(result + "");
                break;
            // 괄호안의 숫자인 경우
            } else {
                result += Integer.parseInt(stack.pop());
            }
        }

        return result;
    }
}
