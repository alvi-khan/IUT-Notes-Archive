#include <iostream>
#include <fstream>
using namespace std;

#include "scheduler.h"
#include "server.h"

int main ()
{
	int serverCount = 2;

    Scheduler *sch = new Scheduler();
    sch->initialize();

    Server *s[serverCount];

    for (int i=0; i<serverCount; i++)
    {
    	s[i] = new Server();
    	s[i]->id_ = i;
    	s[i]->createTraceFile();
    }
    for (int i=0; i<serverCount; i++)
    {
    	if (i == 0)	s[i]->prev_ = nullptr;
    	else		s[i]->prev_ = s[i - 1];
    	if (i == serverCount - 1)	s[i]->next_ = nullptr;
    	else						s[i]->next_ = s[i + 1];
    }

    s[0]->arrivalMean() = 1;
    s[0]->departureMean () = 0.7;
	s[1]->departureMean() = 0.7;

	for (int i=0; i<serverCount; i++)	s[i]->initialize();

	sch->run ();

	s[serverCount - 1]->calculateOutputStatistics();

	return 0;
}
