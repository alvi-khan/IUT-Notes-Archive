#include "Station.h"
#include "scheduler.h"

Station::Station(int firstServer, int serverCount) {
    queue_ = new Queue();
    this->serverCount = serverCount;
    for (int i=0; i<serverCount; i++)
    {
        Server *server = new Server(queue_);
        servers[i] = server;
        servers[i]->id_ = firstServer + i;
        servers[i]->departureMean_ = 8.75;
        servers[i]->createTraceFile();
    }
}

void Station::processJob(Item *item) {
    item->arrivalTime_ = Scheduler::now();
    bool served = false;

    for (int i=0; i<serverCount; i++)
    {
        if (servers[i]->status_ == 0)
        {
            servers[i]->processJob(item);
            served = true;
            break;
        }
    }
    if (!served)
    {
        queue_->enque(item);
    }
}

void Station::calculateOutputStatistics()
{
    double overallAverageQueuingDelay = 0;
    double overallAverageSystemTime = 0;
    double overallServerUtilization = 0;

    ofstream stats;
    stats.open("station_" + to_string(id_) +  ".out", ios::out);
    if (!stats)	cout<<"Cannot open output statistics file.\n";
    stats<< "Output statistics for the Station " + to_string(id_) + ":" << endl;

    for (int i=0; i<serverCount; i++)
    {
        overallAverageQueuingDelay += servers[i]->cumulativeQueuingDelay_;
        overallAverageSystemTime += servers[i]->cumulativeSystemTime_;
        overallServerUtilization += servers[i]->areaServerUtilization_ / servers[i]->lastEventTime_;

        stats<<"\nServer No: "<<servers[i]->id_ + 1<<endl;
        stats<<"Average Delay in Queue: "<<servers[i]->cumulativeQueuingDelay_ /servers[i]->itemsServed<<endl;
        stats<<"Average Delay in System: "<<servers[i]->cumulativeSystemTime_ / servers[i]->itemsServed<<endl;
        stats<<"Average System Size: "<<servers[i]->areaSystemSize_ / servers[i]->lastEventTime_<<endl;
        stats<<"Average Queue Length: "<<servers[i]->areaQueueLength_ / servers[i]->lastEventTime_<<endl;
        stats<<"Server Utilization: "<<servers[i]->areaServerUtilization_ / servers[i]->lastEventTime_<<endl;
    }
    averageQueueingDelay = overallAverageQueuingDelay/serverCount;
    averageSystemDelay = overallAverageSystemTime/serverCount;
    averageServerUtilization = overallServerUtilization/serverCount;
    averageQueueLength = servers[0]->areaQueueLength_/Scheduler::now();
    averageSystemSize = averageQueueLength + averageServerUtilization;

    stats<<"\nOverall: "<<endl;
    stats<<"Average Delay in Queue: "<<averageQueueingDelay<<endl;
    stats<<"Average Delay in System: "<<averageSystemDelay<<endl;
    stats<<"Average System Size: "<<averageSystemSize<<endl;
    stats<<"Average Queue Length: "<<averageQueueLength<<endl;
    stats<<"Average Server Utilization: "<<averageServerUtilization<<endl;

    stats.close();
}
