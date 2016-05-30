#include "RideCenter.h"

#include <algorithm>

RideCenter::RideCenter(ReaderFiles &r) {

	this->rels = r.getRelations();
	this->nodes = r.getNodes();
	this->roads = r.getRoads();

	typename vector<Relation>::iterator it = rels.begin();
	typename vector<Relation>::iterator ite = rels.end();



	unsigned int serial_N = 1;
	for (; it != ite; it++) {

		typename vector<Road>::iterator itRoad;
		typename vector<Node>::iterator itNode1;
		typename vector<Node>::iterator itNode2;

		itRoad = find(roads.begin(), roads.end(), Road(it->getRoadID()));
		itNode1 = find(nodes.begin(), nodes.end(), Node(it->getNode1ID()));
		itNode2 = find(nodes.begin(), nodes.end(), Node(it->getNode2ID()));

		graph.addVertex(*itNode1);
		graph.addVertex(*itNode2);

		double dist = itNode1->distance(*itNode2);

		if (itRoad->getIsTwoWays()) {
			graph.addEdge(*itNode1, *itNode2, *itRoad, dist, serial_N);

			graph.addEdge(*itNode2, *itNode1, *itRoad, dist, serial_N);
		} else {
			graph.addEdge(*itNode1, *itNode2, *itRoad, dist, serial_N);
		}
		serial_N++;
	}
}

void RideCenter::printGraph() const {

	vector<Vertex<Node, Road>*> nodes = graph.getVertexSet();

	for (unsigned int i = 0; i < nodes.size(); i++) {
		cout << nodes[i]->getInfo().getID() << endl;
	}
}

bool RideCenter::in_elipse(Node foco1, Node foco2, Node N) {


	double dist= foco1.distance(foco2);
	double comparador= 2*dist+ dist/4;

	double dist_1= foco1.distance(N);
	double dist_2= foco2.distance(N);
	if (dist_1+dist_2 <= comparador) //se for menor ou igual esta contido na elipse
		return true;
	else
		return false;

}

void RideCenter::centerGraph(Node T) {
	graph.dijkstraShortestPath(T);
}
vector<Vertex<Node, Road> *> RideCenter::getPath(const Node &Sourc,
		const Node &Dest, double &dist) {
	std::vector<Vertex<Node, Road> *> path = graph.getPath(Sourc, Dest);
	vector<Vertex<Node, Road>*>::iterator it = path.end();
	--it;
	dist = (*it)->getDist();

	return path;
}

Node RideCenter::FindNode(unsigned long id) {

	vector<Vertex<Node, Road> *> temp = graph.getVertexSet();
	vector<Vertex<Node, Road> *>::iterator it = temp.begin();
	vector<Vertex<Node, Road> *>::iterator ite = temp.end();

	while (it != ite) {
		if ((*it)->getInfo().getID() == id)
			return (*it)->getInfo();
		it++;
	}

	return Node(0);
}



