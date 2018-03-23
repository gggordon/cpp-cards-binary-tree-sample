#ifndef TREE_H
#define TREE_H

#include "Card.h"
#include "TreeNode.h"

class Tree {
private:
	TreeNode * root;

public:
	Tree() {
		root = NULL;
	}

	bool isEmpty() {
		return root == NULL;
	}

	bool isFull() {
		TreeNode* temp = new TreeNode();
		if (temp == NULL) {
			return true;
		}
		else {
			delete temp;
			return false;
		}
	}

	void insert(Card data) {
		if (isFull()) {
			cout << "Unable to insert, tree is full" << endl;
		}
		else {
			TreeNode* temp = new TreeNode(data);
			if (isEmpty()) {
				root = temp;
			}
			else {
				TreeNode * current = root;
				while (true) {
					if (current->getData().isGreaterThan(data)) {
					   //since card is greater than, insert on right

						//check if right is null before inserting
						if (current->getRight() == NULL) {
							current->setRight(temp);//add node to right portino
							break;
						}
						else {
							//iterate to next right node
							current = current->getRight();
						}
					}
					else {//since card is less than or equal to, insert on left
						
						//check if left is null before inserting
						if (current->getLeft() == NULL) {
							current->setLeft(temp);
							break;
						}
						else {
							//iterate to next left node
							current = current->getLeft();
						}

					}
				}
			}
		}
	}

	void display() {
		displayInOrder(root);
	}

	void displayInOrder() {
		displayInOrder(root);
	}

	void displayPreOrder() {
		displayPreOrder(root);
	}

	bool remove(int cardNumber) {
		if (root == NULL) {
			return false;
		}
		else {
			if (root->getData().getNumber() == cardNumber) {
				TreeNode tempSubRoot;
				tempSubRoot.setLeft(root);

				TreeNode* removedNode = root->remove(cardNumber, &tempSubRoot);
				root = tempSubRoot.getLeft();

				if (removedNode != NULL) {
					delete removedNode;
					return true;
				}
				else {
					return false;
				}
			}
			else {
				TreeNode* removedNode = root->remove(cardNumber, NULL);
				if (removedNode != NULL) {
					delete removedNode;
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	
	~Tree() {}

protected:
	void displayInOrder(TreeNode* current) {
		if (current == NULL)return;
		displayInOrder(current->getLeft());
		current->display();
		displayInOrder(current->getRight());
	}

	void displayPreOrder(TreeNode* current) {
		if (current == NULL)return;
		current->display();
		displayPreOrder(current->getLeft());
		displayPreOrder(current->getRight());
	}
};

#endif