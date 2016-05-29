#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

#include <vector>

#include "User.h"
#include "RideCenter.h"

using namespace std;

class Interface{
	vector<User*> users;
	RideCenter center;
public:
  Interface(ReaderFiles r);
  void displayMenu();
  void displayUsers();
  void newUser();
  void defineUserDeparture();
  void departure();
  void defineRideFromOtherUser();
  Vertex<Node,Road> *findPlace(Node n) const;
  Vertex<Node,Road> * findRoad(string name) const;
  vector<User*> getUsers();
  int returnInt(string s1);

  string returnInput(string s1,string s2);
  int selectMenu(char menor, char maior);
  User *findUser(string name,unsigned long ID) const;
  User *findUser(string name,string road) const;
  vector<Node> SelectUsersForRide(Node Sourc,vector<Node> Positions,  Node Dest, unsigned int lot);
  double returnDouble(string s1);

  //-------------------------------------------------------------------------
};

#endif
