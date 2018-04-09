import java.util.Scanner;

public class Pro_1008_Combinationlist {
	static int n, m, k;
	static int[] a, b;
	static boolean check = false;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		a = new int[n + 1];
		b = new int[m + 1];
		for (int i = 1; i < n + 1; i++) {
			a[i] = i;
		}
		for (int i = 1; i < m + 1; i++) {
			b[i] = a[i];
		}
	//	System.out.println(combination(m, n));
		list_combination();
		sc.close();
	}

	public static void list_combination() {
		if (check == false) {
			if (k > combination(m, n)) {
				System.out.print(-1);
				return;
			}
		}
		int rest;
		while (k > 1) {
			int j;
			rest = n - b[m];
			for (j = 1; j < m; j++) {
				if (k < combination(j, rest + j))
					break;
			}
			int l = 0;
			while (k > combination(j - 1, rest + j - 1 - l)) {
				k -= combination(j - 1, rest + j - 1 - l);
				l++;
			}
			for (int o = m - j + 1; o < m + 1; o++) {
				b[o] = b[o] + l;
			}
		}
		for (int i = 1; i < m; i++) {
			System.out.print(b[i] + " ");
		}
		System.out.print(b[m]);
		return;
	}

	// public static int factorial(int x) {
	// if (x == 0)
	// return 1;
	// int factorial = 1;
	// for (int i = 1; i < x + 1; i++) {
	// factorial *= i;
	// }
	// return factorial;
	// }

	public static long combination(int p, int q) {
		if (p == 0)
			return 1;
		if (q == p)
			return 1;
		long x = 1;
		if ((p == m) & (q == n)) {
			for (int i = 1; i < p + 1; i++) {
				x = (q - p + i) * x / i;
				if (x > 10000) {
					check = true;
					return x;
				}
			}
			return x;
		}
		for (int i = 1; i < p + 1; i++) {
			x = (q - p + i) * x / i;
		}
		return x;
	}
}
