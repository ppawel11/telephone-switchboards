#include "menu.h"
#include "centrala.h"
#include "klient.h"

using namespace std;

Menu::Menu(string name)
{
	cout<<"Program realizujacy system centrali telefonicznych"<<endl<<"autor: Pawel Lech"<<endl<<endl;
	try
	{
		file.open(name);
		if(!file.is_open())
			throw 1;
	}
	catch(int)
	{	
		cout<<"***BLAD OTWARCIA PLIKU***"<<endl;
		exit(1);
	}
	file<<"start"<<endl;	
}
Menu::~Menu()
{
	file<<"koniec"<<endl;
	/*showCentr();
	for(int i=0;i<eter.size();i++)
		eter[i]->showUsers();*/
	file.close();
}
	
void Menu::start()
{
	int what;
	do
	{
		cout<<"Centrale: "<<eter.size()<<endl<<"Klienci: "<<users.size()<<endl;
		cout<<"Jesli chcesz: "<<endl;
		cout<<"-dodac centrale: \twybierz 1"<<endl;
		if(eter.size() >0)
		{	
			cout<<"-polaczyc centrale: \twybierz 2"<<endl;	
			cout<<"-wyswietlic centrale: \twybierz 3"<<endl;
			cout<<"-dodac uzytkownika: \twybierz 4"<<endl;
			if(users.size() > 1)
				cout<<"-wykonac akcje klienta:\t wybierz 5"<<endl;
		}
		cout<<"-zakonczyc: \t\twybierz 0"<<endl;
		cin>>what;
		switch(what)
		{
			case 0:
				break;
			case 1:
				addCentr();
				break;
			case 2:
				connection();
				break;
			case 3:
				showCentr();
				break;
			case 4:
				addUser();
				break;
			case 5:
				menuKlienta();
				break;
				
		}
	}while(what);
	return;
}
void Menu::addCentr()
{
	Centrala *centr;
	centr = new Centrala(eter.size());
	if(eter.size() == 0)
	{
		eter.push_back(centr);
		file<<"-dodano centrale "<<0<<endl;
	}
	else if(eter.size() == 1)
	{
		eter.push_back(centr);
		file<<"-dodano centrale "<<1<<endl;
		connect(centr, eter[0]);
	}
	else
	{
		cout<<"Do ktorej istniejacej centrali dolaczyc nowa centrale? (0-"<<eter.size()-1<<")";
		int n;
		try
		{
			cin>>n;
			if((n<0) || (n>=eter.size()))
				throw n;
			eter.push_back(centr);
			file<<"-dodano centrale "<<eter.size()-1<<endl;
			connect(centr, eter[n]);
		}
		catch(int n)
		{
			cout<<"Podana wartosc: "<<n<<" jest nieprawidlowa. Nie udalo sie dodac centrali."<<endl;
		}
	}
	return;
}
void Menu::connect(Centrala *a, Centrala *b)
{
	a->addNeigh(b);
	b->addNeigh(a);
	file<<"-polaczono centrale: "<<a->getID()<<" + "<<b->getID()<<endl;
	return;
}
void Menu::showCentr()
{
	for(int i=0;i<eter.size();i++)
	{
		cout<<"---Centrala numer: "<<eter[i]->getID()<<"---"<<endl<<"sasiedzi:"<<endl;
		eter[i]->showNeigh();
		cout<<"uzytkownicy:"<<endl;
		eter[i]->showUsers();
		cout<<endl;
	}
	return;
}
void Menu::addUser()
{
	if(eter.size() == 0)
	{
		cout<<"Najpierw nalezy utworzyc centrale."<<endl<<endl;
		return;
	}
	else if(eter.size() == 1)
	{
		Klient *user;
		if(users.size()>0)
			user = new Klient(eter[0], generateID());
		else
			user = new Klient(eter[0], 0);
		users.push_back(user->getID());
		file<<"-do centrali 0 dodano uzytkownika (id "<<user->getID()<<")"<<endl;
	}
	else
	{
		cout<<"Do ktorej centrali ma zostac dodany nowy uzytkownik? (0-"<<eter.size()-1<<")";
		int n;
		try
		{
			cin>>n;
			if(n<0 || eter.size()<=n)
				throw n;
			Klient *user;
			if(users.size()>0)
				user = new Klient(eter[n], generateID());
			else
				user = new Klient(eter[n], 0);
			file<<"-do centrali "<<n<<" dodano uzytkownika (id "<<user->getID()<<")"<<endl;
			users.push_back(user->getID());
		}
		catch(int n)
		{
			cout<<"Nie istnieje centrala o numerze: "<<n<<endl;
		}
	}
	return;
}
int Menu::generateID()
{
	sort(users.begin(),users.end());
	int i;
	for(i=0;i<users.size();i++)
		if(users[i] != i)
			return i;
	return i;
}
void Menu::connection()
{
	if(eter.size()<2)
	{
		cout<<"Za malo central"<<endl;
		return;
	}
	int m,n;
	cout<<"Wybierz pierwsza centrale do polaczenia? 0-"<<eter.size()-1<<endl;
	cin>>m;

	if(m<0 || eter.size()<=m)
	{
		cout<<"Nie istnieje centrala o numerze: "<<n<<endl;
		return;
	}

	cout<<"Wybierz druga centrale do polaczenia? 0-"<<eter.size()-1<<endl;
	cin>>n;
	if(m<0 || eter.size()<=m)
	{
		cout<<"Nie istnieje centrala o numerze: "<<n<<endl;
		return;
	}

	if(n==m)
	{
		cout<<"Wybrano dwa razy te sama centrale."<<endl;
		return;
	}

	connect(eter[n],eter[m]);
	cout<<"Centrale "<<n<<" oraz "<<m<<" zostaly poprawnie polaczone"<<endl;
	return;
}
void Menu::menuKlienta()
{
	if(users.size() == 0)
	{	
		cout<<"Brak klientow"<<endl;
		return;
	}
	int m;
	if(eter.size() == 0)
	{
		cout<<"Najpierw nalezy utworzyc centrale."<<endl<<endl;
		return;
	}
	else if(eter.size() == 1)
	{
		m=0;
	}
	else 
	{
		cout<<"Wybierz centrale: ";
		cin>>m;
		if(m<0 || eter.size()<=m)
		{
			cout<<"Nie istnieje centrala o numerze: "<<m<<endl;
			return;
		}
	}
	eter[m]->showUsers();
	cout<<"Wybierz id uzytkownika: "<<endl;
	int n;
	cin>>n;
	Klient* chosen = eter[m]->getUser(n);
	if(chosen == NULL)
	{
		cout<<"W wybranej centrali brak uzytkownika o id: "<<n<<endl;
		return;
	}
	cout<<"Zeby: "<<endl;
	cout<<"Wyslac wiadomosc:\twybierz 1"<<endl;
	cout<<"Odczytac wiadomosci:\twybierz 2"<<endl;
	cout<<"Usunac wszystkie wiadomosci:\twybierz 3"<<endl;
	cout<<"Doladowac kotno:\twybierz 4"<<endl;
	cout<<"Wrocic do menu glownego:\twybierz 0"<<endl;
	int q;
	cin>>q;
	switch(q)
	{
		case 0:
			return;
		case 1:
			chosen->sendMsg();
			file<<"-uzytkownik "<<chosen->getID()<<" nadal wiadomosc"<<endl;
			break;
		case 2:
			chosen->readAll();
			break;
		case 3:
			chosen->deleteAll();
			break;
		case 4:
			chosen->doladuj();
			break;
	}
	return;
}
			
	
		
		
