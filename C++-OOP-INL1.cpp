#include "Inventory.h"
#include "item.h"
#include "menu.h"
using namespace std;

int main() {
	cout << "Welcome to my Inventory application." << endl;

	cout << "Inventory creation:" << endl;
	Inventory inv = safeInventory();

	cout << "Item creation:" << endl;
	optional<Item> it = safeItem();

	//cout << "Item creation:" << endl;
	//Item it2 = safeItem();

	Status depositStatus = inv.depositItem(it.value());
	inv.checkDepositStatus(depositStatus);

	//Status depositStatus2 = inv.depositItem(it2);
	//inv.checkDepositStatus(depositStatus2);

	inv.getItems();

	cout << endl;

	string name;	
	cout << "Enter an item name to withdraw: ";
	cin >> name;
	it = inv.withdrawItem(name);
	if (it.has_value()) {
		cout << "Success, item withdrewn!" << endl;
	}
	else {
		cout << "Error, Cant withdraw item" << endl;
	}

	//it = inv.withdrawItem(it.getName());
	//it2 = inv.withdrawItem("a");
	//it2 = inv.withdrawItem("a");
	inv.getItems();


	/*cout << "This is the withdraw item screen" << endl;
	try {
		while (1) {
			string name;
			cout << "Enter an item name to withdraw: ";
			cin >> name;

			if (name == it.getName()) {
				cout << "It exists" << endl;
				it = inv.withdrawItem(name);
				break;
			}
			if (name == it2.getName()) {
				cout << "It exists" << endl;
				it2 = inv.withdrawItem(name);
				break;
			}
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}*/

	//inv.getItems();
}
