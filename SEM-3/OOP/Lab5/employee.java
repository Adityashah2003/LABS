import java.util.*;

class emp{
    String emp_name;
    String city;
    double salary,da , hra = 0;
    emp(){
        da = hra = salary = 0;
        city = emp_name = "lamo";
    }                               //default constructor
    /*emp(String town ,String name,double pay ,ad,arh){
        city = town;
        emp_name = name;
        da=ad;
        hra = arh;
        salary = pay;
    }                                //parameterised constructor not needed*/
    void getdata(){
        Scanner sc = new Scanner(System.in);
        emp_name = sc.next();   
        city = sc.next();
        salary=sc.nextInt();
        da=sc.nextInt();
        hra =sc.nextInt();
    }
    void putdata(){
        System.out.println("Name is:" + emp_name + "city is:" + city + "salary is:" + salary + "DA and HRA are: " + da + hra);
    }
    void calculate(){
        double total =  salary + salary*(da/100)+salary*(hra/100);
        System.out.println("Total is: " + total);
    }
};

class employee{
    public static void main(String args[]) {
        emp obj = new emp();
        obj.getdata();
        obj.putdata();
        obj.calculate();
    }
}
