#include "Interface.h"
#include "ReaderFiles.h"
#include "RideCenter.h"

using namespace std;

int main() {

	ReaderFiles r = ReaderFiles();

	Interface cli=Interface(r);

	cli.displayMenu();
	RideCenter center = RideCenter(r);

	//cout << "PRINT GRAPH" << endl;
	//center.printGraph();
	cout << "DISTRAK" << endl;
	//TEST 1 grahp.path
	//	center.centerGraph(temp);
	//	double dist;
	//	center.getPath(temp,temp2,dist);
	//	cout << "DIST" << dist << endl;

	//TEST2 BestPath Multiple Points
	/*Node temp = center.FindNode(441803408);

	Node temp2 = center.FindNode(441803285);
	vector<Node> Pontos_interesse;
	if(center.in_elipse(temp,temp2,center.FindNode(441803328)))
	Pontos_interesse.push_back(center.FindNode(441803328));

	if(center.in_elipse(temp,temp2,center.FindNode(441803282)))
	Pontos_interesse.push_back(center.FindNode(441803282));
	//Pontos_interesse.push_back(center.FindNode(441819655));
	//Pontos_interesse.push_back(center.FindNode(441803329));
	//Pontos_interesse.push_back(center.FindNode(452682268));
			//NAO TEM A LOTAÇAO A FUNCIONAR
			vector<Vertex<Node, Road> > teste = center.BestPath(temp, temp2,
					Pontos_interesse, 0);

			center.displayGraph(teste);

			vector<Vertex<Node, Road> >::iterator it = teste.begin();
			vector<Vertex<Node, Road> >::iterator ite = teste.end();

			while (it != ite) {
				cout << it->getInfo().getID() << endl;
				it++;
			}

			getchar();
*/
	return 0;
}

