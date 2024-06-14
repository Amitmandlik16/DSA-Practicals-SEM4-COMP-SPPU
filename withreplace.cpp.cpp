#include<iostream>
#include<string.h>
#define max 10

using namespace std;
struct node
{
	char name[10];
	long int mn;
	int chain;
	node()
	{
		mn=0;
		chain=-1;
		strcpy(name,"-----");
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
    cout << "Enter name and telephone number: \n";
    cin >> s.name >> s.mn;

    ind = hashfun(s.mn);
    cout << "Index= " << ind<<endl;
	
		if (ht[ind].mn == 0)
		{
			ht[ind] = s;
			count++;
		}
		else if (ind == hashfun(ht[ind].mn))
		{
			int prev = ind;
			while (ht[ind].mn != 0)
			{
			    prev = ind;
			    ind = (ind + 1) % max;
			}

			ht[ind] = s;
			ht[prev].chain = ind;
			count++;
		}
		else
		{ //replace & rehash
			node replaced;
		    replaced=ht[ind];	   //save node to be replaced
		    
	    
			ht[ind]=s; //replace incorrect key with correct one


			    //find out place for inserting the node which is replaced.			
			while (ht[ind].mn != 0) //probe down
			    ind = (ind + 1) % max;

			ht[ind] = replaced;

			int x=hashfun(replaced.mn); //get orginal index of replaced node
			int oriind=x;
			
			while(ht[x].chain!=-1) 
			{
				 x=ht[x].chain;  // until chain of synonym does not equal to -1
				 //x is previous index for replaced node. and this we want to change to new position where it is placed.
				 
				 if(ht[x].chain!=-1) // 
					 oriind=x;
			}
				if(hashfun(ht[x].mn)==oriind) //match index for prev node of replaced node with replaced index.
					ht[x].chain=ind;
				else
					ht[oriind].chain=ind;
				
			
			count++;
		}
}
	


void telephone::display()
{
    for (int i = 0; i < max; i++)
    {
        cout << i << "\t" << ht[i].name << "\t" << ht[i].mn << "\t" << ht[i].chain << endl;
    }
}


int main()
{
    telephone t; 
	int ch;
	char ans;
	do{
		cout<<"Enter your choice"<<endl;
		cout<<"1.Insert"<<endl;
		cout<<"2.Display"<<endl;
		
		cin>>ch;
		switch(ch)
		{
			case 1:t.insert();
					break;
			case 2:t.display();
					break;
			
			default:
				cout<<"Invalid choice!!";
		}
		cout<<"Do you want to continue? (1/0)";
		cin>>ans;
	}while(ans=='1');
	return 0;
}
	
	
	
	
