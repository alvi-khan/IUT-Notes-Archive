#include <iostream>
#include <fstream>
using namespace std;

#include "scheduler.h"
#include "server.h"
#include "JobHandler.h"



int main ()
{
    Scheduler *sch = new Scheduler();
    sch->initialize();
    JobHandler *jobHandler = new JobHandler();
    Server::arrivalMean_ = 10.0;
    Server::initialArrival();
    sch->run ();
	jobHandler->calculateOutputStatistics();
	return 0;
}
