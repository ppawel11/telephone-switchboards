#include "klient.h"
#include "message.h"
#include "centrala.h"

using namespace std;

Klient::Klient(Centrala *centr, int x)
{
	id = x;
	konto = 0;
	c = centr;
	centr->addUser(this);
}
void Klient::show()
{
	cout<<"Klient id: "<<id<<" "<<"stan konta: "<<konto<<endl;
}
void Klient::sendMsg()
{
	if(konto<=0)
	{
		cout<<"Klient nie posiada wystarczajaco srodkow, aby nadac wiadomsc."<<endl;
		return;
	}
	Message *msg;
	cout<<"Jaka wiadomosc ma zostac nadana:"<<endl;
	cout<<"-zwykla wiadmosc (cena podstawowa: 0)\twybierz 0"<<endl;
	cout<<"-wiadomosc premium (cena podstawowa: 3)\twybierz 1"<<endl;
	int k;
	cin>>k;
	if(k==0)
		msg = new Regular(id);
	else if(k==1)
	{
		if(konto<=3)
		{
		cout<<"Klient nie posiada wystarczajaco srodkow, aby nadac wiadomsc premium."<<endl;
		return;
		}
		msg = new Premium(id);
	}
	else
	{
		cout<<"Wybrano niepoprawny typ wiadomosci"<<endl;
		return;
	}
	vector<Centrala*> pusty;
	int koszt = 1+msg->getPrice();
	if(c->passMsg(msg, pusty, koszt))
	{
		cout<<"Wiadomosc poprawnie wyslana"<<endl<<endl;
		konto -= koszt;
	}
	else
		cout<<"Nie udalo sie wyslac wiadomosci"<<endl<<endl;
	return;
}
void Klient::getMsg(Message *m)
{
	received.push_back(m);
	return;
}
void Klient::readAll()
{	
	cout<<endl;
	if(received.size())
	{
		cout<<"Klient id: "<<id<<" liczba wiadomsci: "<<received.size()<<endl;
		list<Message*>::iterator i;
		int k=1;
		for(i = received.begin(); i != received.end(); i++)
		{	
			cout<<"Wiadomosc nr "<<k<<": ";
			(*i)->read();
			k++;
		}		
	}
	else
		cout<<"Klient id: "<<id<<" brak nowych wiadomosci"<<endl;
	cout<<endl;
	return;
}
void Klient::deleteAll()
{
	received.clear();
	return;
}
int Klient::getID()
{
	return id;
}
void Klient::doladuj()
{
	cout<<"Wprowadz kwote: ";
	int x;
	cin>>x;
	if(x>0)
		konto += x;
	else
		cout<<"Wprowadzono niepoprawna wartosc."<<endl;
	return;
}
	

