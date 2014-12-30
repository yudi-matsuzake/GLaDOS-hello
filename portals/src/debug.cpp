/*

|Simple C++ DEBUG helper|
==================
Author: Gustavo Yudi Bientinezi Matsuzake (Helped by the internet)

Compile with -DDEBUG or define a DEBUG macro (#define DEBUG)
*/

#include <iostream>
#include "debug.h"

//After main function (desctructor of the main) (pt joke: "Te deixará maternalmente órfão")
//void __attribute__ ((destructor))  dtor() {}

using namespace std;


void debug(string f, string msg){

	cout << "DEBUG: "
		<< f << ":\t"
		<< msg << endl;
}
