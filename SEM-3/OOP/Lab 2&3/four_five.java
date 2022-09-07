import java.util.*;

class four_five {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter search value: ");
		int n = sc.nextInt();
		int arr[]={10,20,30,10,20,10,50,60,70};
		int j=0;
		for (int i:arr){
			if(i == n){
				System.out.println("value found "+ j );
			}
			j++;
		}
	}
}