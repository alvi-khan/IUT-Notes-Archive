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
		void processJob(Item *item);
		void arrivalHandler ();
		void departureHandler ();
		
		void createTraceFile ();
		void updateTraceFile(string eventType, Item *item);

		inline int& status () { return (status_); }
		inline int& itemArrived () { return (itemArrived_); }
		inline double& arrivalMean () { return (arrivalMean_); }
		inline double& departureMean () { return (departureMean_); }

        void calculateOutputStatistics();

		int id_;
		static Server *servers[2];

		// job averaged
		double cumulativeQueuingDelay_; // time entering service – time entering queue
		double cumulativeSystemTime_;   // time departing – time arrived
		double averageQueuingDelay;
		double averageSystemTime;

		// time averaged
		double lastEventTime_;
		double areaQueueLength_;
		double areaServerUtilization_;
		double areaSystemSize_;
		double averageJobsInSystem;
		double averageJobsInQueue;
		double serverUtilization;

		Queue* queue_;
		ArrivalEvent arrivalEvent;
		DepartureEvent departureEvent_;
		
		int status_;
		static int itemArrived_;
		Item* itemInService_;		
		ofstream traceFile_;

		double arrivalMean_;
		double departureMean_;
		double exponential (double mean);
		void updateStatistics();
};
#endif   




   
