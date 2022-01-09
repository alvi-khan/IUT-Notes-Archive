#include "server.h"
#include "scheduler.h"

#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
#include "JobHandler.h"

double Server::arrivalMean_;
ArrivalEvent Server::arrivalEvent_(nullptr);
Server::Server(Queue *queue): departureEvent_(this)
{
    queue_ = queue;
    status_ = 0;
	lastEventTime_ = 0;
	cumulativeQueuingDelay_= 0;
    cumulativeSystemTime_ = 0;
    areaQueueLength_ = 0;
    areaServerUtilization_ = 0;
    areaSystemSize_ = 0;
}

double Server::exponential(double mean)
{
	double r = (double)rand()/RAND_MAX;
	double ex = -mean * log (r);
	return ex;
}

void Server::createTraceFile()
{
	traceFile_.open("server_" + to_string(id_) + ".out", ios::out);
	if (!traceFile_)	cout << "cannot open the trace file.\n";

	traceFile_ << "trace file for the simulation" << endl;
	traceFile_ << "format of the file" << endl;
	traceFile_ << "<event> <time> <item id> <server status> <queue size>" << endl << endl;
}

void Server::updateTraceFile(string eventType, Item *item)
{
	traceFile_ << eventType << "\t" << item->arrivalTime_ << "\t" << item->id_ << "\t" << status_ << "\t" << queue_->length() << endl;
}

void Server::processJob(Item *item)
{
    itemsServed++;
	updateStatistics();
	updateTraceFile("a", item);

    cumulativeQueuingDelay_ += Scheduler::now() - item->arrivalTime_;
    status_ = 1;
    updateTraceFile("s", item);
    itemInService_ = item;

    double t = exponential(departureMean_);
    departureEvent_.activate (t);
}

Item* Server::createItem() {
    Item* temp;
    temp = new Item();
    Scheduler::itemCount++;
    temp->id_ = Scheduler::itemCount;
    temp->currentStation = -1;

    double r = (double)rand()/RAND_MAX;
    if (r <=0.3)
    {
        temp->stationCount = 4;
        temp->stationList[0] = 2;
        temp->stationList[1] = 0;
        temp->stationList[2] = 1;
        temp->stationList[3] = 4;
    }
    else if (r <= 0.8)
    {
        temp->stationCount = 3;
        temp->stationList[0] = 3;
        temp->stationList[1] = 0;
        temp->stationList[2] = 2;
    }
    else
    {
        temp->stationCount = 5;
        temp->stationList[0] = 1;
        temp->stationList[1] = 4;
        temp->stationList[2] = 0;
        temp->stationList[3] = 3;
        temp->stationList[4] = 2;
    }
    return temp;
}

void Server::initialArrival()
{
    arrivalEvent_.activate(exponential(arrivalMean_));
}

void Server::arrivalHandler()
{
    Item *item = createItem();
    JobHandler::sendToNextStation(item);
    if (item->id_ < 100)
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
    JobHandler::sendToNextStation(itemInService_);
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