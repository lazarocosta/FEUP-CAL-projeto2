#include "Trip.h"

using namespace std;
Trip::Trip(Adress adress, string hDeparture, string hArrive) {
  this->adress = adress;
  this->hDeparture = hDeparture;
  this->hArrive = hArrive;
}

//-------------------------------------------------------------------------------
Adress Trip::getTripAdress() {
	return adress;
}

string Trip::getHDeparture() {
	return hDeparture;
}

string Trip::getHArrive() {
	return hArrive;
}
