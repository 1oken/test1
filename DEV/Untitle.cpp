#include<iostream>
using namespace std;

int main(){
	int a[26]={14, '\r', 17, 23, 2, 'K', 'I', '7', ' ', 30, 20, 'I', '\n', 2, '\f', '>', '(', '@', 11, '\'', 'K', 'Y', 25, 'A', '\r'};
	int b[7] = {'h','a','p','p','y','x','3'};
	char flag[26];
	for (int i=0;i<26;i++)
	{
		flag[i]= a[i] ^ b[i % 7];
	}
	for (int i=0;i<26;i++)
	{
		cout<< flag[i];
	}
	
}
