#include "Node.h"

#include <cmath>
#define EARTH_RAD 6378.137


Node::Node(unsigned long id): id(id){}

Node::Node(unsigned long id,double latR,double lonR,double latD,double lonD):id(id), latRad(latR),lonRad(lonR),latDeg(latD),lonDeg(lonD){}

Node::Node(double latR,double lonR): latRad(latR),lonRad(lonR){}

unsigned long Node::getID() const{
	return id;
}

double Node::getLatRad() const{
	return latRad;
}

double Node::getLonRad() const{
	return lonRad;
}

double Node::getLatDeg() const{
	return latDeg;
}

double Node::getLonDeg() const{
	return lonDeg;
}


double Node::distance(Node &n){
	double dLat=(n.getLatRad()- latRad);
	double dLon=(n.getLonRad() -lonRad);
	double a = sin(dLat/2)*sin(dLat/2)+
			cos(latRad)* cos(n.getLatRad())
			*sin(dLon/2)*sin(dLon/2);
	double c = 2 * atan2(sqrt(a),sqrt(1-a));
	double d = EARTH_RAD * c;
	return d;
}
