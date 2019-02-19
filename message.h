#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Message
{
protected:
	string text;
	int add;
	int from;
	int price;
public:
	virtual void read() = 0;
	int to();
	int getPrice();
};

class Premium: public Message
{
public:
	Premium(int);
	void read();
};

class Regular: public Message
{
public:
	Regular(int);
	void read();
};

#endif // MESSAGE_H_INCLUDED
