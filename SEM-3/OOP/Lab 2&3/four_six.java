import java.util.*;

class four_six {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter m: ");
		int m =sc.nextInt();
		System.out.println("Enter n: ");
		int n =sc.nextInt();
		int i,j,flag = 0;
		for (i = m; i <= n; i++) 
        {
            if (i == 1 || i == 0)
                continue;
            flag = 1;
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                System.out.println(i);
        }
	}
}