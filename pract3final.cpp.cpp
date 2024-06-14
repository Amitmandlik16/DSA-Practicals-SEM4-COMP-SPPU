#include <iostream>
using namespace std;

struct node
{
    string name;
    node *child[50];
    int count;
};

class book
{
private:
    node *root;

public:
    book()
    {
        root = NULL;
    }
    void create();
    void display();
};

void book::create()
{
    int i, j, k;
    root = new node;
    cout << "Enter book name = ";
    cin >> root->name;
    cout << "Enter total no of chapters of book " << root->name << " = ";
    cin >> root->count;

    for (i = 0; i < root->count; i++)
    {
        root->child[i] = new node;
        cout << "Enter name of chapter no. " << (i + 1) << " of book " << root->name << " = ";
        getline(cin, root->child[i]->name);
        cout << "Enter total no of sections of chapter " << root->child[i]->name << " = ";
        cin >> root->child[i]->count;

        for (j = 0; j < root->child[i]->count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter the name of section no. " << (j + 1) << " of chapter " << root->child[i]->name << " = ";
            cin >> root->child[i]->child[j]->name;
            cout << "Enter total no of subsections of section " << root->child[i]->child[j]->name << " = ";
            cin >> root->child[i]->child[j]->count;

            for (k = 0; k < root->child[i]->child[j]->count; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "Enter name of subsection no. " << (k + 1) << " of section " << root->child[i]->child[j]->name << " = ";
                cin >> root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}

void book::display()
{
    if (root == NULL)
    {
        cout << "There is no book created";
        return;
    }

    cout << "\nBook name : " << root->name;

    for (int i = 0; i < root->count; i++)
    {
        cout << "\n"
             << (i + 1) << ".Chapter name: " << root->child[i]->name;

        for (int j = 0; j < root->child[i]->count; j++)
        {
            cout << "\n\t" << (j + 1) << ".Section name: " << root->child[i]->child[j]->name;

            for (int k = 0; k < root->child[i]->child[j]->count; k++)
            {
                cout << "\n\t\t" << (k + 1) << ".Subsection name: " << root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}

int main()
{
    book b1;
    int choice;
    while (1)
    {
        cout << "\n Menu \n 1.create Book \n 2.display Book \n 3.Exit \n Enter choice =";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b1.create();
            break;
        case 2:
            b1.display();
            break;
        case 3:
            cout << "\n Thank you!";
            exit(0);
        }
    }
    return 0;
}
