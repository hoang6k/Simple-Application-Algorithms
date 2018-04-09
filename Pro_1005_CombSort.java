import java.util.Scanner;

public class Pro_1005_CombSort {
	static int n;
	static float[] a;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		a = new float[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextFloat();
		}
		combsort(a);
		sc.close();
	}

	public static void combsort(float[] a) {
		int gap = a.length - 1;
		double shrink = 1.3;
		boolean sorted = false;
		while (!sorted) {
			if (gap == 1) {
				sorted = true;
			}
			int i = 0;
			while (i + gap < a.length) {
				if (a[i] > a[i + gap]) {
					float temp = a[i];
					a[i] = a[i + gap];
					a[i + gap] = temp;
					sorted = false;
				}
				i++;
			}
			gap /= shrink;
			System.out.println(gap);
		}
		System.out.printf("%.2f", a[0]);
		for (int i = 1; i < a.length; i++) {
			System.out.printf(" %.2f", a[i]);
		}
	}
}
