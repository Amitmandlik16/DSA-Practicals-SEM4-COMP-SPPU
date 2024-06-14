#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct node
{
  node *left;
  node *right;
  int data;
};


class bst
{
public:
  int lh, rh;
  node *root = NULL, *head = NULL, *temp = NULL;
  node *insert (node * root, int val)
  {
	if (root == NULL)
	  {
		node *nn = new node;
		  nn->left = NULL;
		  nn->right = NULL;
		  nn->data = val;
		  root = nn;
		  return root;
	  }
	else
	  {
		if (root->data < val)
		  {
			root->right = insert (root->right, val);
		  }
		else
		  {
			root->left = insert (root->left, val);
		  }
	  }

  }
  node* inorder(node * root)
  {
  	if(root==NULL)
  	{
  		return NULL;
  	}
  	else
  	{
  		inorder(root->left);
  		cout<<"\t"<<root->data;
  		inorder(root->right);
  	}
  }
  void preorder (node * root)
  {
	if (root == NULL)
	  {
		cout << "There is no binary search tree created";
	  }
	else
	  {
		cout << "\n preorder travseral is";
		stack < node * >s1;
		node *temp = root;
		s1.push (temp);
		while (!s1.empty ())
		  {
			temp = s1.top ();
			s1.pop ();
			cout << " " << temp->data;
			if (temp->right != NULL)
			  {
				s1.push (temp->right);
			  }
			if (temp->left != NULL)
			  {
				s1.push (temp->left);
			  }
		  }
	  }
  }
  void longest ()
  {
	if (head == NULL)
	  {
		cout << "There is no binary search tree created";
	  }
	else
	  {
		temp = head;
		cout << "\n left Longest path in binary search tree :";
		while (temp != NULL)
		  {
			cout << " " << temp->data;
			temp = temp->left;
			lh++;
		  }
		cout << "\n left longest path is " << lh << endl;

		temp = head;
		cout << "\n right Longest path in binary search tree :";
		while (temp != NULL)
		  {
			cout << " " << temp->data;
			temp = temp->right;
			rh++;
		  }
		cout << "\n right longest path is " << rh << endl;
		if (lh > rh)
		  {
			cout << "\n longest path is left " << lh;
		  }
		else
		  {
			cout << "\n longest path is right" << rh;
		  }
	  }
  }
  void minimumval ()
  {
	if (head == NULL)
	  {
		cout << "There is no binary search tree created";
	  }
	else
	  {
		int min;
		temp = head;
		while (temp->left != NULL)
		  {
			temp = temp->left;
			min = temp->data;
		  }
		cout << "Minimum value found in binary search tree is " << min;
	  }
  }

  node *swaptree (node * root)
  {
	if (root == NULL)
	  {
		return NULL;
	  }
	else
	  {
		root->left = swaptree (root->left);
		root->right = swaptree (root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	  }
  }



  node *searchval (node * root, int val)
  {
	if (root == NULL)
	  {
		cout << val << "not found in binary search tree";
		return NULL;
	  }
	else if (root->data == val)
	  {
		cout << val << " found in binary search tree";
		return root;
	  }
	else
	  {
		if (root->data < val)
		  {
			root->right = searchval (root->right, val);
		  }
		else
		  {
			root->left = searchval (root->left, val);
		  }
	  }

	/*int val;
	   bool flag;
	   if(head==NULL)
	   {
	   cout<<"There is no binary search tree created";
	   }
	   else
	   {
	   cout<<"Enter value to be searched in binray search tree";
	   cin>>val;
	   temp=head;
	   while(temp!=NULL)
	   {
	   if(temp->data==val)
	   {
	   cout<<temp->data<<" found in binary search tree";
	   flag=true;
	   break;
	   }
	   else if(temp->data>val)
	   {
	   temp=temp->left;
	   }
	   else if(temp->data<val);
	   {
	   temp=temp->right;
	   }
	   }
	   }
	   if(flag==false)
	   {
	   cout<<val<<" not found in binary search tree";
	   }
	   }
	 */
  }

};

int
main ()
{
  bst b1;
  int n, val, choice, y = 1;
  while (y == 1)
	{
	  cout <<
		"\n Menu \n 1.create tree \n 2.preorder display \n 3.inoreder display \n  4.insert node in binary search tree \n 5.Longest path \n 6.Minimum data value \n 7.Swap binary search tree\n 8.Search value in binary search tree \n 0.Exit \n Enter choice=";
	  cin >> choice;
	  switch (choice)
		{
		case 1:
		  cout << "how many nodes do you want to insert =";
		  cin >> n;
		  for (int i = 0; i < n; i++)
			{
			  cout << "Enter number =";
			  cin >> val;
			  b1.head = b1.insert (b1.head, val);
			}
		  break;
		case 2:
		  b1.preorder (b1.head);
		  break;
		case 3:
		  cout<<"\n inorder travsersal";
		  b1.inorder (b1.head);
		  break;
		case 4:
		  cout << "\n Enter node number=";
		  cin >> val;
		  b1.head = b1.insert (b1.head, val);
		  break;
		case 5:
		  b1.longest ();
		  break;
		case 6:
		  b1.minimumval ();
		  break;
		case 7:
		  b1.swaptree (b1.head);
		  break;
		case 8:
		  cout << "Enter number to be searched";
		  cin >> val;
		  b1.searchval (b1.head, val);
		  break;
		case 0:
		  y = 0;
		  break;
		}
	}
  return 0;
}
