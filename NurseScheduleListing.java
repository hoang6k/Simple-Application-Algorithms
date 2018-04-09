import java.util.Scanner;

public class NurseScheduleListing {
	static int n, k1, k2;
	static int[] a;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k1 = sc.nextInt();
		k2 = sc.nextInt();
		a = new int[n + 1];
		a[0] = 1;
		nurseschedule(1);
		sc.close();
	}

	public static void nurseschedule(int x) {
		for (int i = 0; i < 2; i++) {
			a[x] = i;
			if (a[x] == 0) {
				if (a[x - 1] == 0)
					continue;
				else {
					if (x > 1)
						if (check(x - 1))
							continue;
					if (x < n)
						nurseschedule(x + 1);
					else {
						for (int j = 1; j < n + 1; j++)
							System.out.print(a[j]);
						System.out.println();
					}
				}
			} else {
				if (checkover(x) && (x != 1))
					continue;
				if (x < n)
					nurseschedule(x + 1);
				else {
					if (!check(x)) {
						for (int j = 1; j < n + 1; j++)
							System.out.print(a[j]);
						System.out.println();
					}
				}
			}
		}
	}

	public static boolean checkover(int x) {
		int _count_ = 0;
		for (int j = x; j > 0; j--) {
			if (a[j] == 1) {
				if (_count_++ > k2)
					return true;
			} else
				break;
		}
		if (_count_ > k2)
			return true;
		else
			return false;
	}

	public static boolean check(int x) {
		int _count_ = 0;
		for (int j = x; j > 0; j--) {
			if (a[j] == 1) {
				if (_count_++ > k2)
					return true;
			} else
				break;
		}
		if ((_count_ < k1) || (_count_ > k2))
			return true;
		else
			return false;
	}
}
