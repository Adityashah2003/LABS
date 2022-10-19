import java.util.Scanner;
class bank_acc{
    int interest=10;
    Scanner scan= new Scanner(System.in);
    int getRateOfInterest(){
        return interest;
    }
}
class SBI extends bank_acc{
    SBI(){
        interest=8;
    }
    int getRateOfInterest(){
        return interest;
    }
}
class ICICI extends bank_acc{
    ICICI(){
        interest=7;
    }
    int getRateOfInterest(){
        return interest;
    }
}
class AXIS extends bank_acc{
    AXIS(){
        interest=9;
    }
    int getRateOfInterest(){
        return interest;
    }
}

public class bank{
    public static void main(String args[]){
        bank_acc b= new bank_acc();
        SBI s= new SBI();
        ICICI i= new ICICI();
        AXIS a= new AXIS();
        System.out.println(b.getRateOfInterest());
        b=s;
        System.out.println(b.getRateOfInterest());
        b=a;
        System.out.println(b.getRateOfInterest());
        b=i;
        System.out.println(b.getRateOfInterest());
    }
}