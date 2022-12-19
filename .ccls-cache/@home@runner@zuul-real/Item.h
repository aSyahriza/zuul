#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item();
  Item(const char* pName);
  ~Item();
  char* getName();
 protected:
  char* name;
};

#endif