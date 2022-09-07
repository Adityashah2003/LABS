import java.util.*;

class four_one {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no: ");
		int n =sc.nextInt();
		int r,sum = 0;
		int temp = n;
		while(n>0){
			r = n%10;
			sum = sum +(r*r*r);
			n = n/10;
		}
		if(temp ==sum){
			System.out.println("Armstrong ");
		}
		else{
			System.out.println("no armstrong");
		}
	}
}