#ifndef SRC_RELATION_H_
#define SRC_RELATION_H_
/**
 * Relation-Class that represents the relation of the roads with the nodes.
 */
class Relation{
	/**
	 * Private attribute that saves the id of the road.
	 */
	unsigned long roadID;
	/**
	 *  Private attribute that saves the id of the first node of the road.
	 */
	unsigned long node1ID;
	/**
	 * Private attribute that saves the id of the second node of the road.
	 */
	unsigned long node2ID;
public:
	/**
	 * Constructor of the class.
	 */
	Relation(unsigned long roadID,unsigned long node1ID,unsigned long node2ID);
	/**
	 * Getter that returns the id of the road.
	 * @return roadID.
	 */
	unsigned long getRoadID() const;
	/**
	 * Getter that returns the id of the first node.
	 * @return node1ID.
	 */
	unsigned long getNode1ID() const;
	/**
	 * Getter that returns the id of the second node.
	 * @return node2ID.
	 */
	unsigned long getNode2ID() const;
};



#endif
