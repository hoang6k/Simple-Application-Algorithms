import java.util.Scanner;
import java.util.Stack;

public class TravelingSalesmanProblem {
	static int n, m, cost = 0, minCost = 1000000;
	static int[][] A;
	static boolean[] a, b;
	static Stack<Integer> route = new Stack<Integer>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		A = new int[n + 1][n + 1];
		for (int i = 1; i < n + 1; i++)
			for (int j = 1; j < n + 1; j++)
				A[i][j] = 1000000;
		for (int i = 0; i < m; i++) {
			int from, to;
			from = sc.nextInt();
			to = sc.nextInt();
			A[from][to] = sc.nextInt();
		}
		a = new boolean[n + 1];
		b = new boolean[n + 1];
		for (int i = 1; i < n + 1; i++) {
			a[i] = true;
			b[i] = true;
		}
		route.push(1);
		TSP(1);
		System.out.print(minCost);
		sc.close();
	}

	public static void TSP(int i) {
		for (int j = 2; j < n + 1; j++) {
			if ((i != j) && (b[j] && checkinf(i, j))) {
				if (minCost < cost + A[i][j])
					continue;
				b[j] = false;
				route.push(j);
				cost += A[i][j];
				if (route.size() < n)
					TSP(j);
				else {
					cost += A[j][1];
					if (cost < minCost) {
						minCost = cost;
					}
					cost -= A[j][1];
				}
				b[j] = true;
				route.pop();
				cost -= A[i][j];
			}
		}
	}

	public static boolean checkinf(int i, int j) {
		if (A[i][j] == 1000000)
			return false;
		else
			return true;
	}
}
