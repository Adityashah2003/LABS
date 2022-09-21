//Program to display non principal diagonals
//Execution: "java MagicSquare" for Scanner input

import java.util.Scanner;
class MagicSquare{


    public static void main(String args[]){
		
        Scanner sc = new Scanner(System.in);
        System.out.println("Program to Input a 2Dimensional Array and check if it is a Magic Square \n");


        // INPUT OF THE ARRAYS
        int m,n;

        System.out.println("Input the number of rows and columns respectively for 1st Array");
        m = sc.nextInt();
        n = sc.nextInt();
        int arr[][] = new int[m][n];

        System.out.println("Input the values one by one");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print((i+1) + "," + (j+1) + "\t");
                arr[i][j] = sc.nextInt();
            }
        
        }

        // PRINT THE GIVEN ARRAYS : Array A
        System.out.println("\nThe A array is: ");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(arr[i][j] + "\t");
            }
            System.out.println("");
        } 

        // PROGRAM LOGIC
        
        int row = 0, row_prv = 0, col = 0, col_prv = 0, diag_a = 0, diag_b = 0;

        OUTER:
            for(int i=0; i<m; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        row += arr[i][j];
                        col += arr[j][i];
                        if(i==j)    diag_a += arr[i][j];
                        if(i+j==n-1) diag_b += arr[i][j];
                    } 
                    System.out.println(row +" "+col);
                    if(row != col)  break OUTER;
                    if(i>0) if(row != row_prv | col != col_prv) break OUTER;
                    row_prv = row; col_prv = col;
                    row = col = 0;

                }
                System.out.println(diag_a +" "+diag_b);
                if(diag_a == diag_b && diag_a == row_prv)
                    System.out.println("MAGIC SQUARE!!");
                else System.out.println("not a magic square");

        //Symmetricity check
        int flag = 1;
        for(int i = 0; i<m ;i++)
                for(int j=0; j<n; j++)
                    if(arr[i][j]!=arr[j][i]) flag = 0;

        if (flag==1)
            System.out.println("SYMMETRIC!!");
        else 
            System.out.println("not symmetric");
    } 
}


