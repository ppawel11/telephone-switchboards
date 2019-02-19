#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class Centrala;

class Menu
{
	ofstream file;
	vector<Centrala*> eter;
	vector<int> users;

	void addCentr();
	void showCentr();
	void connect(Centrala *a, Centrala *b);
	void connection();
	void addUser();
	/*void send();
	void read();*/
	int generateID();
	void menuKlienta();
public:
	void start();
	Menu(string);
	~Menu();
};
