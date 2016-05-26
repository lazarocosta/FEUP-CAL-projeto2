#include "User.h"

using namespace std;
User::User(string name, int age, Adress initAdress, Adress destAdress,int nP) {
  this->name = name;
  this->age = age;
  this->initAdress = initAdress;
  this->destAdress = destAdress;
  this->numPassengers=nP;
  wantDest=true;
}

User::User(string name, int age, Adress initAdress) {
  this->name = name;
  this->age = age;
  this->initAdress = initAdress;
  this->destAdress=initAdress;
  this->numPassengers=0;
  wantDest=false;
}

User::User(string name,int age){
	this->name = name;
	this->age = age;
	this->numPassengers=0;
	wantDest=false;
}

//------------------------------------------------------------------------------------------------
string User::getName() const{
	return name;
}

int User::getAge() const{
	return age;
}

Adress User::getUserAdress() const{
	return initAdress;
}

Adress User::getUserDestination() const{
	return destAdress;
}

string User::getHoraInit() const{
	return horaInit;
}

string User::getHoraFim() const{
	return horaFim;
}

int User::getNumPassegers() const{
	return numPassengers;
}

bool User::getWantDest() const{
	return wantDest;
}

void User::setHoraInit(string &h){
	horaInit=h;
}

void User::setHoraFim(string &h){
	horaFim=h;
}

void User::setDestAdress(Node n,Road r){
	destAdress.setLocal(n);
	destAdress.setStreet(r);
	wantDest=true;
}

void User::resetUser(){
	horaInit="";
	horaFim=="";
	wantDest=false;
	numPassengers=0;
	initAdress=destAdress;
}

//------------------------------------------------------------------------------------------------
void User::printUserAdress() {
	initAdress.printAdress();
}

void User::printDestAdress(){
	if(wantDest){
	destAdress.printAdress();
	}
	else
		cout << "No destiny adress defined." << endl;
}

void User::printHoursAndNumPassengers(){

	if(wantDest){
	cout << "Hour departure: " << horaInit << endl;
	cout << "Hour arrive: " << horaFim << endl;
	cout << "Number Passengers to tranport: " << numPassengers << endl;
	}
}
