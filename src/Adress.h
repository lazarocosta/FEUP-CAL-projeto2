#ifndef SRC_ADRESS_H_
#define SRC_ADRESS_H_

#include <iostream>

#include "Node.h"
#include "Road.h"

using namespace std;
/**
 * Adress- Class which as a node and a road representing an adress.
 */
class Adress {
	/**
	 * Private atribute that represents the node of the adress.
	 */
	Node local;
	/**
	 * Private atribute that represents the road of the adress.
	 */
	Road street;
public:
	/**
	 * Constructor of the class with no parameters.
	 */
	Adress(){};
	/**
	 * Constructor of the class which initialize all the private attributes.
	 * @param local.
	 * @param street.
	 */
	Adress(Node local,Road street);
  //--------------------------------------------------------------------------------------------------------
  /**
   * Getter which returns the road.
   * @return street.
   */
	Road getStreet() const;
	/**
	 * Getter which returns the node.
     * @return local.
	 */
  Node getLocal() const;
  /**
   * Set the node of the adress.
   * @param n.
   */
  void setLocal(Node &n);
  /**
    * Set the road of the adress.
    * @param r.
    */
  void setStreet(Road &r);
  //--------------------------------------------------------------------------------------------------------
  /**
   * Display the information relative to the adress.
   */
  void printAdress();
};

#endif
