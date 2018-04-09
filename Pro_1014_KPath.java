import java.util.*;

public class Pro_1014_KPath {
	static int n, m, k, _count = 0, over = 0, u, v, start;
	static int[][] A;
	static boolean[] cols;
	static Stack<Integer> path = new Stack<Integer>();

	public static void main(String[] args) {
		initialize();
		KPath(0);
		System.out.println(_count);
	}

	public static void initialize() {
		path.push(0);
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		m = sc.nextInt();
		A = new int[n + 1][n + 1];
		for (int i = 0; i < n + 1; i++) {
			if (i == 0)
				for (int j = 0; j < n + 1; j++)
					A[i][j] = 1;
			else
				for (int j = 0; j < n + 1; j++)
					A[i][j] = 0;
		}
		cols = new boolean[n + 1];
		for (int i = 1; i < n + 1; i++)
			cols[i] = true;
		for (int i = 1; i < m + 1; i++) {
			u = sc.nextInt();
			v = sc.nextInt();
			A[u][v] = 1;
			A[v][u] = 1;
		}
		sc.close();
	}

	public static void KPath(int x) {
		int rdt = 0;
		if (x == 0)
			rdt = 1;
		for (int i = 1; i < n + 1 - rdt; i++)
			if (cols[i] && A[x][i] != 0) {
				if (x == 0) {
					start = i;
				}
				if (start < n - k + 1) {
					path.push(i);
					cols[i] = false;
					if (path.size() - 2 < k) {
						KPath(i);
						path.pop();
						cols[i] = true;
					} else {
						if (start < path.peek()) {
							_count++;
						}
						path.pop();
						cols[i] = true;
					}
				} else {
					if (i > start && ++over >= k - 1 && path.size() - 1 < k) {
						over--;
						continue;
					}
					path.push(i);
					cols[i] = false;
					if (path.size() - 2 < k) {
						KPath(i);
						path.pop();
						cols[i] = true;
					} else {
						if (start < path.peek()) {
							_count++;
						}
						path.pop();
						cols[i] = true;
					}
					if (i > start)
						over--;
				}
			}
	}
}
