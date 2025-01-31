#include <iostream>
#include <string>
#include "item.h"
using namespace std;

Item::Item(float w, string n, int q, float sw) : weight(w), name(n), quantity(q), stackWeight(sw) {
	if (w < 0) {
		throw "Weight cant be negative";
	}
	if(q < 0) {
		throw "Quantity cant be negative";
	}
}

string Item::getName() {
	return name;
}

float Item::getWeight() {
	return weight;
}

int Item::getQuantity() {
	return quantity;
}

float Item::getStackWeight(){
	return stackWeight;
}

void Item::setQuantity(int q){
	quantity = q;
}

void Item::setStackWeight(float nw){
	stackWeight = nw;
}
