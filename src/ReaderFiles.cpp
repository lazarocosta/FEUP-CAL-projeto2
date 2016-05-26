#include "ReaderFiles.h"

ReaderFiles::ReaderFiles(){
	readFileNameNodes();
	readFileNameRoads();
	readFileNameRelation();
}

void ReaderFiles::readFileNameNodes(){

	ifstream myfile("files1.txt");

	if(myfile.is_open())
	{
		string line;

		char trash;

		unsigned long nodeID;
		double lat_rad,lon_rad,lat_deg,lon_deg;

		bool isFirstTime=true;

		while(getline(myfile,line))
		{

			if(line=="\n")
				break;

			stringstream ss;

			ss.str(line);
			ss >> nodeID >> trash;
			ss >> lat_deg >> trash;
			ss >> lon_deg >> trash;
			ss >> lat_rad >> trash;
			ss >> lon_rad;

			if(isFirstTime)
			{
				minLat=lat_deg;
				maxLat=lat_deg;
				minLon=lon_deg;
				maxLon=lon_deg;
				isFirstTime=false;
			}
			else
				updateLatsAndLons(lat_deg,lon_deg);


			nodes.push_back(Node(nodeID,lat_rad,lon_rad,lat_deg,lon_deg));
		}
	}

	myfile.close();

}

void ReaderFiles::readFileNameRoads(){
	ifstream myfile("files2.txt");

		if(myfile.is_open())
		{
			string line,lineTrash;
			char trash;
			unsigned long roadID;
			string roadName;
			string twoWaysName;
			bool twoWays;
			while(myfile.good())
			{
				if(line=="\n")
					break;

				myfile >> roadID >> trash;

				getline(myfile,roadName,';');
				getline(myfile,twoWaysName,'\n');

				if(twoWaysName=="True")
					twoWays=true;
				else
					twoWays=false;

				if(myfile.eof())
					break;

				roads.push_back(Road(roadID,roadName,twoWays));

			}
		}

		myfile.close();

}

void ReaderFiles::readFileNameRelation(){
	ifstream myfile("files3.txt");

	if (myfile.is_open()) {
		string line;
		char trash;
		unsigned long roadID,node1ID,node2ID;
		while (getline(myfile, line)) {

			if (line == "\n")
				break;

			stringstream ss;

			ss.str(line);

			ss >> roadID;
			ss >> trash;
			ss >> node1ID;
			ss >> trash;
			ss >> node2ID;

			relations.push_back(Relation(roadID,node1ID,node2ID));

		}
	}

	myfile.close();

}

vector<Node> ReaderFiles::getNodes() const{
	return nodes;
}

vector<Road> ReaderFiles::getRoads() const{
	return roads;
}

vector<Relation> ReaderFiles::getRelations() const{
	return relations;
}

double ReaderFiles::getMinLat() const{
	return minLat;
}

double ReaderFiles::getMaxLat() const{
	return maxLat;
}

double ReaderFiles::getMinLon() const{
	return minLon;
}

double ReaderFiles::getMaxLon() const{
	return maxLon;
}

void ReaderFiles::updateLatsAndLons(double lat,double lon){

	if(minLat>lat)
		minLat=lat;
	if(maxLat<lat)
		maxLat=lat;
	if(minLon>lon)
		minLon=lon;
	if(maxLon<lon)
		maxLon=lon;

}

