#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include <iostream>
#include <cmath>

using namespace std;
/**
 * Node-Class that represents the information of the nodes in the graph.
 */
class Node{
	/**
	 * Private attribute that saves the id of the node.
	 */
	unsigned long id;
	/**
	 * Private attribute that saves the latitude in radians of the node.
	 */
	double latRad;
	/**
	 * Private attribute that saves the longitude in radians of the node.
	 */
	double lonRad;
	/**
	 * Private attribute that saves the latitude in degrees of the node.
	 */
	double latDeg;
	/**
	 * Private attribute that saves the longitude in degrees of the node.
	 */
	double lonDeg;

public:
	/**
	 * Constructor of the class with no parameters.
	 */
	Node(){};
	/**
	 * Constructor of the class which only initialize the id of the node.
	 */
	Node(unsigned long id);
	/**
	 * constructor of the class that initialize all the private atributes.
	 */
	Node(unsigned long id,double latR,double lonR,double latD,double lonD);
	/**
	 * Constructor of the class that only initialize the latitude and the longitude in radians.
	 */
	Node(double x,double y);
	/**
	 * Getter which returns the id of the node.
	 * @return id.
	 */
	unsigned long getID() const;
	/**
	 *  Getter which returns the latitude in radians of the node.
	 * @return latRad.
	 */
	double getLatRad() const;
	/**
	 * Getter which returns the longitude in radians of the node.
	 * @return lonRad.
	 */
	double getLonRad() const;
	/**
	 * Getter which returns the latitude in degrees of the node.
	 * @return latDeg.
	 */
	double getLatDeg() const;
	/**
	 * Getter which returns the latitude in degrees of the node.
	 * @return lonDeg.
	 */
	double getLonDeg() const;
	/**
	 * Operator that verifys if two objects of this class are the same.
	 * @param n.
	 * @return true if both nodes got the same id.
	 */
	bool operator==(const Node &n) const{return this->id==n.getID();};
	/**
	 * Calculates the distance between two nodes.
	 * @param n.
	 * @return distance.
	 */
	double distance(Node &n);
};


#endif
