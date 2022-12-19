#include "Inventory.h"

Inventory::Inventory(){
  
}

void Inventory::addItem(Item* itemName){
  itemVect.push_back(itemName);
}

// Goes through inventory, deletes element if name matches user input
void Inventory::removeItem(char* itemName){
  for(std::vector<Item*>::iterator i=itemVect.begin(); i!=itemVect.end(); i++){
    Item* m = *i;
    if((strcmp(m->getName(),itemName)) == 0){
      itemVect.erase(i);
      break;
    }
  }
}


// Returns bool based on whether the item is in the inventory
bool Inventory::searchInventory(char* itemName){
  for(std::vector<Item*>::iterator i=itemVect.begin(); i!=itemVect.end(); i++){
    Item* m = *i;
    if((strcmp(m->getName(),itemName)) == 0){
      return true;
    }
  }
  return false;
}

// Returns item based on name
Item* Inventory::returnItem(char* itemName){
  for(std::vector<Item*>::iterator i=itemVect.begin(); i!=itemVect.end(); i++){
    Item* m = *i;
     if((strcmp(m->getName(),itemName)) == 0){
      return m;
    }
  }
  return NULL;
}

// Prints all elements of inventory
void Inventory::printInventory(){
  for(std::vector<Item*>::iterator i=itemVect.begin(); i!=itemVect.end(); i++){
    Item* m = *i;
    cout << m->getName() << endl;
  }
}


Inventory::~Inventory(){
  delete[] name;
  delete[] description;
}