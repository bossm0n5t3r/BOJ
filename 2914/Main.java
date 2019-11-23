import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputNumbers = br.readLine().split(" ");
        int A = Integer.parseInt(inputNumbers[0]);
        int I = Integer.parseInt(inputNumbers[1]);
        System.out.println((A * (I - 1)) + 1);
    }
}