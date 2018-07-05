/*
Sorting words
By Using ArrayList

https://www.acmicpc.net/problem/1181
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Collections;
import java.util.ArrayList;
import java.util.HashSet;

class BOJ_1181 {
    public static void main(String[] args) throws IOException {
        new SortingWordsAL().run();
    }
}
class SortingWordsAL {
    public void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList <String> data = new ArrayList <String> ();
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            data.add(br.readLine());
        }
        ArrayList <String> cleanData = removeDuplicates(data);
        ArrayList <ArrayList <String>> dataByLen = splitByLength(cleanData);
        for (ArrayList <String> item : dataByLen) {
            Collections.sort(item);
            for (String inItem : item) {
                System.out.println(inItem);
            }
        }
    }
    public ArrayList <String> removeDuplicates(ArrayList <String> data) {
        ArrayList <String> result = new ArrayList <String> ();
        HashSet <String> set = new HashSet <String> ();
        for (String item : data) {
            if(!set.contains(item)) {
                result.add(item);
                set.add(item);
            }
        }
        return result;
    }
    public ArrayList <ArrayList <String>> splitByLength(ArrayList <String> data) {
        ArrayList <ArrayList <String>> result = new ArrayList <ArrayList <String>> ();
        int maxLength = 0;
        for (String item : data) {
            if (maxLength < item.length()) {
                maxLength = item.length();
            }
        }
        for (int i = 0; i < maxLength; i++) {
            result.add(new ArrayList <String> ());
        }
        for (String item : data) {
            int len = item.length();
            result.get(len - 1).add(item);
        }
        return result;
    }
}