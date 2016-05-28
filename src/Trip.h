#ifndef SRC_TRIP_H_
#define SRC_TRIP_H_

#include "Adress.h"

using namespace std;

class Trip {
  Adress adress;
  string hDeparture;
  string hArrive;

public:
  Trip(){};
  Trip(Adress adress, string hDeparture, string hArrive);
  //--------------------------------------------------------------------------------------------------------
  Adress getTripAdress();
  string getHDeparture();
  string getHArrive();
};

#endif
