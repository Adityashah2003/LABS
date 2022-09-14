import java.util.*;
class leap{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int year,i;
		Boolean leap=false;
		year = scan.nextInt();
		if (year %4 ==0 && year%100!=0 || year%400==0)
			leap = true;
		else
			leap = false;
		System.out.println(leap);
	}
}