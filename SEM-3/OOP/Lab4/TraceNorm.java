//Program to display non principal diagonals
//Execution: "java MatrixArrays" for Scanner input

import java.util.Scanner;
class TraceNorm{


    public static void main(String args[]){
		
        Scanner sc = new Scanner(System.in);
        System.out.println("Program to Display NonPrincipalDiagonals and then Find their sum \n");


        // INPUT OF THE NUMBER

        int m,n;
        int arr[][] = new int[10][10];

        System.out.println("Input the number of rows and columns respectively");
        m = sc.nextInt();
        n = sc.nextInt();

        System.out.println("Input the values one by one");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.println("Enter value for the position " + (i+1) + "," + (j+1) );
                arr[i][j] = sc.nextInt();
            }
        }

        // PRINT THE GIVEN ARRAY
        System.out.println("The given array is: ");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(arr[i][j] + "\t");
            }
            System.out.println("");
        }

        // PRINT THE DIAGONAL ARRAY

        int trace = 0, norm = 0;

        for(int i=0;i<m;i++)
          for(int j=0;j<n;j++)
            {
                if(i==j)
                  trace += arr[i][j];
                norm = (norm + ( arr[i][j]*arr[i][j] ));
            }
            
        System.out.println("The Trace of the matrix is " + trace +"\n The Norm of the matrix is " + norm);

        
						}
			}



