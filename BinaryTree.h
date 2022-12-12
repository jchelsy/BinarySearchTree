#pragma once
#include <iostream>
#include "Node.h"

using namespace std;


class BinaryTree {
public:
	node* root;

	BinaryTree();

	void insert1(int);
	node* insert2(node*, node*);

	void Delete(int);
	void pretrav(node*);
	void intrav(node*);
	void posttrav(node*);
};