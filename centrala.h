#ifndef CENTRALA_H_INCLUDED
#define CENTRALA_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Klient;
class Message;

class Centrala
{	
	int id;
	vector<Klient*> users;
	vector<Centrala*> neigh;
	Message *toPass;
public:
	Centrala(int k);
	void addUser(Klient *kl);
	void addNeigh(Centrala *c);
	int find(int x);
	Klient* getUser(int id);
	void showUsers();
 	int getID();
	bool passMsg(Message *msg, vector<Centrala*> &v, int &koszt);
	void showNeigh();
};
	
	
#endif // CENTRALA_H_INCLUDED
