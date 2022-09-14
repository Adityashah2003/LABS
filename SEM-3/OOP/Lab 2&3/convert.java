import java.util.*;
class convert{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int n=0;
		double d=0;
		char c;
		n= scan.nextInt();
		d= scan.nextDouble();
		c= scan.next().charAt(0);
		byte b1=0;
		int n1=0;
		float f1=0;
		byte b2=0;
		double d1=0;
		int c1;
		b1 = (byte)n;
		c1 = c;
		b2 = (byte) d;
		n1 = (int)d;
		System.out.println("int to byte: " +b1 );
		System.out.println("char to int: " + c1);
		System.out.println("double to byte: " +b2 );
		System.out.println("double to int: " + n1);
	}
}