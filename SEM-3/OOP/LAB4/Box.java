import java.util.*;

class Boxz{
    double height,width,depth;
    Boxz(){
        width = height = depth = 0;
    }                               //default constructor
    Boxz(double w,double h, double d){
        width = w;
        height = h;
        depth = d;
    }                               //parameterised constructor

    double getvol(){
        return height*width*depth;
    }
};

class Box{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the w,h,d: ");
        int w = sc.nextInt();
        int h = sc.nextInt();
        int d = sc.nextInt();
        Boxz obj = new Boxz(w,h,d);
        double vol = obj.getvol();
        System.out.println("vol is: "+ vol);
    }
}
