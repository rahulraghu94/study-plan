#include <iostream>
#include <algorithm>
#include <queue>
#include "bst.h"

using namespace std;

bstnode* create_node(int data)
{
	struct bstnode *newnode = (struct bstnode *)malloc(sizeof(struct bstnode));
	newnode->key= data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

bstnode* insert(bstnode * root, int data)
{
	if(root == NULL){
		root = create_node(data);
		return root;
	} else if (data <= root->key){
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}

	return root;
}

int search(bstnode *root, int key)
{
	if(root == NULL){
		return 0;
	} else if (root->key == key){
		return 1;
	} else if (root->key < key){
		return search(root->right, key);
	} else {
		return search(root->left, key);
	}
}

int find_min(bstnode *root)
{
	struct bstnode* cur = root;

	if(root == NULL){
		cout << "Tree is empty!" << endl;
		return 0;
	}

	while(cur->left){
		cur = cur->left;
	}

	return cur->key;
}

int find_max(bstnode *root)
{
	if(root == NULL){
		cout << "Tree is empty!" << endl;
		return 0;
	}

	while(root->right) {
		root = root->right;
	}

	return root->key;
}

int find_height(bstnode *root)
{
	if(root == NULL)
		return -1;

	return max(find_height(root->left), find_height(root->right)) +1;
}

void inorder(bstnode *root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	cout << root->key << "\t" ;
	inorder(root->right);
}

void preorder(bstnode *root)
{
	if(root == NULL)
		return;

	cout << root->key << "\t" ;
	preorder(root->left);
	preorder(root->right);

}

void postorder(bstnode *root)
{
	if(root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->key << "\t" ;

}

void levelorder(bstnode *root)
{
	queue<bstnode *> q;

	if(root == NULL)
		return;

	q.push(root);

	while(!q.empty()){
		bstnode *cur = q.front();

		cout << cur->key << "\t";

		if(cur->left)
			q.push(cur->left);

		if(cur->right)
			q.push(cur->right);

		q.pop();
 	}

 	return;
}