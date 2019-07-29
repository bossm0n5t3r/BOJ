import java.io.IOException;

class Main {
    public static void main (String [] args) throws IOException {
        int [] count = new int [26];
        for (int c = System.in.read(); c >= 65; c = System.in.read()) {
            count[Character.toLowerCase(c) - 'a']++;
        }
        int index = 0;
        boolean isDuplicate = false;
        for (int max = count[0], i = 1; i < 26; i++) {
            if (count[i] > max) {
                max = count[i];
                index = i;
                isDuplicate = false;
            } else if (count [i] == max) {
                isDuplicate = true;
            }
        }
        if (isDuplicate) {
            System.out.println("?");
        } else {
            System.out.println((char)(index + 'A'));
        }
    }
}
