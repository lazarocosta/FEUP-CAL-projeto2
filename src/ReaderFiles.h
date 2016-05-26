#ifndef SRC_READERFILES_H_
#define SRC_READERFILES_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

#include "Node.h"
#include "Road.h"
#include "Relation.h"

using namespace std;
/**
 * ReadeFiles-Class responsible for read the files that contains the information of the nodes and the roads.
 */
class ReaderFiles{
	/**
	 * Private attribute which stores all the nodes.
	 */
	vector<Node> nodes;
	/**
	 * Private attribute which stores all the roads.
	 */
	vector<Road> roads;
	/**
	 * Private attribute which stores all the relations between the nodes and the roads.
	 */
	vector<Relation> relations;
	/**
	 * Private attribute which stores the minimum latitude.
	 */
	double minLat;
	/**
	 * Private attribute which stores the maximum latitude.
	 */
	double maxLat;
	/**
	 * Private attribute which stores the minimum longitude.
	 */
	double minLon;
	/**
	 * Private attribute which stores the maximum latitude.
	 */
	double maxLon;
public:
	/**
	 * Constructor of the class.
	 */
	ReaderFiles();
	/**
	 * Function which read the file that got all the information of the nodes.
	 */
	void readFileNameNodes();
	/**
	 * Function which read the file that got all the information of the roads.
	 */
	void readFileNameRoads();
	/**
	 * Function which read the file with all the relations between the nodes and the roads.
	 */
	void readFileNameRelation();
	/**
	 * Getter which returns the vector with all the nodes.
	 * @return nodes.
	 */
	vector<Node> getNodes() const;
	/**
	 *  Getter which returns the vector with all the roads.
	 * @return roads.
	 */
	vector<Road> getRoads() const;
	/**
	 *  Getter which returns the vector with all the relations.
	 * @return relations.
	 */
	vector<Relation> getRelations() const;
	/**
	 *  Getter which returns the minimum latitude.
	 * @return minLat.
	 */
	double getMinLat() const;
	/**
	 *  Getter which returns the maximum latitude.
	 * @return maxLat.
	 */
	double getMaxLat() const;
	/**
	 *  Getter which returns the minimum longitude.
	 * @return minLon.
	 */
	double getMinLon() const;
	/**
	 *  Getter which returns the maximum longitude.
	 * @return maxLon.
	 */
	double getMaxLon() const;
	/**
	 * Updates the private attributes minLat,miLon,maxLat and maxLon.
	 * @param lat.
	 * @param lon.
	 */
	void updateLatsAndLons(double lat,double lon);

};



#endif
