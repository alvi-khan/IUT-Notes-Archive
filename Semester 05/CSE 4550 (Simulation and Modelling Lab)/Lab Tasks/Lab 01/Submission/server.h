#ifndef server_h
#define server_h

#include "event.h"
#include "queue.h"
//#include "scheduler.h"

#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

class Server
{
public:
    Server ();
    void initialize ();
    void arrivalHandler ();
    void departureHandler ();

    void createTraceFile ();

    inline int& status ()
    {
        return (status_);
    }
    inline int& itemArrived ()
    {
        return (itemArrived_);
    }
    inline double& arrivalMean ()
    {
        return (arrivalMean_);
    }
    inline double& departureMean ()
    {
        return (departureMean_);
    }

private:
    Queue* queue_;
    ArrivalEvent a_;
    DepartureEvent d_;

    int status_; // 1 means busy, 0 means idle
    int itemArrived_; // count of already arrived events
    Item* itemInService_; // holds reference to the current item (event) in service
    ofstream trace_; // used for writing to the trace file

    double arrivalMean_; // mean time for arrival events
    double departureMean_; // mean time for departure events
    double exponential (double mean);
};
#endif





