/*
* 
* Author: Allam Syahriza  
* Date: 12/18/2022
* This programs creates a text based adventure game where-in the user
* can move between rooms and pick up items. The goal of the game is to 
* go to the vault with the key, where the user can pick up the gold item
* 
*/
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Room.h"
#include "Item.h"

// Function prototypes
void go(Room* &currentRoom,vector<Room*> &roomVect,Inventory &playerInventory);
void get(Room* &currentRoom,vector<Room*> &roomVect, char* itemName,Inventory &playerInventory);
void drop(Room* &currentRoom,vector<Room*> &roomVect, char* itemName,Inventory &playerInventory);

int main(){
  bool loop = true;
  Inventory playerInventory;

  vector<Room*> roomVect;

  // Setting up rooms, adding to vector
  Room* oneTwentyTwo = new Room("1-22","Ms.Smith's Room.");
  roomVect.push_back(oneTwentyTwo);
  
  Room* oneTwentyOne = new Room("1-21","the robotics and CAD room.");
  roomVect.push_back(oneTwentyOne);
  
  Room* oneTwenty = new Room("1-20","Mr. Galbraith's room.");
  roomVect.push_back(oneTwenty);
  
  Room* aOne = new Room("A-1", "Mr. McClain's room.");
  roomVect.push_back(aOne);
  
  Room* kitchen = new Room("The Kitchen", "the place where food is made");
  roomVect.push_back(kitchen);
  
  Room* theatre = new Room("The Theatre", "a large auditorium for performances.");
  roomVect.push_back(theatre);
  
  Room* lab = new Room("The Lab", "a site for tests and experiments and such.");
  roomVect.push_back(lab);
  
  Room* office = new Room("The Office", "a room for the principal and other administrative figures.");
  roomVect.push_back(office);
  
  Room* gym = new Room("The Gym", "a large open gym with hardwood floors.");
  roomVect.push_back(gym);
  
  Room* cafeteria = new Room("The Cafeteria", "a large room with hundreds of tables for students to eat lunch.");
  roomVect.push_back(cafeteria);

  Room* library = new Room("The Library", "a room containing thousands of books.");
  roomVect.push_back(library);
  
  Room* staircase = new Room("The Staircase", "a mysterious winding staircase.");
  roomVect.push_back(staircase);
  
  Room* bathroom = new Room("The Bathroom", "a stinky bathroom." );
  roomVect.push_back(bathroom);
  
  Room* gate = new Room("The Gate", "a rusted metallic gate");
  roomVect.push_back(gate);
  
  Room* vault = new Room("The Vault", "a super secret vault. There's probably something down here.");
  roomVect.push_back(vault);

  // Set up exits
  oneTwentyTwo->exitMap.insert({'E',oneTwentyOne});
  
  oneTwentyOne->exitMap.insert({'W',oneTwentyTwo});
  oneTwentyOne->exitMap.insert({'S',oneTwenty});

  oneTwenty->exitMap.insert({'N',oneTwentyOne});
  oneTwenty->exitMap.insert({'S',aOne});

  aOne->exitMap.insert({'N',oneTwenty});
  aOne->exitMap.insert({'E',theatre});
  aOne->exitMap.insert({'S',lab});
  aOne->exitMap.insert({'W',kitchen});

  kitchen->exitMap.insert({'E',aOne});

  theatre->exitMap.insert({'W',aOne});

  lab->exitMap.insert({'N',aOne});
  lab->exitMap.insert({'E',office});
  lab->exitMap.insert({'S',library});

  office->exitMap.insert({'W',lab});
  office->exitMap.insert({'S',gym});

  bathroom->exitMap.insert({'E',staircase});
  
  staircase->exitMap.insert({'W',bathroom});
  staircase->exitMap.insert({'E',library});
  staircase->exitMap.insert({'S',gate});

  library->exitMap.insert({'W',staircase});
  library->exitMap.insert({'N',lab});

  gym->exitMap.insert({'N',office});
  gym->exitMap.insert({'E',cafeteria});

  cafeteria->exitMap.insert({'W',gym});

  gate->exitMap.insert({'N',staircase});
  gate->exitMap.insert({'S',vault});

  vault->exitMap.insert({'N',gate});

  // Putting items in rooms
  Item* stick = new Item("Stick");
  oneTwentyOne->roomInventory.addItem(stick);
  Item* lego = new Item("Lego Piece");
  oneTwentyOne->roomInventory.addItem(lego);
  
  Item* robot = new Item("Robot");
  oneTwenty->roomInventory.addItem(lego);
  
  Item* key = new Item("Key");
  office->roomInventory.addItem(key);

  Item* basketball = new Item("Basketball");
  gym->roomInventory.addItem(basketball);

  Item* book = new Item("Book");
  library->roomInventory.addItem(book);

  Item* soap = new Item("Soap");
  bathroom->roomInventory.addItem(soap);

  Item* spoon = new Item("Spoon");
  kitchen->roomInventory.addItem(spoon);

  Item* gold = new Item("Gold");
  vault->roomInventory.addItem(gold);

  Item* tissues = new Item("Tissues");
  playerInventory.addItem(tissues);
  
  
  Room* currentRoom;
  currentRoom = oneTwentyOne;

  char* goldd = new char[20];
  strcpy(goldd,"Gold");

  cout << "Welcome!" << endl;
  cout << "Your commands are: " << endl;
  cout << "'GO'\t'GET'\t'DROP'\t'QUIT'" << endl;
  
  while(loop){
    
    // Prints out current room, room description, and room inventory
    cout << "\nYou are in " << currentRoom->getName() << "."<< endl;
    cout << "It is " << currentRoom->getDescription() << endl;  
    cout << "This room contains the following items: " << endl;
    currentRoom->roomInventory.printInventory();
    cout << "\n";
    
    
    // Recieves input from the user
    char userInput[20];
    cin.get(userInput,20);
    cin.ignore(9999,'\n');
    cin.clear();

    if(strcmp(userInput,"GO")==0){ 
      go(currentRoom,roomVect, playerInventory);
    }   

    // Gets item from room
    if(strcmp(userInput,"GET")==0){ 
      cout << "\n";
      cout << "Enter name of item you wish to get: " << endl;
      char* itemName = new char[20];
      cin.get(itemName,20);
      cin.get();
      if(currentRoom->roomInventory.searchInventory(itemName)){
        get(currentRoom,roomVect,itemName,playerInventory);
      }
      else{
        cout << "Cannot pick item up!" << endl;
      }
    }

    // Drops item into room
    if(strcmp(userInput,"DROP")==0){ 
      cout << "\n";
      cout << "Enter name of item you wish to drop: " << endl;
      char* itemName = new char[20];
      cin.get(itemName,20);
      cin.get();
      if(playerInventory.searchInventory(itemName)){
        drop(currentRoom,roomVect,itemName,playerInventory);  
      }
      else{
        cout << "Cannot pick item up!" << endl;
      }
    }

    // Quits
    if(strcmp(userInput,"QUIT")==0){ 
      loop = false;
      break;      
    }
    
    // If the user has gold in their inventory, ends the game
    if(playerInventory.searchInventory(goldd)){
      cout << "Congratulations on finding the gold! You have won!" << endl;
      loop = false;
      break;
    }
    
  }
  cout << "Program ended." << endl;
  
  return 0;
}

