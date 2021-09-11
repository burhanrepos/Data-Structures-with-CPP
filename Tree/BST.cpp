#include<iostream>
using namespace std;
template<class T>
class node
{
public:
	T data;
	node<T> *left;
	node<T> *right;
	node<T> *parent;
	node<T>():left(NULL),right(NULL),parent(NULL){}
};
template<class T>
class tree
{
public:
	void inorder(node<T>* root);
	void preorder(node<T>* root);
	void postorder(node<T>* root);
	node<T>* newnode(T data);//Making a node when there is a need of it
	node<T>* successor( node<T>* searchNode);
	node<T>* predecessor(node<T>* searchNode);
	node<T>* find_minimum(node<T>* root);
	node<T>* find_maximum(node<T>* root);
	node<T>* Search(node<T>* root, T data);
	node<T>* insert(node<T>* root, T data);
	node<T>* Delete(node<T>* root, T data);
};
template<class T>
node<T>* tree<T>::newnode(T data)
{
	node<T>* newNode = new node<T>;
	newNode->data = data;
	newNode->left = newNode->right = newNode->parent = NULL;
	return newNode;
}
template<class T>
node<T>* tree<T>::find_maximum(node<T>* root)
{
	if (root == NULL)
		return NULL;
	while (root->right != NULL)
		root = root->right;
	return root;
}
template<class T>
node<T>* tree<T>::find_minimum(node<T>* root)
{
	if (root == NULL)
		return NULL;
	while (root->left != NULL)
		root = root->left;
	return root;
}
template<class T>
node<T>* tree<T>::Search(node<T>* root, T data)
{
	if (root == NULL || data == root->data )
		return root;
	if (data <=  root->data)
		return Search(root->left , data);
	else
		return Search(root->right, data);
}
template<class T>
node<T>* tree<T>::insert(node<T>* root, T data)
{
	//we use recursion for inserting a node in bst
	if (root == NULL)
		root = newnode(data);
	else if (data <= root->data)
	{
		root->left = insert(root->left, data);
		root->left->parent = root;//Parent of Root ha P->parent
	}
	else
	{
		root->right = insert(root->right, data);
		root->right->parent = root;
	}
	return root;
}
template<class T>
node<T>* tree<T>::Delete(node<T>* root, T data)
{
	if (root == NULL)
		return NULL;
	else if (data < root->data) 
		root->left = Delete(root->left, data);
	else if (data > root->data)
		root->right = Delete(root->right, data);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if (root->left == NULL)
		{
			node<T>* temp = root;
			root = root->right;
			cout << "Deleted Data : " << root->data << endl;
			delete temp;
		}
		else if (root->right == NULL)
		{
			node<T>* temp = root;
			root = root->left;
			cout << "Deleted Data : " << temp->data << endl;
			delete temp;
		}
		else
		{
			cout << "Deleted Data : " << root->data << endl;
			node<T>* min = find_minimum(root->right);
			root->data = min->data;
			root->right = Delete(root->right, min->data);
		}
	}
	return root;
}
template<class T>
void tree<T>::inorder(node<T>* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " , ";
	inorder(root->right);
}
template<class T>
void tree<T>::preorder(node<T>* root)
{
	if (root == NULL)
		return;
	cout << root->data << " , ";
	preorder(root->left);
	preorder(root->right);
}
template<class T>
void tree<T>::postorder(node<T>* root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " , ";
}
template<class T>
node<T>* tree<T>::successor(node<T>* searchNode)
{
	// If Node has Right Subtree
	if (searchNode->right != NULL)
		return find_minimum(searchNode->right);
	node<T>* par = searchNode->parent;
	while (par  != NULL && searchNode == par->right)
	{
		searchNode = par;
		par  = par->parent;
	}
	return par;//parent of last left
}
template<class T>
node<T>* tree<T>::predecessor(node<T>* searchNode)
{
	if (searchNode->left != NULL)
		return find_maximum(searchNode->left);
	node<T>* par = searchNode->parent;
	while (par != NULL && searchNode == par->left)
	{
		searchNode = par;
		par = par->parent;
	}
	return par;
}
template<class T>
void tree_traversal(tree<T> t, node<T>* root)
{
	int ch;
	do
	{
		cout << "------ Sub Menu From tree Traversal ----\n";
		cout << "1) Inorder \n";
		cout << "2) Preorder \n";
		cout << "3) Postorder \n";
		cout << "4) Back To Main Menu \n";
		cout << "Enter Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1: 
			t.inorder(root);
			cout << endl;
			break;
		case 2:
			t.preorder(root);
			cout << endl;
			break;
		case 3:
			t.postorder(root);
			cout << endl;
			break;
		case 4:
			break;
		}
	} while (ch != 4);
}
int main()
{
	tree<int> t;
	node<int> *root = NULL;
	int data,ch;
	int count = 0;
	do
	{
		cout << "---------------- Main Menu -----------------\n\n";
		cout << "1 ) Insert in BST \n\n";
		cout << "2 ) Delete in BST \n\n";
		cout << "3 ) Successor \n\n";
		cout << "4 ) Predecessor\n\n";
		cout << "5 ) Minimum in BST \n\n";
		cout << "6 ) Maximum in BST \n\n";
		cout << "7 ) Searching in BST\n\n";
		cout << "8) Tree Traversal \n\n";
		cout << "9 ) Exit\n\n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter Data On Node : ";
			cin >> data;
			if (count == 0)
				root = t.insert(root, data);
			else
				t.insert(root, data);
			count++;
			break;
		case 2:
			if (count > 0)
			{
				node<int>* res;
				cout << "Enter Data On Node : ";
				cin >> data;
				res = t.Delete(root, data);
				count--;
			}
			else
				cout << "Tree is Empty\n\n";
			break;
		case 3:
			if (count > 0)
			{
				node<int>* res;
				node<int>* searchNode;
				cout << "Enter Data for Which you want to find Successor : ";
				cin >> data;
				searchNode = t.Search(root, data);
				res = t.successor(searchNode);
				if (res == NULL)
					cout << "Successor Not Found\n";
				else
					cout << res->data << endl;
			}
			else
				cout << "Tree is Empty\n\n";
			break;
		case 4:
			if (count > 0)
			{
				node<int>* res1;
				node<int>* searchNode;
				cout << "Enter Data for Which you want to find Predeccessor : ";
				cin >> data;
				searchNode = t.Search(root, data);
				res1 = t.predecessor(searchNode);
				if (res1)
					cout << res1->data << endl;
				else
					cout << "Predeccessor Not Exists\n";
			}
			else
				cout << "Tree is Empty\n\n";
			break;
		case 5:
			if (count > 0)
			{
				node<int>* res2;
				res2 = t.find_minimum(root);
				cout << res2->data << endl;
			}
			else
				cout << "Tree is Empty\n\n";
			break;
		case 6:
			if (count > 0)
			{
				node<int>* res3;
				res3 = t.find_maximum(root);
				cout << res3->data << endl;
			}
			else
				cout << "Tree is Empty\n\n";
			break;
		case 7:
			if (count > 0)
			{
				node<int>* searchNode;
				cout << "Enter Data for Searching : ";
				cin >> data;
				searchNode = t.Search(root, data);
				if (searchNode)
					cout << "Data is Found "<< endl;
				else
					cout << "Data is not Found \n";
			}
			else
				cout << "Tree is Empty\n\n";
			break;
		case 8:
			if (count > 0)
				tree_traversal(t, root);
			else
				cout << "Tree is Empty\n\n";
			break;
		case 9:
			exit(-1);
		}
	} while (true);
	system("pause");
}
