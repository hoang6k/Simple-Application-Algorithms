import java.util.Scanner;

public class Permutationlist {
	static int n, k;
	static int[] a;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		permutation();
		sc.close();
	}

	public static void permutation() {
		if ((n < 13) && (factorial(n) < k)) {
			System.out.println(-1);
			return;
		}
		int i, num, temp, limit;
		int[] a = new int[n + 1];
		for (i = 1; i < n + 1; i++)
			a[i] = i;
		while (k > 1) {
			limit = check(k);
			num = (k - 1) / factorial(limit - 1);
			k -= num * factorial(limit - 1);
			temp = a[n - limit + 1 + num];
			for (i = n - limit + 1 + num; i > n - limit + 1; i--) {
				a[i] = a[i - 1];
			}
			a[n - limit + 1] = temp;
		}
		for (i = 1; i < n; i++)
			System.out.print(a[i] + " ");
		System.out.print(a[n]);
		return;
	}

	public static int factorial(int x) {
		if (x == 0)
			return 1;
		int f = 1;
		for (int i = 1; i < x + 1; i++)
			f = f * i;
		return f;
	}

	public static int check(int x) {
		if (x == 1)
			return 0;
		int i = 1;
		while (!((factorial(i) < x) && (x < factorial(i + 1) + 1)))
			i++;
		return i + 1;
	}
}
