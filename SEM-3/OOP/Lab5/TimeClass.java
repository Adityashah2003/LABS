import java.util.*;

class sec{
    int hours,minutes,seconds=0;
    sec(){
        hours = minutes = seconds =0;
    }                               //default constructor

    sec(int h,int m,int s){
        hours =h;
        minutes=m;
        seconds =s;
    }                                //parameterised constructor
    void display(){
        System.out.println("HH:MM:SS is: " + hours+":"+minutes+":"+ seconds);
    }
    void add(sec a,sec b){
        seconds = (a.seconds + b.seconds)%60;
        minutes = (a.minutes + b.minutes)%60 + (a.seconds+b.seconds)/60;
        hours = (a.hours+b.hours) %24 + (a.minutes + b.minutes)/60;
    }
};

class Time{
    public static void main(String args[]) {
        sec obj1,obj2,sum;
        obj1 = new sec();
        obj2 = new sec(05,45,30);
        sum = new sec();
        
        
        System.out.print("Object 1 default initialised to value \t");
        obj1.display();
        System.out.print("Object 2 manually initialised to value \t");
        obj2.display();
    
        /*System.out.print("Object 1 = Obj2+Obj2 \t\t \t");
        obj1.add(obj2, obj2);
        obj1.display();*/
        System.out.print("Sum = Obj1 + Obj2 \t\t\t");
        sum.add(obj1, obj2);
        sum.display();
    }
}
