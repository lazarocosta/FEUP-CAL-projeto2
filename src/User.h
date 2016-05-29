#ifndef SRC_USER_H_
#define SRC_USER_H_

#include <vector>

#include "Adress.h"
#include "Graph.h"

using namespace std;
/**
 * User-Class that represents a user in the program.
 */
class User {
	/**
	 * Private attribute that saves the name of the user.
	 */
  string name;
  /**
   * Private attribute that saves the age of the user.
   */
  int age;
  /**
   * Private attribute that saves the initial adress of the user.
   */
  Adress initAdress;//adress onde se encontra o utilizador
  /**
   * Private attribute that saves the destiny adress of the user.
   */
  Adress destAdress;//adress onde deseja ir
  /**
   * Private attribute that saves the hour that the user want do get picked or departure.
   */
  string horaInit;
  /**
   * Private attribute that saves the hour that the user want do get to the destiny place.
   */
  string horaFim;
  /**
   * Private attribute that saves if the user will drive or want to get picked.
   */
  bool wantDest;
  /**
   * Private attribute that saves the number of passengers that the user can transport.
   */
  int numPassengers;
  /**
   * Path of the roads and nodes he will pass in case of a travel.
   */
  vector<Vertex<Node, Road> > path;
  /**
   * Users to give a ride.
   */
  vector <User*> usersToTakeRide;

public:
  /**
   * Constructor that initialize all the private attributes.
   */
  User(string name, int age, Adress initAdress, Adress destAdress,int nP,vector<Vertex<Node, Road> > path);
  /**
   * Constructor that initialize all the private attributes except the path.
   */
  User(string name, int age, Adress initAdress, Adress destAdress,int nP);
  /**
   * Constructor that only initialize the name, age and the initial adress of the user.
   */
  User(string name, int age, Adress initAdress);
  /**
   * Constructor that only intialize the private attributes name and age.
   */
  User(string name,int age);
  //----------------------------------------------------------------------------------------------------------
  /**
   * Getter that returns the name of the user.
   * @return name.
   */
  string getName() const;
  /**
   * Getter that returns the age of the user.
   * @return age.
   */
  int getAge() const;
  /**
   * Getter that returns the initial adress of the user.
   * @return initAdress.
   */
  Adress getUserAdress() const;
  /**
   * Getter that returns the destiny adress of the user.
   * @return destAdress.
   */
  Adress getUserDestination() const;
  /**
   * Getter that returns the initial hour of the user.
   * @return horaInit.
   */
  string getHoraInit() const;
  /**
   * Getter that returns the final hour of the user.
   * @return horaFim.
   */
  string getHoraFim() const;
  /**
   * Getter that return the number of passengers that the user can transport.
   * @return numPassenges.
   */
  int getNumPassegers() const;
  /**
   * Getter that returns if the user will drive or want to get picked.
   * @return wantDest.
   */
  bool getWantDest() const;
  /**
   * Getter responsible to return the path of the roads where user will pass.
   * @return path.
   */
  vector<Vertex<Node, Road> > getUserPath() const;
  /**
   * Getter that returns the users that this user will give a ride.
   */
  vector <User*> getUsersToTakeRide() const;
  /**
   * Set the initial hour.
   * @param h.
   */
  void setHoraInit(string &h);
  /**
   *  Set the final hour.
   * @param h.
   */
  void setHoraFim(string &h);
  /**
   * Set the destiny adress.
   * @param n.
   * @param r.
   */
  void setDestAdress(Node n,Road r);
  /**
   * Function that reset the private attributes initAdress, destAdress, horaInit,horaFim and wantDest.
   */
  void resetUser();
  /**
   * Insert the path of the roads and nodes where the user will pass.
   * @param path.
   */
  void insertPath(vector<Vertex<Node, Road> > path);
  /**
   * Push a new user to the vector that has all the users that will receive a ride from this user.
   */
  void pushToUsersToTakeRide(User *u);
  //--------------------------------------------------------------------------------------------------------
  /**
   * Function that prints the initial adress of the user.
   */
  void printUserAdress();
  /**
   * Function that prints the destiny adress of the user.
   */
  void printDestAdress();
  /**
   * Function that prints the initial an final hour of the user.
   */
  void printHoursAndNumPassengers();
};

#endif