vector<Vertex<Node, Road> > RideCenter::BestPath(const Node &Sourc,const Node & Dest, const vector<Node> InterestPoints)
		{
	unsigned int total_points = InterestPoints.size() + 2;

	double dist[total_points - 1][total_points];

	vector<Node> points;
	vector<vector<Vertex<Node, Road>*> > paths;

	//BUILD POINTS SEQUENCE
	points.push_back(Sourc);
	for (unsigned int i = 0; i < InterestPoints.size(); i++) {
		points.push_back(InterestPoints[i]);
	}

	points.push_back(Dest);

	// CALCULATE DIST AND PATHS

	for (unsigned int i = 0; i + 1 < points.size(); i++) // DONT BUILD PATHS FROM END POINT TO OTHER POINTS
			{
		centerGraph(points[i]);
		for (unsigned int t = 0; t < points.size(); t++) {
			if (i == t) {
				dist[i][t] = 0;
				vector<Vertex<Node, Road>*> a;
				paths.push_back(a);
				continue;
			}
			double distant;
			paths.push_back(getPath(points[i], points[t], distant));
			dist[i][t] = distant;
			cout << "distant " << " i: " << i << "t: " << t << " " << dist[i][t]
					<< endl;
		}
	}

	///Nearest neighbour algorithm - TSP
	/// greedy algorithm

	int visited[points.size() - 1];
	for (unsigned int i = 0; i < points.size() - 1; i++) {
		visited[i] = 0;
	}

	unsigned int pos = 0;
	double total_dist = 0;
	bool allVisited = false;

	vector<int> index_order;
	index_order.push_back(0);
	cout << "TOTAL POINTS" << points.size() << endl;

	while (!allVisited) {

		double min = 999.99;
		int nextpos = points.size() - 1;
		for (unsigned int t = 0; t + 1 < points.size(); t++) {

			if (dist[pos][t] < min && dist[pos][t] != 0) {

				if (visited[t] == 0) {
					min = dist[pos][t];
					nextpos = t;

				}

			}
		}

		visited[pos] = 1;
		if (min != 999.99)
			total_dist += min;
		else
			total_dist += dist[pos][nextpos];
		pos = nextpos;
		index_order.push_back(pos);


		for (unsigned int i = 0; i < points.size() - 1; i++) {

			if (visited[i] == 0) {

				allVisited = false;
				break;
			}

		}

		if (nextpos == points.size() - 1) // WHEN CANT COVER ALL POINT ( EU POSSO EXPLICAR ISTO SE TIVEREM DUVIDAS ASK xD )
				{
			allVisited = true;
		}
		if (allVisited == true) {	//index_order.push_back(points.size()-1);
			for (unsigned int t = 0; t < index_order.size(); t++) {
				cout << index_order[t] << endl;
			}

			cout << "TOTAL DISTANCE:  " << total_dist << endl;
		}

	}

	//BUILD FINAL PATH
	vector<Vertex<Node, Road> > final;



	for (unsigned int i = 0; i + 1 < index_order.size(); i++) {

		int path_index = index_order[i] * (points.size()) + index_order[i + 1];

		vector<Vertex<Node, Road> *>::iterator it = paths[path_index].begin();
		vector<Vertex<Node, Road> *>::iterator ite = paths[path_index].end();
		if (i > 0)
			it++;
		while (it != ite) {
			final.push_back(*(*it));
			it++;
		}
	}


	return final;
}

Adress* RideCenter::getAdress(Node N) const {
	Road street;
	bool find = false;
	Adress* A;

	for (unsigned int i = 0; i < graph.getVertexSet().size(); i++) {
		if (graph.getVertexSet()[i]->getInfo() == N)
			if (graph.getVertexSet()[i]->getAdj().size() > 0) {
				find = true;
				street = graph.getVertexSet()[i]->getAdj()[0].getEdgeInfo();
			} else
				return NULL;

	}
	if (!find)
		return NULL;

	*A = Adress(N, street);

	return A;
}

void RideCenter::displayGraph(vector<Vertex<Node, Road> > passNodes) {
	cout <<"count" << passNodes.size() << endl;
	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(1200, 1200);

	gv->defineEdgeColor(ORANGE);

	gv->defineVertexColor(YELLOW);

	gv->defineEdgeCurved(false);
	//ADD NODES TO  MAP
	typename vector<Node>::iterator it_node = nodes.begin();
	typename vector<Node>::iterator ite_node = nodes.end();
	int x, y;
	for (; it_node != ite_node; it_node++) {
		x = floor(
				((it_node->getLonDeg() - reader.getMinLon()) * 1200)
						/ (reader.getMaxLon() - reader.getMinLon()));
		y = floor(
				((it_node->getLatDeg() - reader.getMinLat()) * 1200)
						/ (reader.getMaxLat() - reader.getMinLat()));

		gv->addNode(it_node->getID(), x, -y);
	}

	// ADD EDJES TO MAP
	typename vector<Relation>::iterator it = rels.begin();
	typename vector<Relation>::iterator ite = rels.end();

	for (; it != ite; it++) {

		typename vector<Road>::iterator itRoad;
		itRoad = find(roads.begin(), roads.end(), Road(it->getRoadID()));


		unsigned long ID = getEdgeID(it->getNode1ID(), it->getNode2ID());
		string name = getEdgeName(it->getNode1ID(), it->getNode2ID());
		if (ID == 0) {
			cout << "NAO DESENHOU ARESTA" << endl;
			continue;
		}
		if (itRoad->getIsTwoWays()) {

			gv->addEdge(ID, it->getNode1ID(), it->getNode2ID(),
					EdgeType::UNDIRECTED);

		} else {
			gv->addEdge(ID, it->getNode1ID(), it->getNode2ID(),
					EdgeType::DIRECTED);
		}

		gv->setEdgeLabel(ID, name);

	}

	// CHANGE PATH NODES COLOR
	for (unsigned int i = 0; i < passNodes.size(); i++) {
		if(i == 0)
			gv->setVertexColor(passNodes[i].getInfo().getID(), RED);
		else if(i == passNodes.size()-1)
			gv->setVertexColor(passNodes[i].getInfo().getID(), GREEN);
		else  gv->setVertexColor(passNodes[i].getInfo().getID(), BLUE);
	}
	// CHANGE PATH EDGES COLOR
	for (unsigned int i = 0; i < passNodes.size() - 1; i++) {
		unsigned long id = getEdgeID(passNodes[i].getInfo().getID(),
				passNodes[i + 1].getInfo().getID());
		gv->setEdgeColor(id, BLUE);
	}
	gv->rearrange();
}

