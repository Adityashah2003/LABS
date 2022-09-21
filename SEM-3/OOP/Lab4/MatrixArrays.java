//Program to display non principal diagonals
//Execution: "java MatrixArrays" for Scanner input

import java.util.Scanner;
class MatrixArrays{


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

        int diag_sum = 0;
        System.out.println("The DIAGONAL array is: ");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    System.out.print(arr[i][j] + "\t");
                    diag_sum += arr[i][j];
                }
                else 
                System.out.print("   ");
            }
            System.out.println("");
            
        }
        System.out.println("The sum of the Diagonal Elements are " + diag_sum);
            

        // PRINT THE NON DIAGONAL ARRAY

            int secdiag_sum = 0;
            System.out.println("The SECONDARY DIAGONAL array is: ");
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if( (i+m-1 == j) | (i-m+1 == j) | i==j)
                    {
                        System.out.print(arr[i][j] + "\t");
                        secdiag_sum += arr[i][j];
                    }
                    else 
                    System.out.print("  \t");
                }
                System.out.println("");
                
            }
            System.out.println("The sum of the Secondary Diagonal Elements are " + secdiag_sum);
                

            
            int nondiag_sum = 0;
            System.out.println("The NON DIAGONAL array is: ");
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if( i!=0 || j!= 0 || j!=n-1 || i!= n-1)
                    {
                        System.out.print(arr[i][j] + "\t");
                        nondiag_sum += arr[i][j];
                    }
                    else 
                    System.out.print("  \t");
                }
                System.out.println("");
                
            }
            System.out.println("The sum of the Secondary Diagonal Elements are " + nondiag_sum);
                


        
						}
			}



