test: test.o klient.o message.o centrala.o menu.o
	g++ test.o klient.o message.o centrala.o menu.o -o test
	rm *o
test.o: test.cpp
	g++ -c test.cpp
klient.o: klient.cpp
	g++ -c klient.cpp
message.o: message.cpp
	g++ -c message.cpp
cenrala.o: centrala.cpp
	g++ -c centrala.cpp
menu.o: menu.cpp
	g++ -c menu.cpp
