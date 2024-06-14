#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node()
    {
        data=-1;
        next=NULL;
    }
};

class hashl
{
    public:
    node* arr[10];
    node* temp;
    node* temp1;
    void initialize()
    {
        for(int i=0;i<10;i++)
        {
            arr[i]=new node;
            arr[i]->data=-1;
        }
    }
        void insert(int n)
    {
        int i=n%10;
        if(arr[i]->data==-1)
        {   
            arr[i]->data=n;
            cout<<"sucessfully inserted "<<n<<endl;
        }
        else
        {
            node* temp=arr[i];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            node* nn=new node;
            temp->next=nn;
            nn->data=n;
            cout<<"sucessfully inserted "<<n<<"with open addressing method"<<endl;
        }
    }
        void display()
        {
            cout<<"displaying the hash table";
            for(int i=0;i<10;i++)
            {
                cout<<"\n "<<i<<"\t"<<arr[i]->data;
                temp=arr[i]->next;
                while(temp!=NULL)
                {
                    cout<<"->"<<temp->data;
                    temp=temp->next;
                }
            }
        }
    void search(int v)
        {
            bool searched=false;
                int i=v%10;
                temp=arr[i];
                if(temp->data==v)
                {
                    cout<<v<<"found";
                    searched=true;
                }
                else
                {
                temp=arr[i]->next;
                while(temp!=NULL)
                {
                    if(temp->data==v)
                    {
                        cout<<v<<"found";
                        searched=true;
                        break;
                    }
                    temp=temp->next;
                }
                }
                if(searched==false)
                {
                    cout<<"\t"<<v<<"not found";
                }
            }
    void delte(int v)
        {
            bool searched=false;
                int i=v%10;
                temp=arr[i];
                if(temp->data==v)
                {
                    cout<<v<<"found";
                    searched=true;
                    arr[i]=temp->next;
                    delete temp;
                    cout<<"deleted";
                }
                else
                {
                temp1=temp;
                temp=temp->next;
                while(temp!=NULL)
                {   

                    if(temp->data==v)
                    {
                        cout<<v<<"found";
                        searched=true;
                        temp1->next=temp->next;
                        delete temp;
                        cout<<"deleted";
                        break;
                    }
                    temp1=temp;
                    temp=temp->next;
                }
                }
                if(searched==false)
                {
                    cout<<"\t"<<v<<"not found";
                }
            }
        
    };
int main()
{
    hashl h;
    h.initialize();
    h.display();
    h.insert(0);
    h.insert(10);
    h.insert(22);
    h.insert(30);
    h.insert(450);
    h.display();
    cout<<"\n";
    h.search(55);
    cout<<"\n";
    h.delte(10);
    h.display();
    return 0;
}