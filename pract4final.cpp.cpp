#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct node
{
    string data;
    node *left;
    node *right;
};

class expression
{
public:
    string a;
    node *root, *nn, *temp;
    expression()
    {
        root = NULL;
    }

    void readprefix()
    {
        cout << "Enter prefix expression =";
        cin >> a;
        cout << "expression size is " << a.size() << endl;
        cout << "Given prefix expression is" << endl;
        for (int i = 0; i < a.size(); i++)
        {
            cout << " " << a[i];
        }
    }

    void createtree()
    {
        stack<node *> stk;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
            {
                nn = new node;
                nn->left = stk.top();
                stk.pop();
                nn->right = stk.top();
                stk.pop();
                nn->data = a[i];
                stk.push(nn);
            }
            else
            {
                nn = new node;
                nn->left = NULL;
                nn->right = NULL;
                nn->data = a[i];
                stk.push(nn);
            }
        }

        root = stk.top();
        cout<<"Expression Tree created";
    }
    void preorder()
    {
        if (root == NULL)
        {
            cout << "There is no expression tree created";
        }
        else
        {
            cout << "\n preorder travseral is" << endl;
            stack<node *> s;
            node *temp = root;
            s.push(temp);
            while (!s.empty())
            {
                temp = s.top();
                s.pop();
                cout << " " << temp->data;
                if (temp->right != NULL)
                {
                    s.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    s.push(temp->left);
                }
            }
        }
    }
    void postorder()
    {
        if (root == NULL)
        {
            cout << "There is no expression tree created";
        }
        else
        {
            cout << "\n postorder travseral is" << endl;
            stack<node *> s1, s2;
            node *temp = root;
            s1.push(temp);
            while (!s1.empty())
            {
                temp = s1.top();
                s1.pop();
                s2.push(temp);
                if (temp->left != NULL)
                {
                    s1.push(temp->left);
                }
                if (temp->left != NULL)
                {
                    s1.push(temp->right);
                }
            }
            while (!s2.empty())
            {
                temp = s2.top();
                s2.pop();
                cout << " " << temp->data;
                temp->left=temp->right=NULL;
                delete temp;
            }
            root=NULL;
            cout<<"\n Deleted Entire expression tree";
        }
    }
    void deletetree()
    {
        temp = root;
        root = NULL;
        delete temp;
        cout << "Expression Tree root node deleted.";
    }
};

int main()
{
    expression exp1;
    int choice, y = 1;
    while (y == 1)
    {
        cout << "\n\n MENU \n 1.Read Input Prefix Expression \n 2.Create Prefix Expression Tree \n 3.Preorder Travseral display \n 4.Postorder Travsersal display and delete entire tree \n 5.Delete Expression Tree root node \n 6.Exit \n Enter choice =";
        cin >> choice;
        switch (choice)
        {
        case 1:
            exp1.readprefix();
            break;
        case 2:
            exp1.createtree();
            break;
        case 3:
            exp1.preorder();
            break;
        case 4:
            exp1.postorder();
            break;
        case 5:
            exp1.deletetree();
            break;
        case 6:
            cout << "Thank you";
            y = 0;
            break;
        default:
            cout << "Enter correct choice";
            break;
        }
    }

    return 0;
}

