/*
 *  Studying words
 *
 *  https://www.acmicpc.net/problem/1157
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class BOJ_1157 {
    public static void main (String [] args) throws IOException {
        BOJ_1157 main = new BOJ_1157();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String temp = br.readLine();

        int diffLetter = main.getDiffLetter(temp);

        String [][] save = main.sortString(temp, diffLetter);

        int [] numList = new int [diffLetter];

        for (int i = 0; i < diffLetter; i++) {
            numList[i] = Integer.parseInt(save[i][1]);
        }

        int [] checkMaxIndex = main.getIndexOfLargest(numList, diffLetter);
        if (checkMaxIndex[1] > 1) {
            System.out.println("?");
        } else {
            System.out.println(save[checkMaxIndex[0]][0]);
        }
    }

    String [][] sortString (String temp, int diffLetter) {

        temp = temp.toUpperCase();

        if (temp.length() == 1) {
            String [][] save = {{temp, "1"}};
            return save;
        }

        String [] templist = temp.split("");

        Arrays.sort(templist);

        String [][] record = new String [diffLetter][2];

        int point = 0;
        int count = 1;

        for (int i = 0; i < templist.length - 1; i++) {
            if (templist[i].equals(templist[i+1])) {
                count++;
                if ( i == templist.length - 2 ) {
                    String [] ttemp = {templist[i], String.valueOf(count)};
                    record[point] = ttemp;
                }
            } else {
                String [] tttemp = {templist[i], String.valueOf(count)};
                record[point] = tttemp;
                point++;
                count = 1;
                if ( i == templist.length - 2 ) {
                    String [] ttttemp = {templist[i+1], "1"};
                    record[point] = ttttemp;
                }
            }
        }

        return record;
    }

    int [] getIndexOfLargest (int[] array, int diffLetter) {
        int [] save = new int [2];
        if ( array == null || array.length == 0 ) {
            save[0] = save[1] = -1;
            return save;
        }

        int index = 0;

        for (int i = 1; i < array.length; i++) {
            if ( array[i] > array[index] ) {
                index = i;
            }
        }
        save[0] = index;
        int count = 1;

        for (int i = 0; i < array.length; i++) {
            if (i != index) {
                if (array[i] == array[index]) {
                    count++;
                }
            }
        }
        save[1] = count;
        return save;
    }

    int getDiffLetter (String temp) {
        temp = temp.toUpperCase();
        String [] templist = temp.split("");
        Arrays.sort(templist);
        int length = 1;
        for (int i = 1; i < temp.length(); i++) {
            if (!templist[i].equals(templist[i-1])) {
                length++;
            }
        }
        return length;
    }
}
