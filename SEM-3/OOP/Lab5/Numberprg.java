import java.util.*;
class Number{
    private double num;
    Number(double n){
        num = n;
    }
    boolean isZero(){
        if(num==0)
            return true;
        return false;
    }
    boolean isPositive(){
        if(num>0)
            return true;
        return false;
    }
    boolean isNegative(){
        if(num<0)
            return true;
        return false;
    }
    boolean isEven(){
        if(num%2==0)
            return true;
        return false;
    }
    boolean isOdd(){
        if(num%2!=0)
            return true;
        return false;
    }
    boolean isArm(){
        int  r=0,sum=0,temp=0;
        int j=(int)num;
        temp = j;
        while(temp!=0){
            r = temp%10;
            sum = sum + r*r*r;
            temp = temp/10;
        }
        if (j == sum)
            return true;
        return false;
    }
    boolean isPrime(){
        int i=0;
        for(i = 2;i<num;i++){
            if(num%i==0)
            return true;}
          return false;
        }
};
      
class Numberprg{
public static void main(String args[])
{
    Scanner sc= new Scanner(System.in);
    System.out.println("Enter a number");

    double n=sc.nextDouble();

    Number num1 = new Number(n);

    System.out.println("Zero: "+num1.isZero());
    System.out.println("Armstrong: "+num1.isArm());
    System.out.println("Positive: "+num1.isPositive());
    System.out.println("Negative: "+num1.isNegative());
    System.out.println("Odd: "+num1.isOdd());
    System.out.println("Even: "+num1.isEven());
    System.out.println("Prime: "+num1.isPrime());
}
}





