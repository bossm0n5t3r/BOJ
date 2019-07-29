public class Main {
	public static void main(String [] args) {
		Main check = new Main();
		int [] Arr = new int[10000];
		for (int i = 0; i < 10000; i++) {
			Arr[i] = i + 1;
		}
		for (int j = 0; j < 10000; j++) {
			if (check.nextSelfNumber(j+1) <= 10000)
				Arr[check.nextSelfNumber(j+1) - 1] = -1;
		}
		for (int temp:Arr) {
			if (temp > 0)
				System.out.println(temp);
		}
	}

	public int nextSelfNumber(int n) {
		int sum = n;
		do {
			sum += n%10;
			n /= 10;
		} while (n != 0);
		return sum;
	}
}
