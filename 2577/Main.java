import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        int Mul = 1;
        for (int i = 0; i < 3; i++)
            Mul *= sc.nextInt();
        sc.close();
        int [] Arr = new int[10];
        while (Mul > 0) {
            Arr[ Mul % 10 ]++;
            Mul /= 10;
        }
        for (int temp : Arr)
            System.out.println(temp);
    }
}
