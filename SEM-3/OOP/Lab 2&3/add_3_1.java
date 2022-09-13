import java.util.*;
class Main{
public static void main(String args[]){
int a[] = { 1, 2,3,4}; 
for (int w = 0; w < 4; w++) 
{
    for (int x = 0; x < 4; x++) 
     {
        for (int y = 0; y <4; y++) 
        {
          for (int z = 0; z < 4; z++) 
          {
             if (w!=x && x != y && y != z && z != x) 
             { 
             System.out.println(a[w] + "" + a[x] + "" + a[y] + "" + a[z]); 
             } 
          }
        }
     }
  }
}
}
