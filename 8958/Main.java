import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Main main = new Main();
        Scanner sc = new Scanner(System.in);
        int length = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < length; i++) {
            String temp = sc.nextLine();
            System.out.println(main.scoreCase(temp));
        }
        sc.close();
    }
    
    public int scoreCase(String temp) {
        int length = temp.length();
        int [] Arr = new int[length];
        int point = 0;
        int score = 0;
        for (int i = 0; i < length; i++) {
            if (temp.charAt(i) == 'O')
                Arr[point]++;
            else
                point++;
        }
        for (int i : Arr)
            score += i * (i + 1) / 2;
        return score;
    }
}
