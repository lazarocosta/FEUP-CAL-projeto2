#include "Interface.h"

using namespace std;

Interface::Interface(ReaderFiles r) {
	center = RideCenter(r);
}

void Interface::displayMenu() {

	int option = 0;

	cout << "Welcome to RideSharing! Please choose a option." << endl;
	cout << "1-Insert new user." << endl;
	cout << "2-See all users." << endl;
	cout << "3-User select a ride from other user by road." << endl;
	cout << "4-User select a ride from other user by username" << endl;
	cout << "5-User information departure." << endl;
	cout << "6-Departure." << endl;
	cout << "7-Exit." << endl;

	option = selectMenu('1', '7');

	option -= '0';

	if (option == 1)
		newUser();
	else if (option == 2)
		displayUsers();
	else if (option == 3)
		defineRideFromOtherUserByRoad();
	else  if(option == 4)
		RideUserbyName();
	else if (option == 5)
		defineUserDeparture();
	else if (option == 6)
		departure();
	else if (option == 7)
		return;
	else
		displayMenu();

	cout << endl;
}

void Interface::displayUsers() {

	if (users.size() == 0) {
		cout << "No users registered." << endl;
		displayMenu();
		return;
	} else {
		cout << "Users registed: " << endl;
		for (unsigned int i = 0; i < users.size(); i++) {
			cout << "---------------------------------------" << endl;
			cout << users[i]->getName() << endl;
			cout << "Age: " << users[i]->getAge() << endl;
			cout << "---USER ADRESS---" << endl;
			users[i]->printUserAdress();
			cout << "---DEST ADRESS---" << endl;
			users[i]->printDestAdress();
			users[i]->printHoursAndNumPassengers();
			if(users[i]->getWantDest() && users[i]->getUserPath().size()>0)
			{
				vector<Vertex<Node,Road> > p=users[i]->getUserPath();
				cout << "User path: " << endl;
				for(unsigned int j=0;j<p.size();j++)
				{
					cout << p[j].getInfo().getID() << "-->" << p[j].getAdj()[0].getEdgeInfo().getName() << endl;
				}
			}
			else
				cout << "User doesn't has a path." << endl;
			cout << endl;
		}
	}

	displayMenu();
	return;
}

