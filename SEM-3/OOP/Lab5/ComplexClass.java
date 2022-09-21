class Complex {

  int real, complex;

  Complex() { real = complex = 0;}
  Complex(int r, int i){
    real = r;
    complex = i;
  }

  void add(int r, Complex c){
    real = r+ c.real;
    complex = c.complex;
  }

  void add(Complex c1, Complex C2){
    real = c1.real+c2.real;
    complex = c1.complex+c2.complex;
    System.out.println("Summation is " + real + complex + "i");
  }
  
}

class ComplexPrg{
  public static void main(String args[]){

    Complex a, b, sum;
    a = new Complex(10,5);
    b = new Complex(20,5);

    sum.add(a,b);
  }
}
