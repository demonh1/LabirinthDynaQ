// Dyna-Q.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "QLearningAgent.h"
#include "Environment.h"
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	std::auto_ptr<QLearningAgent>DynaQ(new QLearningAgent);
	DynaQ->run();
	


	return 0;
}