void Interface::newUser() {

	string name, selectMode;
	int age, i = 0, numP;
	Node N;
	unsigned long ID;
	Vertex<Node, Road> *start;
	Vertex<Node, Road> *end;
	bool selectAdressByRoad = true;

	name = returnInput("Name: ", "Introduce a valid name");

	//age = returnInt("Age: ");

	while (selectMode != "road" && selectMode != "node") {
		cout << "Choose adress by road or node ? [road/node]" << endl;
		cin >> selectMode;
	}

	if (selectMode == "node")
		selectAdressByRoad = false;
	//Informação pela Road--------------------------------------------------------------------------------------
	if (selectAdressByRoad) {

		string RoadInitial, RoadFinaly;
		while (true) {

			RoadInitial = returnInput("What is the Road initial?",
					"Introduce a valid name.");
			cout << RoadInitial << endl;
			if ((start = findRoad(RoadInitial)) != NULL) {
				cout << start->getAdj()[0].getEdgeInfo().getName() << endl;
				cout << "Road Found!" << endl;
				break;

			} else
				cout << "Invalid information. Please try again." << endl;
		}

		Adress aInit;
		if (start->getAdj().size() == 0)
			aInit = Adress(start->getInfo(), Road(0, "", false));
		else
			aInit = Adress(start->getInfo(), start->getAdj()[0].getEdgeInfo());

		string choice;

		while (choice != "yes" && choice != "no") {
			cout << "Want to go somewhere ? [yes/no]" << endl;
			cin >> choice;
		}

		string hI;
		string hF;

		if (choice == "yes") {
			i = 0;

		/*	while (true) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				hI = returnInput("Hour to departure ?",
						"Introduce a valid hour");
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				hF = returnInput("Hour to arrive ?", "Introduce a valid hour");

				if (hF > hI)
					break;
				else
					cout
							<< "Not a possible choice. Please choose the hours again."
							<< endl;
			}*/

			numP = returnInt("How many passengers can you transport ?");

			while (true) {
				RoadFinaly = returnInput("What is the final Road?",
						"Introduce a valid name.");

				if ((end = findRoad(RoadFinaly)) != NULL) {
					cout << "Road Found!" << endl;
					break;

				} else
					cout << "Invalid information. Please try again." << endl;
			}

			Adress aDest;
			if (end->getAdj().size() == 0)
				aDest = Adress(end->getInfo(), Road(0, "", false));
			else
				aDest = Adress(end->getInfo(), end->getAdj()[0].getEdgeInfo());

			vector<Node> passP;
			vector<Vertex<Node, Road> > path;

			center.centerGraph(start->getInfo());

			path = center.BestPath(aInit.getLocal(), aDest.getLocal(), passP);

			User *u = new User(name, age, aInit, aDest, numP, path);
			u->setHoraInit(hI);
			u->setHoraFim(hF);

			for (unsigned int i = 0; i < path.size(); i++) {
				cout << path[i].getInfo().getID() << " --->"
						<< path[i].getAdj()[0].getEdgeInfo().getName() << endl;
			}

			users.push_back(u);
		} else {
			User *u = new User(name, age, aInit);

			users.push_back(u);
		}
		//Informação pelo node----------------------------------------------------------------------------------
	} else {
		while (true) {
			if (i == 0) {
				cout << "What is the ID of your Adress: ";
				i++;
			} else
				cout << "ID invalid, new ID again:";

			cin >> ID;

			cin.clear();
			cin.ignore(1000, '\n');
			if ((start = findPlace(Node(ID))) != NULL) {
				cout << "Node found! " << endl;
				break;
			}
		}

		Adress aInit;
		if (start->getAdj().size() == 0)
			aInit = Adress(start->getInfo(), Road(0, "", false));
		else
			aInit = Adress(start->getInfo(), start->getAdj()[0].getEdgeInfo());

		string choice;

		while (choice != "yes" && choice != "no") {
			cout << "Want to go somewhere ? [yes/no]" << endl;
			cin >> choice;
		}

		string hI;
		string hF;

		if (choice == "yes") {
			i = 0;

			while (true) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				hI = returnInput("Hour to departure ?",
						"Introduce a valid hour");
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				hF = returnInput("Hour to arrive ?", "Introduce a valid hour");

				if (hF > hI)
					break;
				else
					cout
							<< "Not a possible choice. Please choose the hours again."
							<< endl;
			}

			numP = returnInt("How many passengers can you transport ?");

			while (true) {
				if (i == 0) {
					cout << "What is the ID Destination: ";
					i++;
				} else
					cout << "ID invalid, new ID again:";

				cin >> ID;

				cin.clear();
				cin.ignore(1000, '\n');
				if ((end = findPlace(Node(ID))) != NULL) {
					if (center.SourcDestConectedDFS(start->getInfo(),
							end->getInfo()))
						cout << "Node found! " << endl;
					break;
				}
			}

			Adress aDest;
			if (end->getAdj().size() == 0)
				aDest = Adress(end->getInfo(), Road(0, "", false));
			else
				aDest = Adress(end->getInfo(), end->getAdj()[0].getEdgeInfo());

			vector<Node> passP;
			vector<Vertex<Node, Road> > path;

			path = center.BestPath(aInit.getLocal(), aDest.getLocal(), passP);

			User *u = new User(name, age, aInit, aDest, numP, path);
			u->setHoraInit(hI);
			u->setHoraFim(hF);

			users.push_back(u);
		} else {
			User *u = new User(name, age, aInit);

			users.push_back(u);
		}

	}

	displayMenu();
}

vector<User*> Interface::getUsers() {
	vector<User*> U;

	for (unsigned int i = 0; i < users.size(); i++) {
		U.push_back(users[i]);
	}
	return U;
}

