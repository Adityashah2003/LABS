import java.util.*;

class numbers{
	public static void main(String[] args){
		int num,countP = 0,countN=0,countZ=0,i=0;
		Scanner scan = new Scanner(System.in);
		for(i=0;i<=10;i++){
			num= scan.nextInt();
			if(num>0)
		  		countP++;
			else if(num<0)
				countN++;
			else
				countZ++;
		}
		System.out.println("No. of Positive numbers are: "+countP);
		System.out.println("No. of Negative numbers are: "+countN);
		System.out.println("No. of Zeroes numbers are: "+countZ);
}
}