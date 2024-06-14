#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct node
{
    char word[10];
    char mean[10];
    node *left;
    node *right;
    int ht;
};
class avl
{
    node* create(node *root)
    {
        int n,i;
        char w[10],m[10];
        cout<<"Enter total number of words to store";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter word no. "<<i<<" =";
            cin>>w;
            cout<<"Enter meaning of the word =";
            cin>>m;
            root=insert(root,w,m);
        }
    }
    node* insert(node* root,char w[],char m[])
    {
        if(root==NULL)
        {
            root=new node;
            strcpy(root->word,w);
            strcpy(root->mean,m);
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        else
        {
            if(strcmp(w,root->word)>=0)   
            {
                root->right=insert(root->right,w,m);
            }
            else
            {
                root->left=insert(root->left,w,m);
            }
        }
        root=balancenode(root);
        root->ht=height(root);
        return root;
    }
    void display(node* root)
    {
        if(root=NULL)
        {
            return;
        }
        else
        {
            queue<node*> q;
            q.push(root);
            while(!q.empty())
            {
                node* temp=q.front();
                q.pop();
                cout<<"\n\n root="<<temp->word<<"mean ="<<temp->mean;
                if(temp->left)
                {
                    cout<<"\n  left word= "<<temp->left->word<<" mean= "<<temp->left->mean;
                }
                if(temp->right)
                {
                    cout<<"\n  right word= "<<temp->right->word<<" mean= "<<temp->right->mean;
                }
            }
        }
    }
    int height(node* root)
    {
        if(root=NULL)
        {
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        if(lh>rh)
        {
        return (lh+1);
        }
        else 
        {   
            return rh+1;
        }
    }
    node* update(node *root,char word[],char mean[])
    {
        root=deletenode(root,word);
        root=insert(root,word,mean);
        return root;
    }
    node* rotateright(node *x)
    {
        node *y=x->left;
        x->left=y->right;
        y->right=x;
        x->ht=height(x);
        y->ht=height(x);
        return y;
    }
    node* rotateleft(node *x)
    {
        node*y=x->right;
        x->right=y->left;
        y->left=x;
        x->ht=height(x);
        y->ht=height(y);
        return y;
    }
    int bf(node *root)
    {
        int lh=0,rh=0;
        if(root->left=NULL)
        {
            lh=1+root->left->ht;
        }
        else
        {
            rh=1+root->right->ht;
        }
        return lh-rh;
    }
    node* RR(node* T)
    {
        T=rotateleft(T);
        return T;
    }
    node* LL(node* T)
    {
        T=rotateright(T);
        return T;
    }
    node *LR(node *T)
    {
        T->left=rotateleft(T->left);
        T=rotateright(T);
        return T;
    }
    node *RL(node *T)
    {
        T->right=rotateright(T->right);
        T=rotateleft(T);
        return T;
    }
    node* search(node *root,char word[])
    {
        if(root=NULL)
        {
            return NULL;
        }
        if(strcmp(word,root->word)==0)
        {
            return root;
        }
        else if(strcmp(word,root->word)<0)
        {
            return search(root->left,word);
        }
        else
        {
            return search(root->right,word);
        }
    }
    node* minvaluenode(node *root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        node *temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp;
    }
    node* balancenode(node *root)
    {
        if(root==NULL)
        {
            return root;
        }
        else
        {
            root->ht=height(root);
            int balance=bf(root);
            if(balance>1 && bf(root->left)>=0)
            {
                return LL(root);
            }
            if(balance>1 && bf(root->right)<=0)
            {
                return RR(root);
            }
            if(balance <)
        }
    }


};