Graph<Node, Road> RideCenter::getGraph() const {
	return graph;
}

bool RideCenter::TestALLNodesConected(Node Sourc, Node Dest,
		vector<Node> Interest_Points, unsigned int &ban) {
	vector<Node> points;
	points.push_back(Sourc);
	for (unsigned i = 0; i < Interest_Points.size(); i++) {
		points.push_back(Interest_Points[i]);
	}
	points.push_back(Dest);

	int count = 0;

	for (unsigned int i = 0; i < points.size(); i++) {

		vector<Node> nodes = graph.dfs(points[i]);

		for (unsigned int j = count; j < points.size(); j++) {
			if (i == j)
				continue;
			if (SourcDestConected(points[j], nodes) == false) {
				ban = j-1;
				return false;
			}

		}
		count++;
	}

	return true;
}

bool RideCenter::SourcDestConected(Node dest, vector<Node> nodes) {

	vector<Node>::iterator it = nodes.begin();
	vector<Node>::iterator ite = nodes.end();

	while (it != ite) {
		if (it->getID() == dest.getID())
			return true;

		it++;

	}
	return false;
}

bool RideCenter::SourcDestConectedDFS(Node sourc, Node dest){
	vector<Node> temp = graph.dfs(sourc);
	return SourcDestConected(dest,temp);
}

unsigned long RideCenter::getEdgeID(unsigned long id_sourc,
		unsigned long id_dest) {
	Node Sourc = FindNode(id_sourc);

	if (Sourc.getID() == 0) {
		return 0;
	}

	vector<Edge<Node, Road> > edges = graph.getVertex(Sourc)->getAdj();

	vector<Edge<Node, Road> >::iterator it = edges.begin();
	vector<Edge<Node, Road> >::iterator ite = edges.end();

	for (; it != ite; it++) {
		if (it->getDest()->getInfo().getID() == id_dest)
			return it->getID();
	}

	return 0;
}


string RideCenter::getEdgeName(unsigned long id_sourc, unsigned long id_dest) {
	Node Sourc = FindNode(id_sourc);

	if (Sourc.getID() == 0) {
		return 0;
	}

	vector<Edge<Node, Road> > edges = graph.getVertex(Sourc)->getAdj();

	vector<Edge<Node, Road> >::iterator it = edges.begin();
	vector<Edge<Node, Road> >::iterator ite = edges.end();

	for (; it != ite; it++) {
		if (it->getDest()->getInfo().getID() == id_dest)
			return it->getEdgeInfo().getName();
	}

	return NULL;
}



Vertex<Node,Road>* RideCenter::findVertex(Node n) const
{
	return graph.getVertex(n);
}

Vertex<Node,Road> *RideCenter::findVertexByRoad(string name) const{

	Vertex<Node,Road> *v;
	vector<Vertex<Node,Road> *> vertexs;
	int con;

	vertexs=graph.getVertexSet();

	typename vector<Vertex<Node,Road> *>::iterator it = vertexs.begin();
	typename vector<Vertex<Node,Road> *>::iterator ite = vertexs.end();

	int BestMatch = 9999;
	Vertex<Node,Road> *BM;

	for(;it!=ite;it++)
	{
		v=*it;
		if(v->getAdj().size() > 0){
		string tmpName=v->getAdj()[0].getEdgeInfo().getName();
		if(kmp(tmpName,name)!=0 && tmpName.size()==name.size())
				return v;

	 tmpName=v->getAdj()[0].getEdgeInfo().getName();
	 con = EditDistance(tmpName,name);
		if(con < BestMatch)
		{
			BestMatch = con;
			BM = v;
		}


		}
	}

	cout << "Didn't mean " << BM->getAdj()[0].getEdgeInfo().getName() << endl;

	return NULL;
}

