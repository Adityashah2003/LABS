import java.util.*;

class calc {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		char lmao;
		System.out.println("Enter number 1: ");
		int a =sc.nextInt();
		System.out.println("Enter the function you want to use: ");
		char operator = sc.next().charAt(0);
		System.out.println("next no is: " );
		int b = sc.nextInt();
		double additon,subtraction,multiplication,divison=0;
		do{
			switch(operator){
				case '+':
				{
					System.out.println("Addition of a+b is: "+ (a+b));
					break;
				}
				case '-':
				{
					System.out.println("Subtraction of a&b is: "+ (a-b));
					break;
				}
				case '*':
				{
					System.out.println("Multiplication of a&b is: "+ (a*b));
					break;
				}
				case '/':
				{
					System.out.println("division of a&b is: "+ (a/b));
					break;
				}
				default:
				{
					System.out.println("Enter a valid operator");
					break;
				}
			}
			System.out.println("Type n to stop or y to continue" );
			lmao = sc.next().charAt(0);
		}while(lmao != 'n');
		
}
}
