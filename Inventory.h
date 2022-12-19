#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "Item.h"


using namespace std;

class Inventory {
 public:
  Inventory();
  void addItem(Item* itemName);
  void removeItem(char* itemName);
  bool searchInventory(char* itemName);
  Item* returnItem(char* itemName);
  void printInventory();
  ~Inventory();
  vector<Item*> itemVect;

  protected:  
  char* name;
  char* description;
};

#endif