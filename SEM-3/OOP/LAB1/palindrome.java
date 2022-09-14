import java.util.*;

class palindrome{
	public static void main(String[] args){
		int temp,r,n,i;
		int sum=0;
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		temp=n;
		while(n>0){
			r = n%10;
			sum = (sum*10)+r;
			n = n/10;
		}
		if(temp==sum)
			System.out.println("It is a palindrome");
		else
			System.out.println("It is not palindrome");
}
}