#ifndef STATION_H
#define STATION_H

#include "queue.h"
#include "server.h"

class Station {
public:
    Station(int firstServer, int serverCount);
    void processJob(Item *item);
    Queue* queue_;
    int id_;
    int serverCount;
    Server* servers[10];
    double averageQueueingDelay;
    double averageSystemDelay;
    double averageSystemSize;
    double averageQueueLength;
    double averageServerUtilization;

    void calculateOutputStatistics();
};


#endif
