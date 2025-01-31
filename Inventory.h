#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>
#include "item.h"
using namespace std;

enum Status {
	FULL_HEAVY,
	FULL,
	HEAVY,
	SUCCESS
};

class Inventory {
private:
	float maxWeight;
	int maxItems;
	vector<Item> items;
	int findSmallest(string name);
public:
	Inventory(float w, int i);
	float getMaxWeight();
	int getMaxItems();
	void setMaxWeight(float w);
	void setMaxItems(int i);
	optional<Item> withdrawItem(string);
	Status depositItem(Item&);
	void checkDepositStatus(Status depStat);
	vector<Item> getItems();
};

#endif 
