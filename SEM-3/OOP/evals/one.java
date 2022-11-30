import java.util.*;
import java.io.*;
class one{
    public static void main(String args[])throws IOException, EOFException{
        File f1 =new File("1A.txt");
        File f2 =new File("1B.txt");
        System.out.println("1.Write a line to a file");
        System.out.println("2.Read a line from a file");
        System.out.println("3.Copy the contents of one file to other file");
        System.out.println("4.Exit");

        Scanner sc = new Scanner(System.in);
        int choice=0;
        choice = sc.nextInt();
        while(true){
            switch(choice){
            case 1:
                FileOutputStream fos = new FileOutputStream(f1,true);
                String s = sc.nextLine();
                byte b[]= s.getBytes();
                fos.write(b);
                fos.flush();
                break;
            case 2:
                FileInputStream fis = new FileInputStream("1A.txt");
                int ch;
                while((ch = fis.read())!=-1){
                    System.out.println((char)ch);   
                }
                break;
            case 3:
                FileOutputStream fos1 = new FileOutputStream(f2,true);
                FileInputStream fis1 = new FileInputStream("1A.txt");
                int c;
                while((c = fis1.read())!=-1){
                    fos1.write(c); 
                }
                
            case 4:
                return;
            default:
                System.out.println("Invalid Choice!");  
            } 
        }
    }
}
