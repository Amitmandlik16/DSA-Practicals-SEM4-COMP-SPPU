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
class BFS
{
public:
    queue<node *> q;
    string v;
    node *array[50];
    int n1, n2;
    node *head = NULL, *temp = NULL, *nn = NULL;
    void read()
    {
        cout << "Enter number of vertices =";
        cin >> n1;
        for (int i = 0; i < n1; i++)
        {
            nn = new node;
            array[i] = nn;
            nn->next = NULL;
            nn->prev = NULL;
            cout << "\n Enter node name =";
            cin >> nn->name;
            cout << "Enter number of vertices connected to the " << nn->name << " =";
            cin >> n2;
            for (int j = 0; j < n2; j++)
            {
                temp = new node;
                nn->next = temp;
                cout << "Enter name of the connected vertices =";
                cin >> temp->name;
                temp->next = NULL;
                temp->prev = NULL;
                nn = temp;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < n1; i++)
        {
            temp = array[i];
            cout << "\n Node name is " << temp->name << endl;
            temp = temp->next;
            cout << "node " << array[i]->name << " connneced vertices are";
            while (temp != NULL)
            {
                cout << "\t " << temp->name;
                temp = temp->next;
            }
        }
    }
    void bfs(int v)
    {
        cout << "\n bfs traversal is ";
        bool visited[n1];
        for (int i = 0; i < n1; i++)
            visited[i] = false;

        queue<node *> q;
        visited[v] = true;
        q.push(array[v]);

        while (!q.empty())
        {
            node *temp = q.front();
            cout << temp->name << " ";
            q.pop();

            while (temp != NULL)
            {
                int index;
                for (index = 0; index < n1; index++)
                {
                    if (array[index]->name == temp->name)
                        break;
                }

                if (!visited[index])
                {
                    visited[index] = true;
                    q.push(array[index]);
                }
                temp = temp->next;
            }
        }
    }
};

int main()
{
    BFS a;
    int choice;
    while (1)
    {
        cout << "\n Menu \n 1.read graph \n 2.display graph \n 3.BFS graph \n 4.Exit \n Enter choice =";
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.read();
            break;
        case 2:
            a.display();
            break;
        case 3:
            int s;
            cout << "\nenter strating vertex no:";
            cin >> s;
            a.bfs(s);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
