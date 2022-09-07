import java.util.*;

/*class four_two {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int i,n,j,m=0;
		for(i=1;i<=5;i++){
			for(j=1;j<=i;j++){
				System.out.print(i);
			}
			System.out.print('\n');
		}
	}
}*/

class four_two {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int arr[]={1,2,3,4,5};
		for(int i : arr){ 
			for(int j=1;j<=i;j++){
				System.out.print(i);
			}
		System.out.print('\n');
	}
}}