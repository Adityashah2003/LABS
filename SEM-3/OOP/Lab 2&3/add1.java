import java.util.*;

class add1 {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("A is: ");
		int a =sc.nextInt();
		System.out.println("B is: ");
		int b = sc.nextInt();
		int c = (a << 2) + (b >> 2);
		System.out.println("C is: "+c);
		boolean d  = (b>0);
		System.out.println("D is: "+d);
		int e = (a+b*100)/10;
		System.out.println("E is: "+e);
		int f = (a&b);
		System.out.println("F is: "+f);

}}