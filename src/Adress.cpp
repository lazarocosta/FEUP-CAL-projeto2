#include "Adress.h"

using namespace std;
Adress::Adress(Node local,Road street) {
	this->local=local;
	this->street=street;
}

Road Adress::getStreet() const{
	return street;
}

Node Adress::getLocal() const{
	return local;
}

void Adress::setLocal(Node &n){
	local=n;
}

void Adress::setStreet(Road &r){
	street=r;
}

void Adress::printAdress() {
	cout << "Local node: " << local.getID() << endl;
	cout << "Street name: " << street.getName() << endl;
}
