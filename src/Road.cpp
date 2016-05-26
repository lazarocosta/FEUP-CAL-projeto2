#include "Road.h"

Road::Road(unsigned long id) {
	this->id = id;
}

Road::Road(string name) {
	this->name = name;
}

Road::Road(unsigned long id, string name, bool isTwoWays) {
	this->id = id;
	this->name = name;
	this->isTwoWays = isTwoWays;
}

unsigned long Road::getID() const {
	return id;
}

string Road::getName() const {
	return name;
}

bool Road::getIsTwoWays() const {
	return isTwoWays;
}
