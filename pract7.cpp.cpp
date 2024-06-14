#include <iostream>
using namespace std;

struct node
{
    int roll;
    string name;
    int next;
};

class hashh
{
public:
    node h[10];
    int i;
    void initialise()
    {
        for (i = 0; i < 10; i++)
        {
            h[i].roll = -1;
            h[i].name = "NULL";
            h[i].next = -1;
        }
        cout << "\n initialise";
        
        cout << "\n Index";
        cout << "\t Roll";
        cout << "\t Name";
        cout << "\t NextIndex";
        for (i = 0; i < 10; i++)
        {
            cout << "\n " << i;
            cout << "\t" << h[i].roll;
            cout << "\t" << h[i].name;
            cout << "\t\t" << h[i].next;
        }
    }
    void insertl()
    {
        bool flag = false, collision = false;

        int n, k, comparison = 1, j = 0;
        string name;
        cout << "\n Enter Roll number  =";
        cin >> n;
        cout << "\n Enter name =";
        cin >> name;
        k = i = (n % 10);
        while (h[i].next != -1)
        {
            i = h[i].next;
            if (h[i].next == -1)
            {
                break;
            }
            i = h[i].next;
        }
        k = i;
        while ((flag == false) && (comparison <= 10))
        {
            if (h[i].roll == -1)
            {
                h[i].roll = n;
                h[i].name = name;
                flag = true;
                if (k != i)
                {
                    h[k].next = i;
                }
            }
            else
            {
                j++;
                i = (n + j) % 10;
                comparison++;
            }
        }
        if (flag == false && (comparison >= 10))
        {
            cout << "\n Hash table is full";
        }
        else
        {
            cout << "\n Sucessfully Inserted " << n;
        }
    }

    void display()
    {
        cout << "\n Index";
        cout << "\t Roll";
        cout << "\t Name";
        cout << "\t NextIndex";
        for (i = 0; i < 10; i++)
        {
            cout << "\n " << i;
            cout << "\t" << h[i].roll;
            cout << "\t" << h[i].name;
            cout << "\t\t" << h[i].next;
        }
    }
    void search()
    {
        int n, comparison, j;
        bool found = false;
        cout << "\n Enter Roll number to search  =";
        cin >> n;
        i = (n % 10);
        while (h[i].roll != n)
        {
            if (h[i].next == -1) // Moved this check up
            {
                break;
            }
            i = h[i].next;
            if (h[i].roll == n) // Changed the condition to check after moving to the next index
            {
                found = true;
                break;
            }
        }
        if (found == false)
        {
            i = (n % 10);
            while (found == false && comparison <= 10)
            {
                if (h[i].roll == n)
                {
                    found = true;
                    break;
                }
                else
                {
                    i = (n + j) % 10;
                    j++;
                    comparison++;
                }
            }
        }
        if (found == true)
        {
            cout << "\n found \n roll=" << h[i].roll << "\t name=" << h[i].name;
        }
        else
        {
            cout << "\n Not found";
        }
    }
    void deletel()
    {
    	int n, comparison, j,k;
        bool found = false;
        cout << "\n Enter Roll number to delete  =";
        cin >> n;
        i = (n % 10);
        j=-1;
        while (h[i].roll != n)
        {
        	j=i;		
            if (h[i].next == -1) 
            {
                break;
            }
            i = h[i].next;
            if (h[i].roll == n) 
            {
                found = true;
                break;
            }
        }
        if (found == false)
        {
            i = (n % 10);
            j=-1;
            while (found == false && comparison <= 10)
            {
            	j=i;	
                if (h[i].roll == n)
                {
                    found = true;
                    break;
                }
                else
                {
                    i = (n + k) % 10;
                    k++;
                    comparison++;
                }
            }
        }
        if (found == true)
        {
            cout << "\n found \n roll=" << h[i].roll << "\t name=" << h[i].name;
            
            if(j==-1)
            {
            	h[i].roll=-1;
            	h[i].name="NULL";
            	h[i].next=-1;
            	cout<<"\n deleted sucessfully";
            }
            else if(j!=-1)
            {
            	h[j].next=h[i].next;
            	h[i].roll=-1;
            	h[i].name="NULL";
            	h[i].next=-1;
            	cout<<"\n deleted sucessfully";
            }
            
        }
        else
        {
            cout << "\n Not found";
        }
        cout<<"\n i ="<<i;
        cout<<"\n j="<<j;
    }
};
int main()
{
    bool y1 = true;
    int choice;
    hashh h1;
    h1.initialise();
    while (y1 == true)
    {
        cout << "\n\nlinear probing \n 1.insert number \n 2. display \n 3.search number \n 4.delete number \n 0.exit \n Enter menu:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            h1.insertl();
            break;
        case 2:
            h1.display();
            break;
        case 3:
            h1.search();
            break;
        case 4:
            h1.deletel();
            break;    
        case 0:
            y1 = false;
            cout << "\n Thank you!";
            break;
        default:
            cout << "\n Invalid choice";
            break;
        }
    }
    return 0;
}

