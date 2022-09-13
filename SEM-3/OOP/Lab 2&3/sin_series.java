import java.util.*;
class sin_series {
    public static void main(String[] args) {
        int i,fac,j,m,x=0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        x = sc.nextInt();
        double y;
        y = x*Math.PI/180;
        double sine = 0;
        for(i=0; i<=n; i++){
            fac = 1;
            for(j=2; j<=2*i+1; j++){
                fac*=j;
            }
            sine+=Math.pow(-1.0,i)*Math.pow(y,2*i+1)/fac;
        }
        System.out.format("The sine of " + x + " is %f",sine);
    }
}
