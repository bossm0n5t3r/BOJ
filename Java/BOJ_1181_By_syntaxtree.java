/*
Sorting words

https://www.acmicpc.net/problem/1181

THIS FILE IS COPYED
ORIGINAL : https://www.acmicpc.net/source/3418033
CREATED BY : syntaxtree (B.O.J. ID)
(You can see this link if you already solved this problem)
(If there is a problem with copyright, I will delete this file)
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

class BOJ_1181_By_syntaxtree {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        int N = Integer.parseInt(br.readLine());
        Words [] data = new Words [N];
        for (int i = 0; i < data.length; i++) {
            data[i] = new Words(br.readLine());
        }
        Arrays.sort(data);
        String before = "";
        for (int i = 0; i < data.length; i++) {
            String temp = data[i].getWord();
            if (!before.equals(temp)) {
                sb.append(temp + "\n");
                before = temp;
            }
        }
        System.out.println(sb.toString());
    }
}
class Words implements Comparable <Words> {
    private String word;

    public Words(String word) {
        this.word = word;
    }

    public String getWord() {
        return this.word;
    }

    public int compareTo(Words o) {
        int thisLen = this.word.length();
        int inputLen = o.getWord().length();

        if (thisLen < inputLen) {
            return -1;
        } else if (thisLen > inputLen) {
            return 1;
        } else {
            return this.word.compareTo(o.getWord());
        }
    }
}