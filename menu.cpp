#include "menu.h"

void safeInp(int* x, string prompt) {
	while (true) {
		cout << prompt;
		cin >> *x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
		}
		else {
			break;
		}
	}
}

Inventory safeInventory() {
	bool error = true;
	int maxWeight;
	int maxItems;
	while (error) {

		string weightPrompt = "Enter max weight: ";
		safeInp(&maxWeight, weightPrompt);

		string itemsPrompt = "Enter max items: ";
		safeInp(&maxItems, itemsPrompt);

		try {
			Inventory inv1(maxWeight, maxItems);
			error = true;
			return inv1;
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
}

Item safeItem() {
	bool error = true;
	float weight;
	int quantity;
	float stackWeight;
	string name;
	while (error) {

		cout << "Enter item weight: ";
		cin >> weight;

		cout << "Enter item name: ";
		cin >> name;

		string quantityPrompt = "Enter item quanity: ";
		safeInp(&quantity, quantityPrompt);

		stackWeight = weight * quantity;

		try {
			Item it1(weight, name, quantity, stackWeight);
			error = true;
			return it1;
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
}
