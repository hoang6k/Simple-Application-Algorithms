import java.util.Scanner;

public class Pro_1006_Binarylist {
	static int n, k, i, count = 0, flag = 0, _count_ = 0;
	static int[] a;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		i = sc.nextInt();
		a = new int[n];
		binary(0);
		if (count < k)
			System.out.print(-1);
		sc.close();
	}

	public static void binary(int x) {
		for (int l = 0; l < 2; l++) {
			if (l == 0)
				_count_++;
			else
				_count_ = 0;
			if (_count_ == i)
				continue;
			a[x] = l;
			if (flag == 1)
				return;
			if (x < n - 1) {
				binary(x + 1);
				if (flag == 1)
					return;
				continue;
			}
			if (check(a))
				count++;
			if (count == k) {
				for (int z = 0; z < a.length - 1; z++)
					System.out.print(a[z] + " ");
				System.out.print(a[a.length - 1]);
				flag = 1;
			}
		}
	}

	public static boolean check(int[] a) {
		int j = 0, _count = 0;
		while ((_count < i) && (j < a.length)) {
			if (a[j] == 0)
				_count++;
			else
				_count = 0;
			j++;
		}
		if (_count == i)
			return false;
		else
			return true;
	}
}
