#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Item {
private:
	float weight;
	string name;
	int quantity;
	float stackWeight;
public:
	Item(float w, string n, int q, float sw);
	string getName();
	float getWeight();
	int getQuantity();
	float getStackWeight();
	void setQuantity(int q);
	void setStackWeight(float nw);
};

#endif 