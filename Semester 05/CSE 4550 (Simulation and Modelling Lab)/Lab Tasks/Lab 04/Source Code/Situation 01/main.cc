#include <iostream>
#include <fstream>
using namespace std;

#include "scheduler.h"
#include "server.h"

void calculateOutputStatistics(Server *servers[2])
{
	double serverCount = 2;
	double overallAverageQueuingDelay = 0;
	double overallAverageSystemTime = 0;
	double overallAverageJobsInSystem = 0;
	double overallAverageJobsInQueue = 0;
	double overallServerUtilization = 0;

	ofstream stats;
	stats.open("output statistics.out", ios::out);
	if (!stats)	cout<<"Cannot open output statistics file.\n";
	stats<< "Output statistics for the simulation:" << endl;

	for (int i=0; i<2; i++)
	{
		overallAverageQueuingDelay += servers[i]->cumulativeQueuingDelay_;
		overallAverageSystemTime += servers[i]->cumulativeSystemTime_;
		overallAverageJobsInSystem += servers[i]->areaSystemSize_ / servers[i]->lastEventTime_;
		overallAverageJobsInQueue += servers[i]->areaQueueLength_ / servers[i]->lastEventTime_;
		overallServerUtilization += servers[i]->areaServerUtilization_ / servers[i]->lastEventTime_;

		stats<<"\nServer No: "<<servers[i]->id_ + 1<<endl;
		stats<<"Average Delay in Queue: "<<servers[i]->cumulativeQueuingDelay_ /servers[i]->itemArrived_<<endl;
		stats<<"Average Delay in System: "<<servers[i]->cumulativeSystemTime_ / servers[i]->itemArrived_<<endl;
		stats<<"Average System Size: "<<servers[i]->areaSystemSize_ / servers[i]->lastEventTime_<<endl;
		stats<<"Average Queue Length: "<<servers[i]->areaQueueLength_ / servers[i]->lastEventTime_<<endl;
		stats<<"Server Utilization: "<<servers[i]->areaServerUtilization_ / servers[i]->lastEventTime_<<endl;
	}

	stats<<"\nOverall: "<<endl;
	stats<<"Average Delay in Queue: "<<overallAverageQueuingDelay/servers[0]->itemArrived_<<endl;
	stats<<"Average Delay in System: "<<overallAverageSystemTime/servers[0]->itemArrived_<<endl;
	stats<<"Average System Size: "<<overallAverageJobsInSystem/serverCount<<endl;
	stats<<"Average Queue Length: "<<overallAverageJobsInQueue/serverCount<<endl;
	stats<<"Server Utilization: "<<overallServerUtilization/serverCount<<endl;

	stats.close();
}

int main ()
{
    Scheduler *sch = new Scheduler();
    sch->initialize();

    Server *s[2];

    for (int i=0; i<2; i++)
    {
    	s[i] = new Server();
    	s[i]->id_ = i;
    	s[i]->createTraceFile();
    }
    for (int i=0; i<2; i++)	Server::servers[i] = s[i];

    double x = 2;
    s[0]->arrivalMean() = 10.0;
    s[0]->departureMean() = x;
    s[1]->departureMean() = x;
    s[0]->initialize();
    s[1]->initialize();

	sch->run ();

	calculateOutputStatistics(s);

	return 0;
}
