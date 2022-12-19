#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "Item.h"


using namespace std;

class Room {
 public:
  Room();
  Room(char* pName);
  map<char,Room*> rExitMap;
  vector<Item*> rItemVect;
 protected:
  char* name;
};

#endif
