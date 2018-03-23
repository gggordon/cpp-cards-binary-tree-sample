#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
private:
	int number;
	string suite;

public:
	Card():Card(0) {
	}

	Card(int number) : Card(number,"") {
	}

	Card(int number, string suite) {
		this->number = number;
		this->suite = suite;
	}

	Card(const Card & card) {
		number = card.number;
		suite = card.suite;
	}

	int getNumber() {
		return number;
	}

	string getSuite() {
		return suite;
	}

	void setNumber(int number) {
		this->number = number;
	}

	void setSuite(string suite) {
		this->suite = suite;
	}

	bool isGreaterThan(Card otherCard) {
	    //if(otherCard == null)return false;//<<java
		if (otherCard.getNumber() > this->getNumber()) {
			return true;
		}
		else {
			return false;
		}
	}

	void display() {
		cout << "Card [number=" << number << ", suite="
			<< suite << "]" << endl;
	}

	~Card() {}

};



#endif