#include <iostream>
#include <string>
using namespace std;

int cost[50][50];
string cities[50] ;
int ans;
int totalcity;
int connect;

void cityread()
{	
	cout<<"Enter total cities =";
	cin>>totalcity;
	for(int i=0;i<totalcity;i++)
	{
		cout<<"Enter city name =";
		cin>>cities[i];
	}
	
}
void readcost()
{
	for(int i=0;i<totalcity;i++)
	{
		for (int j=0;j<totalcity;j++)
		{
			if(i==j)
			{	
				cost[i][j]=0;
			}
			else
			{
				cout<<"is there flight from "<< cities[i]<<" to "<<cities[j]<<" city \n 1.YES \n 2.NO"<<endl;;
				cin>>ans;
				switch(ans)
				{	
					case 1:
						cout<<"\n Enter cost for flight from "<<cities[i]<<" to "<<cities[j]<<" city =";
						cin>>cost[i][j];
						break;
					case 2:
						cost[i][j]=0;
						break;
					default:
						cout<<"Invalid choice! Enter a right choice in YES OR NO";
						break;	
							
				}
			}
		}
	}
} 

void printcost()
{
	for(int i=0;i<totalcity;i++)
	{
		for (int j=0;j<totalcity;j++)
		{	
			if(i==j)
			{
				
			}
			else if(cost[i][j]==0)
			{	
				cout<<"\n sorry, there is no flight from "<<cities[i]<<" to "<<cities[j]<<" city ";
			}
			else
			{
				cout<<"\n cost for flight from "<<cities[i]<<" to "<<cities[j]<<" city is "<<cost[i][j];
			}
		}
	}
} 
void cityconnect()
{
    int i;
	for(i=0;i<totalcity;i++)
	{
		for (int j=0;j<totalcity;j++)
		{	
			connect=1;
			if(cost[i][j]==0)	
			{
				connect=0;
			}
			if(connect==1)
			{
			    break;
			}
		}
		if(connect==0)
			{
			break;
			}

	}
	if(connect==0)
	{
	cout<<"\n "<<cities[i] <<" city is not connected with any of the city .so this is Disconnected graph";
	}
	else
	{
	cout<<"\n All cities are connected so this is connected graph";
	}

}


int main()
{
	int choice;
	int y=1;
	while(y==1)
	{
	cout<<"\n MENU \n 1.Take city names \n 2.input flight costs between cities \n 3.show flight costs for all cities \n 4.check whether all cities are connected(i.e. connected or disconnected graph) \n 5.Exit \n Enter choice= ";
	cin>>choice;
	switch(choice)
	{
		case 1:	cityread();
			break;
		case 2:	readcost();
			break;
		case 3:	printcost();
			break;
		case 4:	cityconnect();
			break;
		case 5:	y=0;
			break;			
		default:cout<<"Invalid choice";
			break;
	}
	}
	return 0;
}

