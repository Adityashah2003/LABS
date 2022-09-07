import java.util.*;

class add_three {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int i,n,j=0;
		int a=1;
		for(i=1;i<5;i++){
			for(j=1;j<i+1;j++){
				System.out.print(a+" ");
				a++;
			}
			System.out.println();
		}
	}
}