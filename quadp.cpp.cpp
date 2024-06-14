#include<iostream>
#include<string.h>
#define max 10
using namespace std;
struct node
{
	char name[10];
	long int mn;
	node()
	{
		mn=0;	
		strcpy(name,"--------");
	}
};
class telephone
{
	public:
	node ht[max];
	int count;
	telephone()
	{
		count=0;
	}
	int hashfun(long int);
	void insert();
	void find();
	void display();
	void delno();
};
int telephone::hashfun(long int num)
{
	return(num%10);
}
void telephone::insert()
{
	node s;
	int ind;
	long int m;
	cout<<"enter name and telephone no.:"<<endl;
	cin>>s.name>>s.mn;
	m=s.mn;
	ind=hashfun(s.mn);
	cout<<"index:"<<ind<<endl;
	if(ht[ind].mn==0)
	{
		ht[ind]=s;
		
	}
	else
	{	int i=1;
		while(ht[ind].mn!=0)
		{	
			ind=(m+(i*i));
			ind=ind%max;
			
			i++;
			
		}
		cout<<"new index is:"<<ind<<endl;
		ht[ind]=s;
	}


}
void telephone::display()
{
	for(int i=0;i<max;i++)
	{
		cout<<i<<"\t"<<ht[i].name<<"\t"<<ht[i].mn<<endl;
	}
}
int main()
{
	telephone t;
	int ch;
	char ans;
	do{
		cout<<"enter your choice"<<endl;
		cout<<"1.insert"<<endl;
		cout<<"2.display"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:t.insert();
				break;
			case 2:t.display();
				break;
			default:
				cout<<"invalid choice!!!";
		}
		cout<<"do you want to continue?(y/n)";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
		