void Interface::defineUserDeparture() {

	if (users.size() == 0) {
		cout << "No users." << endl;
		displayMenu();
	}

	string name;
	unsigned long nodeID;
	bool flag = true;
	Vertex<Node, Road> *v;
	unsigned long ID;
	int j = 0;
	bool selectAdressByRoad = true;
	string selectMode;
	string RoadFinaly;

	while (flag) {
		name = returnInput("What is the user name ?",
				"Introduce a valid name.");
		nodeID = returnDouble("What is the ID of the node ?");

		for (unsigned int i = 0; i < users.size(); i++) {
			if (users[i]->getName() == name
					&& users[i]->getUserAdress().getLocal().getID() == nodeID) {

				if (users[i]->getWantDest()) {
					cout << "User already picked a destiny." << endl;
					displayMenu();
				}
				string hI;
				string hF;
				cout << "Hour to departure ?" << endl;
				cin >> hI;
				cout << "Hour to arrive ?" << endl;
				cin >> hF;

				users[i]->setHoraInit(hI);
				users[i]->setHoraFim(hF);

				while (selectMode != "road" && selectMode != "node") {
					cout << "Choose adress by road or node ? [road/node]"
							<< endl;
					cin >> selectMode;
				}

				if (selectMode == "node")
					selectAdressByRoad = false;
				//Selecionar pela road----------------------------------------------------------------------------------------
				if (selectAdressByRoad) {
					while (true) {
						RoadFinaly = returnInput("What is the final Road?",
								"Introduce a valid name.");

						if ((v = findRoad(RoadFinaly)) != NULL) {
							cout << "Road Found!" << endl;
							break;

						} else
							cout << "Invalid information. Please try again."
									<< endl;
					}
					//Selecionar pelo node-----------------------------------------------------------------------------------
				} else {
					while (true) {
						cin.ignore(1000);
						if (j == 0) {
							cout << "What is the ID of your destiny adress: ";
							j++;
						} else {
							cout << "ID invalid, new ID again:";
						}
						cin >> ID;

						if ((v = findPlace(Node(ID))) != NULL)
							break;
					}
				}

				cout << v->getInfo().getID() << " | "
						<< v->getAdj()[0].getEdgeInfo().getName() << endl;

				users[i]->setDestAdress(v->getInfo(),
						v->getAdj()[0].getEdgeInfo());

				vector<Node> passP;
				vector<Vertex<Node, Road> > path;

				path = center.BestPath(users[i]->getUserAdress().getLocal(),
						users[i]->getUserDestination().getLocal(), passP);

				users[i]->insertPath(path);

				for (unsigned int i = 0; i < path.size(); i++) {
					cout << path[i].getInfo().getID() << " --->"
							<< path[i].getAdj()[0].getEdgeInfo().getName()
							<< endl;
				}

				flag = false;
				break;
			}
		}

	}

	displayMenu();

}

void Interface::departure() {
	string name;
	string  roadSourc;
	vector<Node> passPoints;
	bool flag = true;
	User *u;

	while (flag) {
		name = returnInput("What is the user ?", "Introduce a valid name.");
		roadSourc = returnInput("Road name ?", " Write a valid Road");

		while ((u = findUser(name, roadSourc)) == NULL) {
			name = returnInput("What is the user ?", "Introduce a valid name.");
			roadSourc = returnInput("Departure location? ","Not a valid option");
		}

		if (!u->getWantDest()) {
			cout << "User don't have a destiny ." << endl;
			displayMenu();
		}

		if (u != NULL)
			flag = false;
		else
			cout << "Invalid information. Please try again." << endl;
	}

	vector<Vertex<Node, Road> > teste = u->getUserPath();
	teste.push_back(*(center.findVertex(u->getUserAdress().getLocal())));
	center.displayGraph(teste);

	for(int i = 0; i < u->getUsersToTakeRide().size(); i++)
	{
		u->getUsersToTakeRide()[i]->resetUser();
	}
	u->resetUser();

	//Apagar Registo
	getchar();

	displayMenu();
	return;

}

void Interface::defineRideFromOtherUserByRoad(){

	if (users.size() == 0) {
		cout << "No users." << endl;
		displayMenu();
	}

	bool existsClientWithCar=false;

	for(unsigned int i=0;i<users.size();i++)
	{
		if(users[i]->getWantDest())
		{
			existsClientWithCar=true;
			break;
		}
	}

	if(!existsClientWithCar)
	{
		cout << "No users with a car to give you a ride." << endl;
		displayMenu();
	}

	string name;
	string RoadChoose,RoadDest;
	bool flag=true;
	bool isInPath=false;
	unsigned int i;
	User *u;

	while (flag) {
		name = returnInput("What is your name ?",
				"Introduce a valid name.");

		RoadChoose = returnInput("What is the road of your adress ?",
				"Introduce a valid name.");

		if((u=findUser(name,RoadChoose))!=NULL)
			flag=false;
	}

	RoadDest = returnInput("What is the road of your destiny ?","Introduce a valid name.");


	for(i=0;i<users.size();i++)
	{
		vector<Vertex<Node,Road> > path=users[i]->getUserPath();
		for(unsigned int j=0;j<path.size();j++)
		{
			string tmpRoad=path[j].getAdj()[0].getEdgeInfo().getName();
			if(kmp(tmpRoad,RoadChoose)!=0
					&& tmpRoad.size()==RoadChoose.size() && RoadDest==users[i]->getUserDestination().getStreet().getName())
			{
				users[i]->pushToUsersToTakeRide(u);
				isInPath=true;
				break;
			}
		}

		if(isInPath)
			break;
	}

	if(isInPath)
	{
		Node tmpNode=users[i]->getUserDestination().getLocal();
		Road tmpRoad=users[i]->getUserDestination().getStreet();

		u->setDestAdress(tmpNode,tmpRoad);

		cout << "Find a user. You will take a ride with Mr/Mrs " << users[i]->getName() << "." << endl;
	}
	else
		cout << "Can't find a user that passes in your actual road." << endl;

	displayMenu();
}

