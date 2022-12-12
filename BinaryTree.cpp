#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
	root = NULL;
}

node* BinaryTree::insert2(node* temp, node* newnode)
{
	if (temp == NULL)
		temp = newnode;

	else if (temp->info < newnode->info) {
		insert2(temp->Right, newnode);

		if (temp->Right == NULL)
			temp->Right = newnode;
	}
	else {
		insert2(temp->Left, newnode);
		if (temp->Left == NULL)
			temp->Left = newnode;
	}

	return temp;
}

void BinaryTree::insert1(int n)
{
	// node* temp = root;
	// node* newnode;
	node* temp = root, * newnode;
	newnode = new node;
	newnode->Left = NULL;
	newnode->Right = NULL;
	newnode->info = n;
	root = insert2(temp, newnode);
}

void BinaryTree::pretrav(node* t)
{
	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else if (t != NULL) {
		cout << t->info << " ";
		pretrav(t->Left);
		pretrav(t->Right);
	}
}

void BinaryTree::intrav(node* t)
{
	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else if (t != NULL) {
		intrav(t->Left);
		cout << t->info << " ";
		intrav(t->Right);
	}
}

void BinaryTree::posttrav(node* t)
{
	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else if (t != NULL) {
		posttrav(t->Left);
		posttrav(t->Right);
		cout << t->info << " ";
	}
}

void BinaryTree::Delete(int key)
{
	node* temp = root, * parent = root, * marker;
	if (temp == NULL)
		cout << "Tree is empty!" << endl;
	else {
		while (temp != NULL && temp->info != key) {
			parent = temp;
			if (temp->info < key)
				temp = temp->Right;
			else
				temp = temp->Left;
		}
	}

	marker = temp;
	if (temp == NULL)
		cout << "Value not found!" << endl;
	else if (temp == root) {
		if (temp->Right == NULL && temp->Left == NULL)
			root = NULL;
		else if (temp->Left == NULL)
			root = temp->Right;
		else if (temp->Right == NULL)
			root = temp->Left;
		else {
			node* temp1;
			temp1 = temp->Right;
			while (temp1->Left != NULL) {
				temp = temp1;
				temp1 = temp1->Left;
			}
			if (temp1 != temp->Right) {
				temp->Left = temp1->Right;
				temp1->Right = root->Right;
			}
			temp1->Left = root->Left;
			root = temp1;
		}
	}
	else {
		if (temp->Right == NULL && temp->Left == NULL) {
			if (parent->Right == temp)
				parent->Right = NULL;
			else
				parent->Left = NULL;
		}
		else if (temp->Left == NULL) {
			if (parent->Right == temp)
				parent->Right = temp->Right;
			else
				parent->Left = temp->Right;
		}
		else if (temp->Right == NULL) {
			if (parent->Right == temp)
				parent->Right = temp->Left;
			else
				parent->Left = temp->Left;
		}
		else {
			node* temp1;
			parent = temp;
			temp1 = temp->Right;
			while (temp1->Left != NULL) {
				parent = temp1;
				temp1 = temp1->Left;
			}
			if (temp1 != temp->Right) {
				temp->Left = temp1->Right;
				temp1->Right = parent->Right;
			}
			temp1->Left = parent->Left;
			parent = temp1;
		}
	}
	delete marker;
}