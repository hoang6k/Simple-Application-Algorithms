import java.util.Scanner;
public class Pro_1004_SubseqMax {
	static int n;
	static int[] a;
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		n=sc.nextInt();
		a=new int[n];
		for(int k=0;k<n;k++) {
			a[k]=sc.nextInt();
		}
//		n=Integer.parseInt(sc.nextLine());
//		a=new int[n];
//		String s=sc.nextLine();
//		String[] _s=s.split(" ");
//		for(int k=0;k<n;k++) {
//			a[k]=Integer.parseInt(_s[k]);
//		}
		subsequence();
		sc.close();
	}
	public static void subsequence() {
		int i=0;
		int[] s=new int[n];
		s[0]=a[0];
		int max=s[0];
		for(i=1;i<n;i++) {
			if(s[i-1]>0) s[i]=s[i-1]+a[i];
			else s[i]=a[i];
			max=max>s[i]?max:s[i];
		}
		System.out.print(max);
	}
}
