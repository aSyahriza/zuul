#include "Item.h"

Item::Item(){
  name = new char[80];
}

Item::Item(const char* pName){
  name = new char[80];
  strcpy(name,pName);
}

Item::~Item(){
  delete[] name;
}

char* Item::getName(){
  return name;
}