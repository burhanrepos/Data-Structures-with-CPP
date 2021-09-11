#include<iostream>
using namespace std;
template<class T>
class node
{
public:
	int data;
	node<T>* left;
	node<T>* right;
	node<T>():left(NULL),right(NULL){}
};
template<class T>
class AVL
{
	node<T> *cur, *pre, *root;
public:
	int  heightAVL(node<T>* nsnode);
	int  balancFactor(node<T>* nsnode);
	node<T>* rrRotation(node<T>* nsnode);
	node<T>* llRotation(node<T>* nsnode);
	node<T>* lrRotation(node<T>* nsnode);
	node<T>* rlRotation(node<T>* nsnode);
	node<T>* BalanceTree(node<T>* nsnode);
	node<T>* Insertion(node<T>* nsnode, int data);
	node<T>* Deletion(node<T>* nsnode, int data);
	node<T>* find_minimum(node<T>* root);
	void inorder(node<T>* nsnode);
	void preorder(node<T>* nsnode);
	void postorder(node<T>* nsnode);

};
template<class T>
node<T>* AVL<T>::find_minimum(node<T>* root)
{
	if (root == NULL)
		return NULL;
	while (root->left != NULL)
		root = root->left;
	return root;
}
template<class T>
int AVL<T>::heightAVL(node<T>* nsnode)
{
	int height = 0;
	int l_height, r_height;

	if (nsnode != NULL)
	{
		l_height = heightAVL(nsnode->left);
		r_height = heightAVL(nsnode->right);

		if (l_height > r_height)
			height = l_height + 1;
		else
			height = r_height + 1;
	}
	return height;
}
template<class T>
int AVL<T>::balancFactor(node<T>* nsnode)
{
	int b_factor = 0;
	int l_height, r_height;

	l_height = heightAVL(nsnode->left);
	r_height = heightAVL(nsnode->right);

	b_factor = l_height - r_height;

	return b_factor;
}
template<class T>
node<T>* AVL<T>::rrRotation(node<T>* nsnode)
{
	node<T>* temp;

	temp = nsnode->right;
	nsnode->right = temp->left;
	temp->left = nsnode;

	return temp;
}
template<class T>
node<T>* AVL<T>::llRotation(node<T>* nsnode)
{
	node<T>* temp;

	temp = nsnode->left;
	nsnode->left = temp->right;
	temp->right = nsnode;

	return temp;
}
template<class T>
node<T>* AVL<T>::lrRotation(node<T>* nsnode)
{
	node<T>* temp;

	temp = nsnode->left;
	nsnode->left = rrRotation(temp);

	return llRotation(nsnode);
}
template<class T>
node<T>* AVL<T>::rlRotation(node<T>* nsnode)
{
	node<T>* temp;

	temp = nsnode->right;
	nsnode->left = llRotation(temp);

	return rrRotation(nsnode);
}
template<class T>
node<T>* AVL<T>::BalanceTree(node<T>* nsnode)
{
	int b_factor = balancFactor(nsnode);
	if (b_factor > 1)
	{
		if (balancFactor(nsnode->left) > 0)
			nsnode = llRotation(nsnode);
		else
			nsnode = lrRotation(nsnode);
	}
	if (b_factor < -1)
	{
		if (balancFactor(nsnode->right) > 0)
			nsnode = rlRotation(nsnode);
		else
			nsnode = rrRotation(nsnode);
	}
	return nsnode;
}
template<class T>
node<T>* AVL<T>::Deletion(node<T>* nsnode, int data)
{
	if (nsnode == NULL)
		return NULL;
	else if (data < nsnode->data)
		nsnode->left = Deletion(nsnode->left, data);
	else if (data > nsnode->data)
		nsnode->right = Deletion(nsnode->right, data);
	else
	{
		if (nsnode->left == NULL && nsnode->right == NULL)
		{
			delete nsnode;
			nsnode = NULL;
		}
		else if (nsnode->left == NULL)
		{
			node<T>* temp = nsnode;
			nsnode = nsnode->right;
			cout << "Deleted Data : " << nsnode->data << endl;
			delete temp;
			nsnode = BalanceTree(nsnode);
		}
		else if (nsnode->right == NULL)
		{
			node<T>* temp = nsnode;
			nsnode = nsnode->left;
			cout << "Deleted Data : " << temp->data << endl;
			delete temp;
			nsnode = BalanceTree(nsnode);
		}
		else
		{
			cout << "Deleted Data : " << nsnode->data << endl;
			node<T>* min = find_minimum(nsnode->right);
			nsnode->data = min->data;
			nsnode->right = Deletion(nsnode->right, min->data);
			nsnode = BalanceTree(nsnode);
		}
	}
	return nsnode;

}
template<class T>
node<T>* AVL<T>::Insertion(node<T>* nsnode, int data)
{
	if (nsnode == NULL)
	{
		node<T>* newnode = new node<T>;
		newnode->data = data;
		newnode->left = newnode->right = NULL;
		return newnode;
	}
	else
	{
		if (data <= nsnode->data)
		{
			nsnode->left = Insertion(nsnode->left, data);
			nsnode = BalanceTree(nsnode);
		}
		else
		{
			nsnode->right = Insertion(nsnode->right, data);
			nsnode = BalanceTree(nsnode);
		}
		return nsnode;
	}
}
template<class T>
void AVL<T>::inorder(node<T>* nsnode)
{
	if (nsnode != NULL)
	{
		inorder(nsnode->left);
		cout << nsnode->data << " ";
		inorder(nsnode->right);
	}
}
template<class T>
void AVL<T>::postorder(node<T>* nsnode)
{

	if (nsnode != NULL)
	{
		postorder(nsnode->left);
		postorder(nsnode->right);
		cout << nsnode->data << " ";
	}

}
template<class T>
void AVL<T>::preorder(node<T>* nsnode)
{
	if (nsnode != NULL)
	{
		cout << nsnode->data << " ";
		preorder(nsnode->left);
		preorder(nsnode->right);
	}
}
int main()
{
	node<int>* root = NULL;
	AVL<int> A;
	int ch, data,count;
	count = 0;
	do
	{
		cout << "+++++++++++++     MAIN Menu    ++++++++++++++\n";
		cout << "1) Insertion\n\n";
		cout << "2) Deletion \n\n";
		cout << "3) Display\n\n";
		cout << "4) Exit\n\n";
		cout << "Enter Choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter Data : ";
			cin >> data;
			root = A.Insertion(root, data);
			count++;
			break;
		case 2:
			if (count > 0)
			{
				cout << "Enter Data : ";
				cin >> data;
				A.Deletion(root, data);
			}
			else
				cout << "Tree is Empty \n\n";
			break;
		case 3:
			if (count > 0)
			{
				cout << "Inorder Traversal \n";
				A.inorder(root);
				cout << endl;
				cout << "Preorder Traversal\n";
				A.preorder(root);
				cout << endl;
				cout << "Postorder Traversal\n";
				A.postorder(root);
				cout << endl;
			}
			else
				cout << "Tree is Empty \n\n";
			break;
		case 4:
			exit(-1);
		}
	} while (true);
}