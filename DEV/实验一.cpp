#include<iostream>
using namespace std;

int main(){
	int n,mid=0;
	int a[10];
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++){
			if(a[i]<a[j])
			{
				int tem=a[i];
				a[i]=a[j];
				a[j]=tem;
			}
		}
	}
	if(n%2==0)
	mid=(a[n/2-1]+a[(n+2)/2-1])/2;
	else
	mid=a[(n+1)/2-1];
	cout<<a[0]<<" "<<mid<<" "<<a[n-1];
}
