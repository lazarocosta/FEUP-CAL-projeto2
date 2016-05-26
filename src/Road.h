#ifndef SRC_ROAD_H_
#define SRC_ROAD_H_´

#include <string>

using namespace std;
/**
 * Road-Class that represents the information of the edges in the graph.
 */
class Road{
	/**
	 * Private attribute that represents the id of the road.
	 */
	unsigned long id;
	/**
	 * Private attribute that represents the name of the road.
	 */
	string name;
	/**
	 * Private attribute that saves if the road is two ways or not.
	 */
	bool isTwoWays;
public:
	/**
	 * Constructor of the class with no parameters.
	 */
	Road(){};
	/**
	 * Costructor of the class that only initialize the id of the road.
	 * @param id.
	 */

	Road(string name);


	Road(unsigned long id);
	/**
	 * Constructor of the class that initialize all the private attributes.
	 */
	Road(unsigned long id,string name,bool isTwoWays);
	/**
	 * Getter that returns the id of the road.
	 * @return id.
	 */
	unsigned long getID() const;
	/**
	 * Getter that returns the name of the road.
	 * @return name.
	 */
	string getName() const;
	/**
	 * Getter that returns if the road is in two ways or not.
	 * @return isTwoWays.
	 */
	bool getIsTwoWays() const;
	/**
	 * Operator that verifys if two roads are the same.
	 * @param r.
	 * @return true if the roads are the same.
	 */
	bool operator==(const Road &r) const{return this->id==r.getID();};
};



#endif
