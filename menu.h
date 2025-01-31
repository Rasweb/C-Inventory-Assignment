#ifndef MENU_H
#define MENU_H
#include "Inventory.h"
#include "item.h"
/*
Clears the input buffer by ignoring all chars until a newline 
Numeric: The maximum number of chars to ignore
* Returns the largest possible value for the type streamsize.
*/
void safeInp(int* x, string prompt);
Inventory safeInventory();
Item safeItem();

#endif