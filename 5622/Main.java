import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {
    public static void main (String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String temp = br.readLine();
        String [] templist = temp.split("");
        String [] Dial = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
        int time = 0;
        for (String s : templist) {
            for (int i = 0; i < 9; i++) {
                if (Dial[i].contains(s)) {
                    time += (i + 3);
                    break;
                }
            }
        }
        System.out.println(time);
    }
}
