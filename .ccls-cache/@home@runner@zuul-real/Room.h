#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "Item.h"
#include "Inventory.h"


using namespace std;

class Room {
 public:
  Room();
  Room(const char* pName,const char* pDescription);
  ~Room();
  char* getName();
  char* getDescription();
  map<char,Room*> exitMap;
  vector<Item*> rItemVect;
  Inventory roomInventory;

  protected:  
  char* name;
  char* description;
};

#endif