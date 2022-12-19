#include "Item.h"

Item::Item(){
  name = new char[80];
  description = new char[80];
}

Item::Item(char* pName, char* pDescription){
  name = new char[80];
  description = new char[80];
  strcpy(name,pName);
  strcpy(description,pName);
}
