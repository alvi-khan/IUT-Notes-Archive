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
		Server (Queue *queue);
		void processJob(Item *item);
		void departureHandler ();
		
		int id_;

		double cumulativeQueuingDelay_; // time entering service – time entering queue
		double cumulativeSystemTime_;   // time departing – time arrived
		double lastEventTime_;
		double areaQueueLength_;
		double areaServerUtilization_;
		double areaSystemSize_;

		DepartureEvent departureEvent_;
        static ArrivalEvent arrivalEvent_;
		
		int status_;
		Item* itemInService_;
        int itemsServed = 0;
		ofstream traceFile_;

		double departureMean_;
        static double arrivalMean_;
		static double exponential (double mean);
		void updateStatistics();
        void calculateOutputStatistics();
        void createTraceFile ();
        void updateTraceFile(string eventType, Item *item);

    static Item *createItem();

    static void arrivalHandler();
    Queue *queue_;

    static void initialArrival();
};
#endif   




   
