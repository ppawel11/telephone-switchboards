#ifndef KLIENT_H_INCLUDED
#define KLIENT_H_INCLUDED

#include <string>
#include <iostream>
#include <list>
#include <memory>

using namespace std;
class Message;
class Centrala;
class Klient
{
	int id;
	Centrala *c;
	list<Message*> received;
	int konto;
public:
	Klient(Centrala *centr, int x);
	void show();
	void sendMsg();
	void getMsg(Message *m);
	void readAll();
	int getID();
	void deleteAll();
	void doladuj();
}; 

#endif // KLIENT_H_INCLUDED
