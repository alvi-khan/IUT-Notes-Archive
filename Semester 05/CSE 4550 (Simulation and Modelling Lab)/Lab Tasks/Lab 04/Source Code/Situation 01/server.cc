#include "server.h"
#include "scheduler.h"

#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int Server::itemArrived_;
Server* Server::servers[];

Server::Server():arrivalEvent(this), departureEvent_(this)
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
		arrivalEvent.activate(t);
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
	Server *server = servers[0];
	int minSystemLength = server->queue_->length() + server->status_;

	for (int i=1; i<2; i++)
	{
		int systemLength = servers[i]->queue_->length() + servers[i]->status_;
		if (systemLength < minSystemLength)
		{
			minSystemLength = systemLength;
			server = servers[i];
		}
	}

	Item* temp;
	temp = new Item();
	itemArrived_++;
	temp->id_ = itemArrived_;

	server->processJob(temp);

	if (temp->id_ < 100)
	{
		double t = exponential(arrivalMean_);
		servers[0]->arrivalEvent.activate(t);
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