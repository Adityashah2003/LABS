
import java.util.Scanner;

import javax.management.loading.MLet;
class Time {
  int hour, min, sec;

  Time() { hour = min = sec = 0;}
  Time(int h, int m, int s)
  {
    hour = h;
    min = m;
    sec = s;
  }

  void printTime()
  { System.out.println( hour +":"+ min +":"+ sec);}
  
  void AddTime(Time a, Time b)
  {
    sec = (a.sec + b.sec)%60;
    min = (a.min + b.min)%60 + (a.sec+b.sec)/60;
    hour = (a.hour+b.hour) %24 + (a.min + b.min)/60;
    
  }
}

class TimePrg{
  public static void main(String args[])
  {
    Time obj1, obj2, Sum;
    obj1 = new Time();
    obj2 = new Time(5, 45, 30);
    Sum = new Time();

    System.out.print("Object 1 default initialised to value \t");
    obj1.printTime();
    System.out.print("Object 2 manually initialised to value \t");
    obj2.printTime();

    System.out.print("Object 1 = Obj2+Obj2 \t\t \t");
    obj1.AddTime(obj2, obj2);
    obj1.printTime();
    System.out.print("Sum = Obj1 + Obj2 \t\t\t");
    Sum.AddTime(obj1, obj2);
    Sum.printTime();

  }
}