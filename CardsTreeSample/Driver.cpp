#include "Card.h"
#include "Tree.h"
#include <cstdlib>
#include <cmath>




int main() {
	
	
	Tree *deck = new Tree();
	
	
	for (int i = 0;i < 4;i++) {
		Card c(rand()%10);
		deck->insert(c);
		cout << "Inserted : ";
		c.display();
	}

	

	cout << "InOrder Display" << endl;
	deck->displayInOrder();
	cout << "PreOrder Display" << endl;
	deck->displayPreOrder();
	
	system("pause");
	return 0;
}