#ifndef JOBHANDLER_H
#define JOBHANDLER_H


#include "Station.h"

class JobHandler {
public:
    JobHandler();
    static Station* stations[5];

    static void sendToNextStation(Item *item);

    void calculateOutputStatistics();
};


#endif