void go(Room* &currentRoom,vector<Room*> &roomVect, Inventory &playerInventory){
  bool found = false;
  cout << "\n";
  cout << "Enter the direction you want to travel. (";
  // Prints out options for directions for user to travel
  map<char, Room*>::iterator i;
  for (i = currentRoom->exitMap.begin(); i != currentRoom->exitMap.end(); ++i) {
    cout << i->first << " ";
    
  }
  cout << ")" << endl;
  
  char direction[10];
  cin.get(direction,10);
  cin.get();

  char* key = new char[80];
  strcpy(key,"Key");

  // Goes through possible exits, sees if user input matches one of them
    
  for (i = currentRoom->exitMap.begin(); i != currentRoom->exitMap.end(); ++i) {
    if(*direction == i->first){
      // Prevents user from accessing vault without key
      if(strcmp(currentRoom->exitMap.at(i->first)->getName(),"The Vault")==0){
        if((playerInventory.searchInventory(key))==false){
          cout << "Sorry, room is locked. Try finding a key." << endl;
          found = true;
          break;
        }
      }
      // Moves current room if user's direction is a valid exit
      currentRoom = currentRoom->exitMap.at(i->first);
      found = true;
      break;
    }
  }
  if(!found){
    cout << "Not a valid direction." << endl;
  }
}

void get(Room* &currentRoom,vector<Room*> &roomVect, char* itemName,Inventory &playerInventory){

  // Gets item based on name, adds to player inventory, removes from room inventory
  Item* m = currentRoom->roomInventory.returnItem(itemName);
  playerInventory.addItem(m);
  currentRoom->roomInventory.removeItem(itemName);
  
  

  
  cout << itemName << " has been added to your inventory!" << endl;
  
}

void drop(Room* &currentRoom,vector<Room*> &roomVect, char* itemName,Inventory &playerInventory){

  // Gets item based on name, adds to room inventory, removes from player inventory
  Item* m = playerInventory.returnItem(itemName);
  currentRoom->roomInventory.addItem(m);
  playerInventory.removeItem(itemName);

  cout << itemName << " has been dropped from your inventory!" << endl;
}
