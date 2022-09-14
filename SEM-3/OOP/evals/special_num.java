import java.util.Scanner;  
public class special_num  
{  
public static void main(String args[])  
{  
	int num, temp, last_digit, sum=0,product=1,finalnum = 0;  
	Scanner sc = new Scanner(System.in);  
	System.out.print("Enter a number: ");    
	num = sc.nextInt();  
	temp = num;  
	while (num > 0){
		last_digit = num % 10;     
		sum = sum + last_digit;		
		product *= last_digit ;
		num = num / 10;
	}
	System.out.println(sum);
	System.out.println(product);
	finalnum = sum+product;
	if(finalnum==temp){
		System.out.println("Special no.");
	}
	else{
		System.out.println("Not Special no.");
	}  
}
}  