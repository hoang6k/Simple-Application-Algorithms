import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class HoleyQueens {
	static int N, M, count;
	static int[] x, y;
	static boolean[] a, b, c;

	public static void main(String[] args) {
		Queue<Integer> result = new LinkedList<Integer>();
		Scanner sc = new Scanner(System.in);
		do {
			count = 0;
			N = sc.nextInt();
			M = sc.nextInt();
			if (N == 0 && M == 0)
				break;
			x = new int[M];
			y = new int[M];
			a = new boolean[N];
			b = new boolean[2 * N - 1];
			c = new boolean[2 * N - 1];
			for (int i = 0; i < M; i++) {
				x[i] = sc.nextInt();
				y[i] = sc.nextInt();
			}
			for (int i = 0; i < N; i++)
				a[i] = true;
			for (int i = 0; i < 2 * N - 1; i++) {
				b[i] = true;
				c[i] = true;
			}
			result.add(holeyqueens(0));
		} while (true);
		while (!result.isEmpty())
			System.out.println(result.poll());
		sc.close();
	}

	public static int holeyqueens(int i) {
		for (int j = 0; j < N; j++) {
			if (a[j] && b[i + j] && c[i - j + N - 1] && checkhole(i, j)) {
				a[j] = false;
				b[i + j] = false;
				c[i - j + N - 1] = false;
				if (i < N - 1)
					holeyqueens(i + 1);
				else
					count++;
				a[j] = true;
				b[i + j] = true;
				c[i - j + N - 1] = true;
			}
		}
		return count;
	}

	public static boolean checkhole(int i, int j) {
		for (int k = 0; k < M; k++) {
			if (x[k] == i + 1 && y[k] == j + 1)
				return false;
		}
		return true;
	}
}
