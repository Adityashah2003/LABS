import java.util.*;

class areaperi {
    public static void main(String[] args) {
        int length,breadth,area,circumference=0;
        Scanner scan = new Scanner(System.in);
        length = scan.nextInt();
        breadth = scan.nextInt();
        area = length*breadth;
        circumference = 2*(length+breadth);
        System.out.println("Circumference is: "+circumference);
        System.out.println("area is: "+area);
    }
}
