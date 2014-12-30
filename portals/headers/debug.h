/*

|Simple C++ DEBUG helper|
==================
Author: Gustavo Yudi Bientinezi Matsuzake (Helped by the internet)

Compile with -DDEBUG or define a DEBUG macro (#define DEBUG)
*/

#ifndef _DEBUG_H_
#include <sstream>

using namespace std;


/*	MACROS	*/
/*
MACRO FUNCTION TO_STRING (X)
=============================
To do something like that:

DEBUG("i = " << i);

*/
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

/*
MACRO FUNCTION DEBUG(X)
=======================
call debug(string func, string msg) function, where:
func - name function
msg  - debug message

This MACRO calls the debug() with the macro __PRETTY_FUNCTION__ that returns the name of the function.
*/

#ifdef DEBUG
	#undef DEBUG
	#define DEBUG(X) debug(__PRETTY_FUNCTION__, TO_STRING(X))
#else
	#define DEBUG(X)
#endif

/*	FUNCTIONS 	*/

void debug(string f, string debug_msg);

#endif
