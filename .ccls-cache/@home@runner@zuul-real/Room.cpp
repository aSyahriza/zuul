#include "Room.h"

Room::Room(){
  name = new char[80];
  description = new char[100];
}

Room::Room(const char* pName, const char* pDescription){
  name = new char[80];
  description = new char[100];
  strcpy(name,pName);
  strcpy(description, pDescription);
}



char* Room::getName(){
  return name;
}

char* Room::getDescription(){
  return description;
}

Room::~Room(){
  delete[] name;
  delete[] char;
}