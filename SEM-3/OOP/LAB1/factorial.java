import java.util.*;

class factorial{
	public static void main(String[] args){
	int num,i;
	int fact=1;
	Scanner scan = new Scanner(System.in);
	num = scan.nextInt();
	for(i=1;i<=num;i++)
		fact = fact*i;
	System.out.println(fact);
}
}
