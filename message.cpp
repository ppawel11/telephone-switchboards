#include "message.h"

using namespace std;


int Message::to()
{
	return add;
}
int Message::getPrice()
{
	return price;
}
void Regular::read()
{
	cout<<"Nadawca: "<<from<<" Tresc: "<<text<<endl;
} 
void Premium::read()
{
	cout<<"Jasnie pan "<<from<<" przesyla wiadomosc o tresci: "<<text<<endl;
}
Regular::Regular(int f)
{
	from = f;
	price = 0;
	cout<<endl<<"Nowa wiadomosc: "<<endl;
	cout<<"Adresat: ";
	cin>>add;
	cout<<"Tresc (max 10 znakow): ";
	cin.ignore();
	getline(cin, text);	
	if(text.length() > 10)
	{
		cout<<"Wiadomosc zostala przycieta do 10 znakow."<<endl;
		cout<<"Aby wyslac dluzsza wiadomosc, nalezy nadac wiadomosc premium"<<endl;
		text = text.substr(0,10);
	}
	else
		cout<<"Wiadomosc popawnie utworzona"<<endl;
}
Premium::Premium(int f)
{
	from = f;
	price = 3;
	cout<<endl<<"Nowa wiadomosc: "<<endl;
	cout<<"Adresat: ";
	cin>>add;
	cout<<"Tresc: ";
	cin.ignore();
	getline(cin, text);	
	cout<<"Wiadomosc premium popawnie utworzona"<<endl;
}
