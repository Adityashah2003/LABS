import java.io.*;
import java.util.*;

class three{
    static void counter()throws IOException{
        FileInputStream fis = new FileInputStream(new File ("1A.txt"));
        int ch=0;
        StringBuffer s1 = new StringBuffer();
        while((ch=fis.read())!=-1){
            s1.append(Character.toString((char)ch));
        }
        s1.toString();
        int words=0;
        int lines=0;
        int chars=s1.length();
        int vowels=0;
        for(int i=0; i<chars;i++){
            char c=s1.charAt(i);
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
    public static void main(String[] args) throws IOException {
        counter();
        
    }
}