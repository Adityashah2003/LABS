import java.io.*;
import java.net.DatagramSocketImplFactory;
import java.util.*;

class count{
    synchronized void counter(String s){
        int words=0;
        int lines=0;
        int chars=s.length();
        int vowels=0;
        for(int i=0; i<chars;i++){
            char c=s.charAt(i);
            switch(c){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels+=1;
                    break;
                case '\n':
                    lines+=1;
                case ' ':
                    words+=1;
                    break;
            }
        }
        System.out.println("Number of words:"+words);
        System.out.println("Number of lines:"+lines);
        System.out.println("Number of vowels:"+vowels);
        System.out.println("Number of characters:"+chars);
    }
    synchronized void disp(){
        System.out.println("Hello");
    }
}
class Mythread extends Thread{
    count c;
    // String s;
    // Mythread(){
    //     this.s = s;
    // }
    public void run(){
        c.disp();
    }
}
class Mythread1 extends Thread{
    count c;
    String s;
    Mythread1(String s){
        this.s = s;
    }
    public void run(){
        c.counter(s);
    }
}
class three{
    public static void main(String[] args) throws IOException {
        File f1 = new File("1A.txt");
        FileInputStream fis = new FileInputStream(f1);
        count c = new count();
        int ch=0;
        StringBuffer s1 = new StringBuffer();
        while((ch=fis.read())!=-1){
            s1.append(Character.toString((char)ch));
        }
        Mythread1 t1 = new Mythread1(s1.toString());
        t1.start();
        Mythread t = new Mythread();
        t.start();

    }
}