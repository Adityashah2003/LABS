import java.util.*;

class add2 {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("A is: ");
		int a =sc.nextInt();
		System.out.println("B is: ");
		int b = sc.nextInt();
		System.out.println("C is: " );
		int c = sc.nextInt();
		int max = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
		System.out.println("Largest is:"+max);

		
		
}}