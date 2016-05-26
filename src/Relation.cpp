#include "Relation.h"

Relation::Relation(unsigned long roadID,unsigned long node1ID,unsigned long node2ID){
	this->roadID=roadID;
	this->node1ID=node1ID;
	this->node2ID=node2ID;
}

unsigned long Relation::getRoadID() const{
	return roadID;
}

unsigned long Relation::getNode1ID() const{
	return node1ID;
}

unsigned long Relation::getNode2ID() const{
	return node2ID;
}

