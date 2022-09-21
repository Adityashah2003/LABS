//Program to display non principal diagonals
//Execution: "java TraceNorm" for Scanner input

import java.util.Scanner;
class MatrixCalculator{


    public static void main(String args[]){
		
        Scanner sc = new Scanner(System.in);
        System.out.println("Program to Input a 2Dimensional Array and then perform Calculations \n");


        // INPUT OF THE ARRAYS : Array A
        int m_a,n_a;

        System.out.println("Input the number of rows and columns respectively for 1st Array");
        m_a = sc.nextInt();
        n_a = sc.nextInt();
        int arr_a[][] = new int[m_a][n_a];

        System.out.println("Input the values one by one");
        for(int i=0;i<m_a;i++)
        {
            for(int j=0;j<n_a;j++)
            {
                System.out.print((i+1) + "," + (j+1) + "\t");
                arr_a[i][j] = sc.nextInt();
            }
        
        }

        // INPUT OF THE ARRAYS : Array B
        int m_b,n_b;

        System.out.println("Input the number of rows and columns respectively for 2nd Array");
        m_b = sc.nextInt();
        n_b = sc.nextInt();
        int arr_b[][] = new int[m_b][n_b];

        System.out.println("Input the values one by one");
        for(int i=0;i<m_b;i++)
        {
            for(int j=0;j<n_b;j++)
            {
                System.out.print((i+1) + "," + (j+1) + "\t");
                arr_b[i][j] = sc.nextInt();
            }
        }

        // PRINT THE GIVEN ARRAYS : Array A
        System.out.println("\nThe A array is: ");
        for(int i=0;i<m_a;i++)
        {
            for(int j=0;j<n_a;j++)
            {
                System.out.print(arr_a[i][j] + "\t");
            }
            System.out.println("");
        } 
        // PRINT THE GIVEN ARRAYS : Array B
        System.out.println("The B array is: ");
        for(int i=0;i<m_b;i++)
        {
            for(int j=0;j<n_b;j++)
            {
                System.out.print(arr_b[i][j] + "\t");
            }
            System.out.println("");
        }


        //Add Integer Matrices
        if(m_a!=m_b | n_a != n_b)
            System.out.println("Matrixes are not of the same dimesnion so cannot find sum");
        else{
        int addend[][] = new int[m_a][n_a];
        for(int i=0;i<m_a;i++)
            for(int j=0;j<n_a;j++)
                addend[i][j] = arr_a[i][j]+arr_b[i][j];
        

        // PRINT THE GIVEN ARRAYS : Array Sum
        System.out.println("The SUM Matrix is: ");
        for(int i=0;i<m_b;i++)
        {
            for(int j=0;j<n_b;j++)
            {
                System.out.print(addend[i][j] + "\t");
            }
            System.out.println("");
        }
        }

        //Multiply Integer Matrices
        if(m_a != n_b)
            System.out.println("Matrix size mismatch");
        else{
        int product[][] = new int[m_a][n_b];
        for(int i=0;i<n_a;i++)
            for(int j=0;j<m_a;j++)
                for(int k=0; k<n_b;k++)
                    product[i][j] += arr_a[i][k] + arr_b[k][j];

        // PRINT THE GIVEN ARRAYS : Array Product
        System.out.println("The PRODUCT Matrix is: ");
        for(int i=0;i<m_b;i++)
        {
            for(int j=0;j<n_b;j++)
            {
                System.out.print(product[i][j] + "\t");
            }
            System.out.println("");
        }
        }
        

    }
}
