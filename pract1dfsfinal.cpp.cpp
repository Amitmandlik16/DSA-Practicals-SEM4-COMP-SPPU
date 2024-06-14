#include <iostream>
#include <stack>
#include <string>
using namespace std;

class DFS
{
    int graph[50][50];
    int visited[50];
    string nodename[50];
    int i, j, n, y, g1, g2;

public:
    void read()
    {
        int v;
        cout << "Enter the total number of nodes/vertices: ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cout << "Enter node name of index no. " << i << " =";
            cin >> nodename[i];
            for (j = 0; j < n; j++)
            {
                graph[i][j] = 0;
            }
        }
        y = 1;
        while (y == 1)
        {
            cout << "\n enter a edge starting vertices node no.: ";
            cin >> g1;
            cout << "enter a edge ending vertices node no.: ";
            cin >> g2;
            graph[g1][g2] = 1;
            cout << "\n do you want to add more edges \n 1.Yes 0.No: ";
            cin >> y;
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\t" << nodename[i];
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << nodename[i] << "\t";
            for (int j = 0; j < n; j++)
            {
                cout << graph[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    void dfs(int s)
    {
        stack<int> stk;
        stk.push(s);
        int var;
        visited[s] = 1;
        while (!stk.empty())
        {
            var = stk.top();
            cout << nodename[var] << "->";
            stk.pop();
            for (i = 0; i < n; i++)
            {
                if (graph[var][i] == 1 && visited[i] == 0)
                {
                    visited[i] = 1;
                    stk.push(i);
                }
            }
        }
    }
    /*
    void dfs(int v)
    {
        cout << nodename[v] << "\t";
        visited[v] = 1;
        for (int i = 0; i < n; i++)
        {
            if ((graph[v][i] == 1) && (visited[i] != 1))
            {
                dfs(i);
            }
        }
    }
    */
};
int main()
{
    DFS a;
    int choice;
    while (1)
    {
        cout << "\n Menu \n 1.read graph \n 2.display graph \n 3.DFS graph \n 4.Exit \n Enter choice =";
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
            a.dfs(s);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}