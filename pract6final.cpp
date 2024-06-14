#include <iostream>
using namespace std;

class hash
{
	public:
		long int tele[10],n;
		int i;
		void initialise()
		{
			for(i=0;i<10;i++)
			{
			tele[i]=-1;
			}
			cout<<"\n initialise";
			for(i=0;i<10;i++)
			{
			cout<<" "<<tele[i];
			}
		}
		
		void insertl()
		{
			bool flag=false;
			int comparison=1,j=1;
			cout<<"Enter number to insert =";
			cin>>n;
			i=(n%10);
			while((flag==false) && (comparison<=10))
			{
				if(tele[i]==-1)
				{
					tele[i]=n;
					flag=true;
					cout<<"\n comparions ="<<comparison;
					break;
				}
				else
				{
					i=(n+j)%10;
					j++;
					comparison++;
				}
			}
			if(flag==false && (comparison>=10))
			{
				cout<<"\n comparions ="<<comparison;
				cout<<"Hash table is full"	;
			}
			
			
		}
		void searchl()
		{
			bool flag=false;
			int comparison=1,j=1;
			cout<<"Enter number to search =";
			cin>>n;
			i=(n%10);
			while(flag==false && comparison<=10)
			{
				if(tele[i]==n)
				{
					cout<<"found "<<tele[i]; 
					flag=true;
					cout<<"\n comparisons ="<<comparison;
					break;
				}
				else
				{
					i=(n+j)%10;
					j++;
					comparison++;
				}
			}
			if(flag==false && (comparison>=10))
			{
				cout<<"\n comparions ="<<comparison;
				cout<<"\n"<<n<< "not found";	
			}
		}
		
		
		void insertq()
		{
			bool flag=false;
			int comparison=1,j=1;
			cout<<"Enter number to insert =";
			cin>>n;
			i=(n%10);
			while((flag==false) && (comparison<=10))
			{
				if(tele[i]==-1)
				{
					tele[i]=n;
					flag=true;
					cout<<"\n comparions ="<<comparison;
					break;
				}
				else
				{
					i=(n+(j^2))%10;
					j++;
					comparison++;
				}
			}
			if(flag==false && (comparison>=10))
			{
				cout<<"\n comparions ="<<comparison;
				cout<<"Hash table is full"	;
			}
		}
		void searchq()
		{
			bool flag=false;
			int comparison=1,j=1;
			cout<<"Enter number to search =";
			cin>>n;
			i=(n%10);
			while(flag==false && comparison<=10)
			{
				if(tele[i]==n)
				{
					cout<<"found "<<tele[i]; 
					flag=true;
					cout<<"\n comparisons ="<<comparison;
					break;
				}
				else
				{
					i=(n+(j^2))%10;
					j++;
					comparison++;
				}
			}
			if(flag==false && (comparison>=10))
			{
				cout<<"\n comparions ="<<comparison;
				cout<<"\n"<<n<< "not found";	
			}
		}
};
int main()
{
	bool y1=false,y2=false;
	int choice;
	hash h1;
	h1.initialise();
	cout<<"\n select collision probing method \n 1.linear probing \n 2.quadratic probing \n 0.exit \n Enter =";
	cin>>choice;
	switch(choice)
		{
		case 1:	y1=true;
				break;
		case 2:	y2=true;
				break;
		case 0: cout<<"\n Thank you!";
				break;
		default:cout<<"\n Invalid choice";
				break;
		}		
	while(y1==true)
	{	
		cout<<"\n\nlinear probing \n 1.insert number \n 2.search number \n 0.exit \n Enter menu";
		cin>>choice;
		switch(choice)
		{
		case 1:	h1.insertl();
				break;
		case 2:	h1.searchl();
				break;
		case 0:	y1=false;
				cout<<"\n Thank you!";
				break;
		default:cout<<"\n Invalid choice";
				break;
		}
	}
	while(y2==true)
	{
		cout<<"\n\nquadratic probing \n 1.insert number \n 2.search number \n 0.exit \n Enter menu";
		cin>>choice;
		switch(choice)
		{
		case 1:	h1.insertq();
				break;
		case 2:	h1.searchq();
				break;
		case 0:	y2=false;
				cout<<"\n Thank you!";
				break;
		default:cout<<"\n Invalid choice";
				break;
		}
	}
	return 0;
}