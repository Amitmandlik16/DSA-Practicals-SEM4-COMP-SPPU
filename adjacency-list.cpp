#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct node
{
	node *next;
	node *prev;
	string name;
};
class dll
{
public:
	node *array[50];
	int n1,n2;
	node *head=NULL,*temp=NULL,*nn=NULL;
	void create()
	{
		cout<<"Enter number of vertices =";
		cin>>n1;
		for(int i=0;i<n1;i++)
		{   
			nn=new node;
			array[i]=nn;
			nn->next=NULL;
			nn->prev=NULL;
			cout<<"\n Enter node name =";
			cin>>nn->name;
			cout<<"Enter number of vertices connected to the "<<nn->name<<" ="; 
			cin>>n2;
			for(int j=0;j<n2;j++)
			{
				temp=new node;
				nn->next=temp;
				cout<<"Enter name of the connected vertices =";
				cin>>temp->name;
				temp->next=NULL;
				temp->prev=NULL;
				nn=temp;
			}
		}
	}
	void read()
	{
		for(int i=0;i<n1;i++)
		{
			temp=array[i];
			cout<<"\n Node name is "<<temp->name<<endl;
			temp=temp->next;
			cout<<"node "<<array[i]->name<<" connneced vertices are";
			while(temp!=NULL)
			{
				cout<<"\t "<<temp->name;
				temp=temp->next;			
			}
		}
	}
};

int main()
{
	int t;
	dll g;
	g.create();								
	g.read();
	return 0;
}