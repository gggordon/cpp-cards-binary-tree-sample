#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "Card.h"

class TreeNode {
private:
	Card data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode() {
		this->left = NULL; this->right = NULL;
	}

	TreeNode(Card data) : TreeNode(data, NULL, NULL) {
	}
	TreeNode(Card data, TreeNode* left, TreeNode* right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}

	Card getData() {
		return data;
	}

	TreeNode* getLeft() {
		return left;
	}

	TreeNode* getRight() {
		return right;
	}

	void setData(Card data) {
		this->data = data;
	}

	void setLeft(TreeNode* left){
		this->left = left;
	}

	void setRight(TreeNode* right) {
		this->right = right;
	}

	void display() {
		cout << "TreeNode [ data=";
		data.display();
		cout << ", left = " << (left == NULL ? "null" : "not null");
		cout << ", right = " << (right == NULL ? "null" : "not null");
		cout << "]" << endl;
	}

	~TreeNode() {}
};

#endif