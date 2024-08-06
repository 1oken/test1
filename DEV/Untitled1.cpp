#include<iostream>
using namespace std;

struct node
{
	int data;
    node* next;
    
    node(int x):data(x){
	} 
	
};

struct list
{
	node* head;
	int length;
};

void addnode(list&,int);
int main()
{
	list list;
	list.head=NULL;
	list.length=0;
	int inputdata;
	char chr='Y';
	while(chr=='Y'||chr=='y')
	{
		cin>>inputdata;
		addnode(list,inputdata);
		cin>>chr;
	}
	void addnode(list &list,int dt)
	{
		node*pcur=new node;
		pcur->data=dt;
		pcur->next=NULL;
		if(list.head==NULL)
		{
			list.head=pcur;
			list.length=1;
		}
		else
		{
			node* pt=list.head;
			while(pt->next)
				pt=pt->next;
			pt->next=pcur;
			lisr.length++;
		}
	}
	
	return 0;
}
