#include "server.h"
#include "scheduler.h"

#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


Server :: Server () : a_(this), d_(this)
{
	queue_ = new Queue ();
	lastEventTime_ = 0;
	cumulativeQueuingDelay_= 0;
    cumulativeSystemTime_ = 0;
    areaQueueLength_ = 0;
    areaServerUtilization_ = 0;
    areaSystemSize_ = 0;
}

double
Server :: exponential(double mean) {

	double r = (double)rand()/RAND_MAX;

	double ex = -mean * log (r);

	return ex;
}

void
Server :: initialize () {
	status_ = 0;
	itemArrived_ = 0;

	double t = exponential (arrivalMean_);
	//trace_ << "interarrival time " << t << endl;
	a_.activate (t);
}

void
Server :: createTraceFile () {
	trace_.open ("trace.out", ios::out);
	if (!trace_) {
		cout << "cannot open the trace file.\n";
	}
	trace_<< "trace file for the simulation" << endl;
	trace_ << "format of the file" << endl;
	trace_ << "<event> <time> <item id> <server status> <queue size>" << endl << endl;
}

void
Server :: arrivalHandler () {
    updateStatistics();
	Item* temp;

	itemArrived_++;
	temp = (Item*) malloc (sizeof(Item));
	temp->id_ = itemArrived_;
	temp->arrivalTime_ = Scheduler::now();

	trace_ << "a\t" << Scheduler::now () << "\t" << temp->id_ << "\t" << status_ << "\t" << queue_->length() << endl;

	if (status () == 0) {
		// write to the trace file
        cumulativeQueuingDelay_ += Scheduler::now() - temp->arrivalTime_;
		status() = 1;
		trace_ << "s\t" << Scheduler::now () << "\t" << temp->id_ << "\t" << status_ << "\t" << queue_->length() << endl;
		itemInService_ = temp;

		double t = exponential (departureMean_);
		//trace_ << "\tservice time = " << t << endl;
		d_.activate (t);
	} else {
		queue_->enque(temp);
	}

	if (temp->id_ < 100) {
		double t = exponential (arrivalMean_);
		//trace_ << "\tinterarrival time = " << t << endl;
		a_.activate (t);
	}
}

void
Server :: departureHandler () {
    updateStatistics();
    cumulativeSystemTime_ += Scheduler::now() - itemInService_->arrivalTime_;
	// write to the trace file
	if (queue_->length() > 0) {
		trace_ << "d\t" << Scheduler::now () << "\t" << itemInService_->id_ << "\t" << status_ << "\t" << queue_->length() << endl;
	} else {
		trace_ << "d\t" << Scheduler::now () << "\t" << itemInService_->id_ << "\t" << 0 << "\t" << queue_->length() << endl;
	}

	if (queue_->length() > 0) {
		itemInService_ = queue_->deque ();
        cumulativeQueuingDelay_ += Scheduler::now() - itemInService_->arrivalTime_;

		// write to the trace file
		trace_ << "s\t" << Scheduler::now () << "\t" << itemInService_->id_ << "\t" << status_ << "\t" << queue_->length() << endl;

		double t = exponential (departureMean_);
		//trace_ << "\tservice time = " << t << endl;
		d_.activate (t);
	} else {
		status () = 0;
		itemInService_ = 0;
	}
}

void Server::updateStatistics()
{
    areaQueueLength_ += queue_->length() * (Scheduler::now() - lastEventTime_);
    areaServerUtilization_ += status_ * (Scheduler::now() - lastEventTime_);
    areaSystemSize_ += (queue_->length() + status_) * (Scheduler::now() - lastEventTime_);

    lastEventTime_ = Scheduler::now();
}

void Server::calculateOutputStatistics()
{
    averageQueuingDelay = cumulativeQueuingDelay_ / itemArrived_;
    averageSystemTime = cumulativeSystemTime_ / itemArrived_;

    averageJobsInSystem = areaSystemSize_ / lastEventTime_;
    averageJobsInQueue = areaQueueLength_ / lastEventTime_;
	serverUtilization = areaServerUtilization_ / lastEventTime_;

	ofstream stats;
	stats.open("output statistics.out", ios::out);

	if (!stats)	cout<<"Cannot open output statistics file.\n";
	stats<< "Output statistics for the simulation:" << endl;

    stats<<"Average Delay in Queue: "<<averageQueuingDelay<<endl;
    stats<<"Average Delay in System: "<<averageSystemTime<<endl;
    stats<<"Average System Size: "<<averageJobsInSystem<<endl;
    stats<<"Average Queue Length: "<<averageJobsInQueue<<endl;
    stats<<"Server Utilization: "<<serverUtilization;

    stats.close();
}
