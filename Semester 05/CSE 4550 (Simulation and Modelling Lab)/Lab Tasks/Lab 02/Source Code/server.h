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

		inline int& status () { return (status_); }
		inline int& itemArrived () { return (itemArrived_); }
		inline double& arrivalMean () { return (arrivalMean_); }
		inline double& departureMean () { return (departureMean_); }

        void calculateOutputStatistics();

	private:
		Queue* queue_;
		ArrivalEvent a_;
		DepartureEvent d_;
		
		int status_;
		int itemArrived_;
		Item* itemInService_;		
		ofstream trace_;

		double arrivalMean_;
		double departureMean_;
		double exponential (double mean);

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

		void updateStatistics();
};
#endif   




   
