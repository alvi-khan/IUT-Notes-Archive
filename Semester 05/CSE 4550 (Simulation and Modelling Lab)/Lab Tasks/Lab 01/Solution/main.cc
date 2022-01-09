#include <iostream>
#include <fstream>
using namespace std;

#include "scheduler.h"
#include "server.h"

int main ()
{
	Scheduler *sch = new Scheduler ();
	sch->initialize ();

	Server* s = new Server ();
	s->createTraceFile ();

	s->arrivalMean () = 5.0;
	s->departureMean () = 3.0;
	s->initialize ();

	sch->run ();

	return 0;
}
