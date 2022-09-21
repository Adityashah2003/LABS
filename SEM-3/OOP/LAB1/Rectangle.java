import java.util.Scanner;

public class Rectangle
{
   public static void main(String[] args)
   {
      Scanner in= new Scanner(System.in);
      int num= in.nextInt();
      int temp,r,sum=0;
      temp = num;
      while(num>0){
        r=num%10; 
        sum=(sum*10)+r;    
        num=num/10;   
      }
      /*
      for(i=1;i<=number;i++){    
      fact=fact*i;
      */
      if(temp==sum){
        System.out.print("p");
      }
      else{
        System.out.print("n");
      }
   }
}
