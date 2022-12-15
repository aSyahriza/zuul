#include "Room.h"

Room::Room(){
  name = new char[80];
  description = new char[80];
}

Room::Room(char* pName, char* pDescription){
  name = new char[80];
  description = new char[80];
  strcpy(name,pRoomName);
  strcpy(description, pDescription);
}




