#include <iostream>
using namespace std;
class B0
{
	int a;
public:
	B0(int x):a(x){	}
	void display()
    	{cout<<"B0::display()  "<<a<<endl;}
    	int getA()
    	{
       	 return a;
    	}
};
class B1: virtual public B0
{
	int b1;
public:
	B1(int x,int y):B0(x),b1(y) {	}
	  void display()
     	{ B0::display();
	 cout<<"B1::display()  "<<b1<<endl;  }
};
class B2: virtual public B0
{
	int b2;
public:
	B2(int x,int y):B0(x),b2(y) {	}
	  void display()
     	{ B0::display();
	 cout<<"B2::display()  "<<b2<<endl;  }
};
class D: public B1, public B2
{
	int d;
public:
	D(int x, int y, int z):B1(y,z),B2(z,y),B0(x)
	{d=x+y+z;
	}
	  void display()
     	{  cout<<"D1::display()  "<<d<<endl;  }
};
int main()
{
    B0 b0(1);
    B1 b1(2,2);
    B2 b2(3,3);
    D d1(1,2,3);
    b0.display();
    b1.display();
    b2.display();
    cout<<"D::a="<<d1.getA()<<endl;
   	return 0;
}
