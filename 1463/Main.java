import java.io.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		System.out.println(new Main().compute(N));
	}
	
	public int compute(int data) {
		int [] result = new int [data + 1];
		if(data == 1)
			return 0;
		if (data == 2 || data == 3)
			return 1;
		for (int i = 0; i < result.length; i++) {
			result[i] = 2*data;
		}
		result[1] = 1;
		result[2] = 1;
		result[3] = 1;
		for (int i = 4; i < result.length; i++) {
			boolean [] checkDiv = checkDiv(i);
			for (int j = 0; j < checkDiv.length; j++) {
				if (checkDiv[j]) {
					int temp = 3 - j;
					if (temp != 1)
						result[i] = Math.min(result[i/temp] + 1, result[i]);
					else
						result[i] = Math.min(result[i-1] + 1, result[i]);
				}
			}
		}
		return result[data];
	}
	
	public boolean [] checkDiv(int data) {
		boolean [] result = new boolean [3];
		if (data % 3 == 0)
			result[0] = true;
		if (data % 2 == 0)
			result[1] = true;
		if (data > 1)
			result[2] = true;
		return result;
	}
}
