#include "server.h"
#include "scheduler.h"

#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int Server::itemArrived_;

Server::Server():arrivalEvent_(this), departureEvent_(this)
{
	queue_ = new Queue ();
	lastEventTime_ = 0;
	cumulativeQueuingDelay_= 0;
    cumulativeSystemTime_ = 0;
    areaQueueLength_ = 0;
    areaServerUtilization_ = 0;
    areaSystemSize_ = 0;
    arrivalMean_ = 0.0;
}

double Server::exponential(double mean)
{
	double r = (double)rand()/RAND_MAX;
	double ex = -mean * log (r);
	return ex;
}

void Server::initialize()
{
	status_ = 0;
	itemArrived_ = 0;

	if (id_ == 0)
	{
		double t = exponential(arrivalMean_);
		arrivalEvent_.activate(t);
	}
}

void Server::createTraceFile()
{
	traceFile_.open("trace_" + to_string(id_) + ".out", ios::out);
	if (!traceFile_)	cout << "cannot open the trace file.\n";

	traceFile_ << "trace file for the simulation" << endl;
	traceFile_ << "format of the file" << endl;
	traceFile_ << "<event> <time> <item id> <server status> <queue size>" << endl << endl;
}

void Server::updateTraceFile(string eventType, Item *item)
{
	traceFile_ << eventType << "\t" << Scheduler::now () << "\t" << item->id_ << "\t" << status_ << "\t" << queue_->length() << endl;
}

void Server::processJob(Item *item)
{
	updateStatistics();
	item->arrivalTime_ = Scheduler::now();
	updateTraceFile("a", item);

	if (status() == 0)
	{
		cumulativeQueuingDelay_ += Scheduler::now() - item->arrivalTime_;
		status() = 1;
		updateTraceFile("s", item);
		itemInService_ = item;

		double t = exponential(departureMean_);
		departureEvent_.activate (t);
	}
	else	queue_->enque(item);
}

void Server::arrivalHandler()
{
	Item* temp;
	temp = new Item();
	itemArrived_++;
	temp->id_ = itemArrived_;

	processJob(temp);

	if (temp->id_ < 100)
	{
		double t = exponential(arrivalMean_);
		arrivalEvent_.activate(t);
	}
}

void Server::departureHandler()
{
    updateStatistics();
    cumulativeSystemTime_ += Scheduler::now() - itemInService_->arrivalTime_;

    if (queue_->length() > 0)
    {
    	updateTraceFile("d", itemInService_);
    }
    else
	{
		status_ = 0;
		updateTraceFile("d", itemInService_);
	}

	if (next_ != nullptr)	next_->processJob(itemInService_);

	if (queue_->length() > 0)
	{
		itemInService_ = queue_->deque();
        cumulativeQueuingDelay_ += Scheduler::now() - itemInService_->arrivalTime_;
		updateTraceFile("s", itemInService_);
		double t = exponential (departureMean_);
		departureEvent_.activate (t);
	}
	else
	{
		status_ = 0;
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
	if (next_ != nullptr)	return;

	double serverCount = id_ + 1;
	double overallAverageQueuingDelay = 0;
	double overallAverageSystemTime = 0;
	double overallAverageJobsInSystem = 0;
	double overallAverageJobsInQueue = 0;
	double overallServerUtilization = 0;

	Server *temp = this;
	while (temp->prev_ != nullptr)	temp = temp->prev_;

	ofstream stats;
	stats.open("output statistics.out", ios::out);
	if (!stats)	cout<<"Cannot open output statistics file.\n";
	stats<< "Output statistics for the simulation:" << endl;

	while (temp != nullptr)
	{
		overallAverageQueuingDelay += temp->cumulativeQueuingDelay_;
		overallAverageSystemTime += temp->cumulativeSystemTime_;
		overallAverageJobsInSystem += temp->areaSystemSize_ / lastEventTime_;
		overallAverageJobsInQueue += temp->areaQueueLength_ / lastEventTime_;
		overallServerUtilization += temp->areaServerUtilization_ / lastEventTime_;

		stats<<"\nServer No: "<<temp->id_ + 1<<endl;
		stats<<"Average Delay in Queue: "<<temp->cumulativeQueuingDelay_ / itemArrived_<<endl;
		stats<<"Average Delay in System: "<<temp->cumulativeSystemTime_ / itemArrived_<<endl;
		stats<<"Average System Size: "<<temp->areaSystemSize_ / lastEventTime_<<endl;
		stats<<"Average Queue Length: "<<temp->areaQueueLength_ / lastEventTime_<<endl;
		stats<<"Server Utilization: "<<temp->areaServerUtilization_ / lastEventTime_<<endl;
		temp = temp->next_;
	}

	stats<<"\nOverall: "<<endl;
	stats<<"Average Delay in Queue: "<<overallAverageQueuingDelay/itemArrived_<<endl;
	stats<<"Average Delay in System: "<<overallAverageSystemTime/itemArrived_<<endl;
	stats<<"Average System Size: "<<overallAverageJobsInSystem/serverCount<<endl;
	stats<<"Average Queue Length: "<<overallAverageJobsInQueue/serverCount<<endl;
	stats<<"Server Utilization: "<<overallServerUtilization/serverCount<<endl;

    stats.close();
}
