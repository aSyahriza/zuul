#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Room.h"
#include "Item.h"


int main(){


  vector<Room*> roomVect;
  
  Room oneTwentyTwo = new Room("1-22","Ms. Smith's room.");
  roomVect->push_back();
  Room oneTwentyOne = new Room("1-21","The robotics and CAD room.");
  Room oneTwenty = new Room("1-20","Mr. Galbraith's room.");
  Room aOne = new Room("A-1", "Mr. Mcclain's room.");
  Room kitchen = new Room("Kitchen", "They make food here.");
  Room theatre = new Room("Theatre", "Large auditorium for performances.");
  Room lab = new Room("Lab", "Site for tests and experiments and such.");
  Room office = new Room("Office", "Room for the principal and other administrative figures.");
  Room gym = new Room("Gym", "Large, open gym with hardwood floors.");
  Room cafeteria = new Room("Cafeteria", "Hundreds of tables for students to eat lunch.");
  Room library = new Room("Library", "Room containing thousands of books.");
  Room staircase = new Room("Staircase", "Mysterious winding staircase.");
  Room bathroom = new Room("Bathroom", "Stinky bathroom." );
  Room gate = new Room("Gate", "Rusted metallic gate");
  Room vault = new Room("Vault", "Super secret vault. There's probably something awesome down here.");
  
  cout << "ENDL!!!:" << endl;
  return 0;
}