Vertex<Node, Road> *Interface::findPlace(Node n) const {

	return center.findVertex(n);
}

Vertex<Node, Road> *Interface::findRoad(string name) const {

	return center.findVertexByRoad(name);
}

int Interface::returnInt(string s1) {
	int tmp;

	bool fail = false;
	bool eof = false;

	do {
		std::cin.clear();

		if (fail && !eof)
			std::cin.ignore(100, '\n');

		std::cout << s1;
		std::cin >> tmp;

		fail = false;
		eof = false;

		if (std::cin.fail())
			fail = true;

		if (std::cin.eof())
			eof = true;
	} while (fail || eof);

	return tmp;
}

double Interface::returnDouble(string s1) {
	double tmp;

	bool fail = false;
	bool eof = false;

	do {
		std::cin.clear();

		if (fail && !eof)
			std::cin.ignore(100, '\n');

		std::cout << s1;
		std::cin >> tmp;

		fail = false;
		eof = false;

		if (std::cin.fail())
			fail = true;

		if (std::cin.eof())
			eof = true;
	} while (fail || eof);

	return tmp;
}

string Interface::returnInput(string s1, string s2) {
	std::string tmp;
	bool valido = true;

	do {
		std::cin.clear();
		if (!valido)
			std::cout << s2;
		else
			std::cout << s1;

		getline(std::cin, tmp);

		valido = false;

		for (size_t i = 0; i < tmp.size(); i++)
			if (tmp[i] != ' ')
				valido = true;
	} while (std::cin.eof() || !valido);

	for (size_t i = tmp.size() - 1; i >= 0; i--) {
		if (tmp[i] != ' ') {
			tmp.resize(i + 1);
			break;
		}
	}

	return tmp;
}

int Interface::selectMenu(char menor, char maior) {
	std::string linha = "";

	while (linha.length() != 1) {
		getline(std::cin, linha);
		if (std::cin.eof())
			std::cin.clear();

		if (linha.length() != 1
				|| (linha.length() == 1
						&& (linha[0] < menor || linha[0] > maior))) {
			std::cout << "Opcao invalida. Introduza a opcao pretendida: ";
			linha = "";
		}
	}
	return linha[0];
}

User *Interface::findUser(string name, unsigned long ID) const {

	for (unsigned int i = 0; i < users.size(); i++) {
		if (EditDistance(users[i]->getName(),name)==0 && kmp(users[i]->getName(),name)!=0 && users[i]->getUserAdress().getLocal().getID()!=ID)
			return users[i];
	}

	return NULL;
}

User *Interface::findUser(string name, string road) const {

	for (unsigned int i = 0; i < users.size(); i++) {
		/*if (EditDistance(users[i]->getName(), name) == 0
				&& kmp(users[i]->getName(), name) != 0)
		{
			/*if(EditDistance(users[i]->getUserAdress().getStreet().getName(),road)==0 &&
					kmp(users[i]->getUserAdress().getStreet().getName(),road)!=0
					&& users[i]->getUserAdress().getStreet().getName().size()==road.size())*/

		if(users[i]->getName() == name && kmp(users[i]->getName(),name))
			if(users[i]->getUserAdress().getStreet().getName() == road)
			{
				return users[i];
			}
		}


	return NULL;
}

