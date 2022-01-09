#include "JobHandler.h"

Station *JobHandler::stations[5];

JobHandler::JobHandler() {
    stations[0] = new Station(0, 3);
    stations[1] = new Station(3, 2);
    stations[2] = new Station(5, 4);
    stations[3] = new Station(9, 3);
    stations[4] = new Station(12, 1);
    for (int i=0; i<5; i++)
        stations[i]->id_ = i;
}

void JobHandler::sendToNextStation(Item *item)
{
    item->currentStation++;
    int currentStation = item->currentStation;
    int totalStations = item->stationCount;
    if (currentStation < totalStations)
    {
        int nextStationIndex = item->stationList[currentStation];
        stations[nextStationIndex]->processJob(item);
    }
}

void JobHandler::calculateOutputStatistics()
{
    double averageQueueingDelay = 0;
    double averageSystemDelay = 0;
    double averageSystemSize = 0;
    double averageQueueLength = 0;
    double averageServerUtilization = 0;

    for (int i=0; i<5; i++)
    {
        stations[i]->calculateOutputStatistics();
        averageQueueingDelay += stations[i]->averageQueueingDelay;
        averageSystemDelay += stations[i]->averageSystemDelay;
        averageSystemSize += stations[i]->averageSystemSize;
        averageQueueLength += stations[i]->averageQueueLength;
        averageServerUtilization += stations[i]->averageServerUtilization;
    }
    averageQueueingDelay /= 5;
    averageSystemDelay /= 5;
    averageSystemSize /= 5;
    averageQueueLength /= 5;
    averageServerUtilization /= 5;

    ofstream stats;
    stats.open("SYSTEM OUTPUT.out", ios::out);
    if (!stats)	cout<<"Cannot open output statistics file.\n";
    stats<< "Output statistics for the System :" << endl;
    stats<<"Average Delay in Queue: "<<averageQueueingDelay<<endl;
    stats<<"Average Delay in System: "<<averageSystemDelay<<endl;
    stats<<"Average System Size: "<<averageSystemSize<<endl;
    stats<<"Average Queue Length: "<<averageQueueLength<<endl;
    stats<<"Average Server Utilization: "<<averageServerUtilization<<endl;
    stats.close();
}