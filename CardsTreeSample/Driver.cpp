#include "Card.h"
#include "Tree.h"
#include <cstdlib>
#include <cmath>




int main() {
	
	
	Tree *deck = new Tree();
	int numbersToBeDeleted[4];
	int numberToBeDeleted = 0;
	for (int i = 0;i < 4;i++) {
		numbersToBeDeleted[i]=numberToBeDeleted = rand() % 10;
		Card c(numberToBeDeleted);
		deck->insert(c);
		cout << "Inserted : ";
		c.display();
	}

	

	cout << "InOrder Display" << endl;
	deck->displayInOrder();
	cout << "PreOrder Display" << endl;
	deck->displayPreOrder();

	cout << "Deleting : " << numberToBeDeleted << endl;
	if (deck->remove(numberToBeDeleted)) {
		cout << "Deleted Card with number : " << numberToBeDeleted << endl;
	}else{
		cout << "Did not delete Card with number : " << numberToBeDeleted << endl;
	}


	
	system("pause");
	return 0;
}