vector<Node> Interface::SelectUsersForRide(Node Sourc, vector<Node> Positions,
		Node Dest, unsigned int lot) {
	vector<Node> Picked;

	vector<Node>::iterator it = Positions.begin();
	vector<Node>::iterator ite = Positions.end();

	unsigned int count = 0;
	for (; it != ite; it++) {
		Picked.push_back(*it);
		if (count >= lot) {
			unsigned int ban = 0;
			if (center.TestALLNodesConected(Sourc, Dest, Picked, ban)
					== false) {
				Picked.erase(Picked.begin() + ban);
			} else
				return Picked;
		}
	}
	while (Picked.size() > 0 && Picked.size() < lot) {
		if (Picked.size() < lot) {
			unsigned int ban = 0;
			if (center.TestALLNodesConected(Sourc, Dest, Picked, ban)
					== false) {
				Picked.erase(Picked.begin() + ban);
			} else
				return Picked;
		}
	}
	return Picked;
}

void Interface::RideUserbyName()
{

	string UserName , RoadSourc,  FriendName;
	bool foundFriend = false;
	bool foundUser = false;
	User *UserF;
	User *Friend;
	if (users.size() == 0) {
			cout << "No users." << endl;
			displayMenu();
		}

		bool existsClientWithCar=false;

		for(unsigned int i=0;i<users.size();i++)
		{
			if(users[i]->getWantDest())
			{
				existsClientWithCar=true;
				break;
			}
		}

		if(!existsClientWithCar)
		{
			cout << "No users with a car to give you a ride." << endl;
			displayMenu();
			return;
		}


		do{
			UserName = returnInput("Username? ", "Invalid option");
			RoadSourc = returnInput("Road of departure? ","Invalid option");

			UserF = findUser(UserName,RoadSourc);

			if(UserF == NULL)
			{
				cout << "User doesn´t exist!" << endl;
				displayMenu();
				return;
			}
			else
			{
				foundUser = true;
				cout << "Hi" << UserF->getName()<< "!" << endl;
			}

		}while(!foundUser);


		do{

			FriendName = returnInput("Friend name? ", "Invalid option");
			RoadSourc  = returnInput("Friend departure location? ", "Invalid option");

			Friend = findUser(FriendName,RoadSourc);

			if(Friend == NULL)
			{
				cout << "Uhhhhh..... I didn´t find yout friend ....  :( " << endl;
			}
			else
			{
				cout << "I found your friend :) " <<  endl;
				foundFriend = true;
			}
		}while(!foundFriend);



		User *Pilot;


		if(Friend->getWantDest())
		{
			cout << "Your friend will drive " << endl;
			 Pilot = Friend;
		}
		else
		{
			bool foundPilot = false;
			for(int i = 0; i < users.size();i++)
			{
				if(users[i]->getWantDest())
				{
					vector <User*> Rides = users[i]->getUsersToTakeRide();
					for(int j = 0; j < Rides.size(); j++)
					{
						if(Rides[j]->getName() == Friend->getName() &&
						   Rides[j]->getUserAdress().getStreet() == Friend->getUserAdress().getStreet())
						{
							Pilot = Rides[j];
							foundPilot = true;
							break;
						}

					}
				}
				if(foundPilot)
					break;
			}

			if(!foundPilot)
			{
				cout << "Your friend doesn´t have a ride....." << endl;
				displayMenu();
				return;
			}
		}


		if(Pilot == NULL)
		{
			cout << "No Pilot ...." << endl;
			displayMenu();
			return;
		}



		if(Pilot->getNumPassegers() > Pilot->getUsersToTakeRide().size())
		{
			cout << "The car have  free space for you !" << endl;
		}
		else{
			cout << "Sorry but the car is full! "<< endl;
			displayMenu();
			return;
		}


		bool inTheWay = false;

		vector<Vertex<Node, Road> > Path = Pilot->getUserPath();
		Path.push_back(*(center.findVertex(Pilot->getUserAdress().getLocal())));
		cout << Path.size() << endl;
		for(int i = 0;i < Path.size(); i++)
		{
			int size = Path[i].getAdj().size();
			for(int j = 0; j < size; j++)
			{if(Path[i].getAdj()[j].getEdgeInfo().getName() == RoadSourc)
			{
				inTheWay = true;
				break;
			}
			//cout << Path[i].getAdj()[j].getEdgeInfo().getName() << endl;
			}

		}

		if(inTheWay)
		{
			Pilot->pushToUsersToTakeRide(UserF);
			cout << "Ride Added " << endl;
			displayMenu();
			return;
		}
		else
		{
			cout << "Sorry Pilot can't pick you  ..... MUAHAHAHAHAH " << endl;
			displayMenu();
			return;
		}

}
//--------------------------------------------------------------------------------------------------------
