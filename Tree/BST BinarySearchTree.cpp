#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node *left, *right,*parent;;
};
Node* Search(Node* root, int data);
Node* insert(Node* root, int data);
Node* Delete(Node* root, int data);
Node* FindMax(Node* root);
Node* successor(Node* search);
Node* FindMin(Node* root);
void preorder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->info << " , ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	Node *root = NULL;
	int data;
	//InsertData
	root=insert(root, 12);
	insert(root, 15);
	insert(root, 9);
	insert(root, 8);
	system("pause");
	preorder(root);
	cout << endl;
	system("pause");
	//Delete Data
	cout << "Enter Data for Deletion : ";
	cin >> data;
	Delete(root, data);
	system("pause");
	//Preordertraversal
	preorder(root);
	cout << endl;
	system("pause");
	//Successor
	Node *search,*res;
	cout << "Enter Data for Which you want to find Successor : ";
	cin >> data;
	search = Search(root, data);
	res = successor(search);
	if (res == NULL)
		cout << "Successor Not Found\n";
	else
		cout << res->info << endl;
	cout << endl;
	system("pause");
}
Node* successor(Node* search)
{
	if (search->right != NULL)
		return FindMin(search->right);
	Node* parent = search->parent;
	while (parent != NULL && search == parent->right)
	{
		search = parent;
		parent = parent->parent;
	}
	return parent;
}
Node* Search(Node* root, int data)
{
	if (root == NULL)
		return NULL;
	if (data < root->info)
		return Search(root->left, data);
	else if (data > root->info)
		return Search(root->right, data);
	return root;
}
Node* insert(Node* root, int data)
{
	Node *newnode;
	newnode = new Node;
	newnode->info = data;
	newnode->left = newnode->right =newnode->parent= NULL;
	if (root == NULL)
		root = newnode;
	else if (data < root->info)
	{
		root->left = insert(root->left, data);
		root->left->parent = root;
	}
	else
	{
		root->right = insert(root->right, data);
		root->right->parent = root;
	}
	return root;

}
Node* FindMax(Node* root)
{
	Node* Max = NULL;
	while (root->right != NULL)
	{
		Max = root->right;
	}
	return Max;
}
Node* FindMin(Node* root)
{
	Node* Min = NULL;
	while (root->left != NULL)
	{
		Min = root->right;
	}
	return Min;
}
Node* Delete(Node* root, int data)
{
	Node* temp;
	if (root == NULL)
		cout << "No Such Element Exits\n";
	else if (data < root->info)//deletion node tak ponchny k liye
		root->left = Delete(root->left, data);
	else if (data > root->info)
		root->right = Delete(root->right, data);
	else
	{
		if (root->left&& root->right)//deleted node having two child         
		{
			temp = FindMax(root->left);
			cout << temp->info << endl;
			root->info = temp->info;
			root->left = Delete(root->left, root->info);
		}
		else//having only one child
		{
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
		}
	}
	return root;
}

