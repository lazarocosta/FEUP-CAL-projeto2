#ifndef SRC_RIDECENTER_H_
#define SRC_RIDECENTER_H_

#include "Graph.h"
#include "Node.h"
#include "Road.h"
#include "ReaderFiles.h"
#include "User.h"
#include "Adress.h"
#include "GraphViewer.h"
#include "StringSearch.h"

/**
 * RideCenter-Class that represents all the logic of the program.
 */
class RideCenter {
	/**
	 * Private attribute that saves all the information in a graph.
	 */
	Graph<Node, Road> graph;
	/**
	 * Private attribute which stores all the relations between the nodes and the roads.
	 */
	vector<Relation> rels;
	/**
	 * Private attribute which stores all the nodes.
	 */
	vector<Node> nodes;
	/**
	 * Private attribute which stores all the roads.
	 */
	vector<Road> roads;
	/**
	 * Private attribute of type ReaderFiles.
	 */
	ReaderFiles reader;
public:
	/**
	 * Constructor of the class with no parameters.
	 */
	RideCenter() {
	}
	;
	/**
	 * Constructor of the class that initialize all the private attributes.
	 * @param r.
	 */
	RideCenter(ReaderFiles &r);
	/**
	 * Function that prints all the ids's of the nodes in the graph.
	 */
	void printGraph() const;
	/**
	 * Function that calculates if a node is inside of the ellipse.
	 * @param foco1.
	 * @param foco2.
	 * @param n.
	 * @return true if the node n is inside of the ellipse.
	 */
	bool in_elipse(Node foco1, Node foco2, Node N);

	/**
	 * Function that calls  Dijkstra algorithm implementation
	 * @param T Starting Point on Desired Path
	 */
	void centerGraph(Node T);

	/**
	 *Returns path between Sourc and Dest if possible
	 *Update dist value to total distance between Sourc and Dest
	 *@param Sourc
	 *@param Dest
	 *@param dist
	 */
	vector<Vertex<Node, Road> *> getPath(const Node &Sourc, const Node &Dest,
			double &dist);

	/**
	 * Find a node based in is unique id
	 * @param id.
	 * @return Node if exits, NULL otherwise.
	 */
	Node FindNode(unsigned long id);
	/**Return the best path between a Sourc and Dest nodes passing by InterestPoints
	 *@return vector<Vertex<Node, Road> > sequence between Sourc and Dest
	 */
	vector<Vertex<Node, Road> > BestPath(const Node &Sourc, const Node & Dest,
			const vector<Node> InterestPoints);

	/**
	 * Returns a pointer  of class Address that contain Node N
	 * @param N
	 * @return Pointer to Address object
	 */
	Adress* getAdress(Node N) const;
	/**
	 * Call's graphviewer application
	 * @param passNodes
	 */
	void displayGraph(vector<Vertex<Node, Road> > passNodes);
	/**
	 * Return a copy of RideCenter graph
	 * @return Grap<Node,Road>
	 */
	Graph<Node, Road> getGraph() const;

	/**
	 * Check if dest is present in nodes vector
	 * @param nodes
	 * @return true is exist in  nodes, false  otherwise
	 */
	bool SourcDestConected(Node dest, vector<Node> nodes);
	/**
	 * Check if dest is present in nodes vector
	 * @param nodes
	 * @return true is exist in  nodes, false  otherwise
	 */
	bool SourcDestConectedDFS(Node sourc, Node dest);
	/**
	 * Check if  Sourc is connected with Dest and Interest_Point,also check if all Interest_points
	 * are connected  to Dest
	 * @param Sourc
	 * @paramm Dest
	 * @Interest_Points
	 * @ban
	 * @return true is all nodes connected, false if not.
	 */
	bool TestALLNodesConected(Node Sourc, Node Dest,
			vector<Node> Interest_Points, unsigned int &ban);

	/**
	 * Return Edge id number
	 * @param id_sourc
	 * @param id_dest
	 * @return EdgeID
	 */
	unsigned long getEdgeID(unsigned long id_sourc, unsigned long id_dest);

	string getEdgeName(unsigned long id_sourc, unsigned long id_dest);

	/**
	 * Returns a vertex of the graph
	 * @param n
	 * @return NULL if does not exits otherwise returns a Vertex<Node.Road> pointer
	 */
	Vertex<Node, Road>* findVertex(Node n) const;

	/**
	 * Returns the first vertex of the egde contained in the graph
	 * @param name of Road
	 * @return NULL if does not exits otherwise returns a Vertex<Node.Road> pointer
	 */
	Vertex<Node, Road> *findVertexByRoad(string name) const;

};

#endif
