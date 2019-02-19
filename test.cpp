#include "message.h"
#include "klient.h"
#include "centrala.h"
#include "menu.h"

using namespace std;

int main()
{
	string plik = "testowanie.txt";
	Menu *all;
	all = new Menu(plik);
	all->start();
	delete all;
	return 0;
}
