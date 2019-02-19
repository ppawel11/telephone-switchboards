#include "centrala.h"
#include "klient.h"
#include "message.h"

using namespace std;

Centrala::Centrala(int k)
{
	id = k;
	cout<<"Utworzono centrale "<<k<<endl;
}
void Centrala::addUser(Klient *kl)
{
	users.push_back(kl);
	return;
}
void Centrala::showUsers()
{
	for(int i = 0; i<users.size(); i++)
		users[i]->show();
	return;
}
int Centrala::find(int x)
{	
	for(int i=0;i<users.size();i++)
		if(users[i]->getID() == x)
			return i;
	return -1;
}
bool Centrala::passMsg(Message *msg, vector<Centrala*> &v, int &koszt)
{
	toPass = msg;
	int ix = find(toPass->to());
	if(!(ix<0))
	{
		users[ix]->getMsg(toPass);
		return true;
	}
	else
	{
		int inf=0;
		for(int i=0;i<neigh.size();i++)
		{	
			inf = 0;
			for(int j=0;j<v.size();j++)
				if(neigh[i]->getID() == v[j]->getID())
					inf =1;
			if(!inf)
			{
				v.push_back(neigh[i]);
				if(neigh[i]->passMsg(toPass, v, koszt))
				{
					koszt++;
					return true;
				}
			}
		}
				
	}	
	return false;
}
void Centrala::addNeigh(Centrala *c)
{
	neigh.push_back(c);
	return;
}
int Centrala::getID()
{
	return id;
}
void Centrala::showNeigh()
{
	for(int i=0;i<neigh.size();i++)
		cout<<"Centrala numer: "<<neigh[i]->getID()<<endl;
	return;
}
Klient* Centrala::getUser(int id)
{
	int k = find(id);
	if(!(k<0))
		return users[k];
	else
		return NULL;
}

