#include "Inventory.h"
#include <optional>

using namespace std;

Inventory::Inventory(float w, int i) : maxWeight(w), maxItems(i) {
	if (w < 0) {
		throw "Max weight cant be negative";
	}
	if (i % 8 != 0) {
		throw "Max items arent divided by 8";
	}
};

float Inventory::getMaxWeight() {
	return maxWeight;
};

int Inventory::getMaxItems() {
	return maxItems;
};

void Inventory::setMaxWeight(float w) {
	if (w < maxWeight) {
		throw "Cant decrease max weight";
	}
};

void Inventory::setMaxItems(int i) {
	if (i < maxItems) {
		throw "Cant decrease max items";
	}
	if (i % 8 != 0) {
		throw "Max items arent divided by 8";
	}
};

int Inventory::findSmallest(string name) {
	int size = items.size();
	int smallest = 0;
	int matchCnt = -1;
	int i;

	for (i = 0; i < items.size(); i++) {

		if (items[i].getName() == name) {
			matchCnt++;
			if (items[i].getQuantity() < items[smallest].getQuantity()) {
				smallest = i;
			}
		}
	}

	if (matchCnt == -1) {
		smallest = -1;
	}

	return smallest;
}

optional<Item> Inventory::withdrawItem(string name) {
	int size = items.size();
	if (size == 0) {
		return nullopt;
	}

	int index = findSmallest(name);
	if (index < 0) {
		return nullopt;
	}

	int quant = items[index].getQuantity();
	float weightStack = items[index].getStackWeight();
	float currWeg = items[index].getWeight();
	Item removedIt = items[index];


	if (quant == 1) {
		items.erase(items.begin() + index);
		return removedIt;
	}
	if (quant > 1) {
		quant -= 1;
		weightStack -= currWeg;

		if (quant == 0) {
			items.erase(items.begin() + index);
			return removedIt;
		}
		items[index].setQuantity(quant);
		items[index].setStackWeight(weightStack);
		return removedIt;
	}

	return nullopt;
}

Status Inventory::depositItem(Item& it) {
	float currWeight = 0;
	int sizeTot = items.size();
	float incomingWeight = it.getWeight();
	float incomingStackWeight = it.getStackWeight();
	int incomingQuantity = it.getQuantity();
	string incomingName = it.getName();
	int stackLimit = 64;
	bool is_too_full = (sizeTot > getMaxItems());
	bool is_too_heavy = ((incomingStackWeight + currWeight) > getMaxWeight());

	for (int i = 0; i < sizeTot; i++)
	{
		currWeight += items[i].getStackWeight();
	}
	if (is_too_full && is_too_heavy) {
		return FULL_HEAVY;
	}
	if (is_too_full) {
		return FULL;
	}
	if (is_too_heavy) {
		return HEAVY;
	}
	if (incomingQuantity > stackLimit) {
		int remainingQuant = incomingQuantity;

		while (remainingQuant > stackLimit) {
			Item newIt = it;
			newIt.setQuantity(stackLimit);
			newIt.setStackWeight(incomingWeight * stackLimit);

			items.push_back(newIt);
			remainingQuant -= stackLimit;
		}
		if (remainingQuant > 0) {
			it.setQuantity(remainingQuant);
			it.setStackWeight(incomingWeight * remainingQuant);
			items.push_back(it);
		}
		return SUCCESS;
	}
	for (int i = 0; i < items.size(); i++) {
		bool is_same_name = (items[i].getName() == incomingName);
		bool is_same_weight = (items[i].getWeight() == incomingWeight);
		int totalQuant = items[i].getQuantity() + incomingQuantity;

		if (is_same_name && is_same_weight) {
			if (totalQuant < stackLimit) {
				items[i].setQuantity(totalQuant);
				items[i].setStackWeight(totalQuant * items[i].getWeight());
				return SUCCESS;
			}
			else {
				int execssQuant = totalQuant - stackLimit;
				items[i].setQuantity(stackLimit);
				items[i].setStackWeight(stackLimit * items[i].getWeight());

				incomingQuantity = execssQuant;
				incomingStackWeight = execssQuant * incomingWeight;
				it.setQuantity(incomingQuantity);
				it.setStackWeight(incomingStackWeight);
			}
		}

	}
	items.push_back(it);
	return SUCCESS;
};

void Inventory::checkDepositStatus(Status depStat) {
	if (depStat == FULL_HEAVY) {
		cout << "Its full and too heavy" << endl;
	}
	else if (depStat == FULL) {
		cout << "Its full" << endl;
	}
	else if (depStat == HEAVY) {
		cout << "Its too heavy" << endl;
	}
	else if (depStat == SUCCESS)
	{
		cout << "Success, everything went well" << endl;
	}
}

vector<Item> Inventory::getItems() {
	int size = items.size();

	vector<Item> v2 = items;

	for (int i = 0; i < items.size(); i++)
	{
		cout << endl;
		cout << "after" << endl;
		cout << "Name: " << items[i].getName() << endl;
		cout << "Weight: " << items[i].getWeight() << endl;
		cout << "Quantity: " << items[i].getQuantity() << endl;
		cout << "Stack weight: " << items[i].getStackWeight() << endl;
	}

	return v2;
}

