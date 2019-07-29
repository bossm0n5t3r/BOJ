import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        String temp = sc.nextLine();
        if (temp != null && temp.trim().length() > 0) {
            String [] Arr = temp.trim().split(" ");
            System.out.println(Arr.length);
        } else
            System.out.println(0);
        sc.close();
    }
}
