
import java.util.Scanner;
class PrimeArray{

  public static boolean isPrime(int k){
    if (k==0) return false;
    if (k==1) return false;
    for(int i=2; i<k; i++)
        if(k%i==0) return false;
    return true;
    }

    public static void main(String args[]){
		
        Scanner sc = new Scanner(System.in);
        System.out.println("Program to print all Primes in a given array \n");


        // INPUT OF THE ARRAYS
        int m;

        System.out.println("Input the size of the Array");
        m = sc.nextInt();
        int arr[] = new int[m];

        System.out.println("Input the values one by one");
        for(int i=0;i<m;i++)
          arr[i] = sc.nextInt();


        // PRINT THE GIVEN ARRAYS : Array A
        System.out.println("\nThe given array is: ");
        for(int i=0;i<m;i++)
          System.out.print(arr[i] + " ");
        System.out.println("");

        
        // Program Logic

        System.out.println(("Enter what you want to do \n 1. Find Primes \n 2. Find max and min \n 3. Find Number of occurences \n 4. Merge Arrays \n 5. Demo all \n"));
        int ch =  sc.nextInt();
        switch(ch){
          case 5:
            
          case 1: for(int i:arr)
                    if(isPrime(i)) System.out.print(i + " "); 
                  if(ch!= 5) break;
          case 2: int max = arr[0], min = arr[0];
                  for(int i:arr)  { if (i>max) max = i; if(i<min) min = i;}
                  System.out.print("Max is " + max + " Min is " + min);
                  if(ch!= 5) break;
          case 3: int flag = 0, count = 0;
                  System.out.print("Input value to find");
                  int key = sc.nextInt();
                  for(int i:arr)
                    if(i==key) 
                      {
                        flag = 1;
                        count++;
                      }
                  if(flag == 0) System.out.print("Not FOund");
                  else System.out.print("Found " + count + " occurences of the given value");
                  if(ch!= 5) break;
          case 4:                  
                  System.out.print("Enter the size of second array");
                  int n = sc.nextInt();
                  System.out.print("Enter the array elements");
                  int brr[] = new int[n];
                  for(int i=0;i<n;i++)
                      brr[i] = sc.nextInt();
                  int crr[] = new int[m+n];

                  for(int i=0;i<m+n;i++)
                      {
                        if(i<m) crr[i] = arr[i];
                        else crr[i] = brr[i-m];
                      }
                  
                  for(int i=0; i<m+n; i++)
                  System.out.print(crr[i] + " ");
                  if(ch!= 5) break;
                      
                      
                  
        }
        
        
        

    }
}
