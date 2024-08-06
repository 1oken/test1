#include<iostream>
using namespace std;

void p(int* x,int &y)
{
	y=*x+y;
	*x=y%4;
	cout<<*x<<","<<y<<endl;
}

int main()
{
	int x=4,y=5;
	p(&y,&x);
	cout<<x<<","<<y<<endl;
}
