import java.util.Scanner;  
class pattern_exam{  
public static void main(String args[])  
{  
	int rows, i,j,k=0;
	int count=1;  
	Scanner sc = new Scanner(System.in);  
	System.out.print("Enter a number: ");    
	rows = sc.nextInt();
	for(i=0;i<=rows;i++){
		if(i%2!=0){
			for(j=1;j<=i;j++){
					System.out.print(j*i+" ");
			}System.out.println();
			/*for(k=i;k<=i;k++){
					System.out.print(k*i+" ");
				}*/
		}
	}
}
}
