#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item();
  Item(char* pName, char* pDescription);
 protected:
  char* name;
  char* description;
};

#endif
