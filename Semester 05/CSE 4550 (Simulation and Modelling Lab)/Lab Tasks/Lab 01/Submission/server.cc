#include "server.h"
#include "scheduler.h"

#include <malloc.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;


Server :: Server () : a_(this), d_(this)
{
    queue_ = new Queue ();
}

// ------------------------------------Task-5 (start)--------------------------------------------------
// Complete the exponential() function
// Hint: Follow the flow-chart of generating exponential random variable provided in the theory class
// should not require more than 3 lines of code
double
Server :: exponential(double mean)
{
    srand(time(0));
    double u = (double) rand() / (RAND_MAX);    // u ~ U(0, 1)
    return (- (mean * log(u)));    // -(1/λ) ln(1-u)



}
// ------------------------------------Task-5 (end)--------------------------------------------------

// ------------------------------------Task-6 (start)--------------------------------------------------
// complete the server initialization function
void
Server :: initialize ()
{
    // TASK-PART-1
    // initialize the state variables
    // 2 lines of code
    status_ = 0;
    itemArrived_ = 0;


    // TASK-PART-2
    // Schedule the very first event
    // Hint: the first event is always an arrival event
    // Hint: from where do you draw the events? what's the purpose of exponential() function defined above?
    // Hint: after you've got the event, how do you schedule it? (check event.cc)
    // 2 lines of code

    double t = exponential (arrivalMean_);
    a_.activate(t);

    // ------------------------------------Task-6 (end)--------------------------------------------------
}

void
Server :: createTraceFile ()
{
    trace_.open ("trace.out", ios::out);
    if (!trace_)
    {
        cout << "cannot open the trace file.\n";
    }
    trace_<< "trace file for the simulation" << endl;
    trace_ << "format of the file" << endl;
    trace_ << "<event> <time> <item id> <server status> <queue size>" << endl << endl;
}

// ------------------------------------Task-7 (start)--------------------------------------------------
// Complete the arrivalHandler() function
void
Server :: arrivalHandler ()
{
    Item* temp;
    // TASK-PART-1
    // increment the counter for arrived events (check available variables in server.h)
    // 1 line of code
    itemArrived_++;
    temp = (Item*) malloc (sizeof(Item));
    temp->id_ = itemArrived_;

    // TASK-PART-2
    // write to the trace file following the trace file format
    // Hint: check which information are required?
    // can be done in a single line
    trace_ << "a\t" << Scheduler::now() << "\t" << temp->id_ << "\t" << status_ << "\t" << queue_->length() << endl;

    if (status () == 0)
    {
        // TASK-PART-3
        // change server status
        // 1 line of code
        status_ = 1;
        // TASK-PART-4
        // write to the trace file again
        // 1 line of code
        trace_ << "s\t" << Scheduler::now() << "\t" << temp->id_ << "\t" << status_ << "\t" << queue_->length() << endl;

        // TASK-PART-5
        // update the current event that's being served to the arrived event
        // 1 line of code
        itemInService_ = temp;

        // schedule a departure for the arrived event
        double t = exponential (departureMean_);
        d_.activate (t);
    }
    else
    {
        // TASK-PART-6
        // put the arrived event in the queue if the server is busy
        // Hint: any function in queue.cc that can be put to use?
        // 1 line of code
        queue_->enque(temp);
    }

    // schedule arrival events till number of events is less then 100
    if (temp->id_ < 100)
    {
        double t = exponential (arrivalMean_);
        a_.activate (t);
    }
}
// ------------------------------------Task-7 (end)--------------------------------------------------


// ------------------------------------Task-8 (start)--------------------------------------------------
// Complete the departureHandler() function
void
Server :: departureHandler ()
{
    // write to the trace file before handling the departure
    if (queue_->length() > 0)
    {
        trace_ << "d\t" << Scheduler::now () << "\t" << itemInService_->id_ << "\t" << status_ << "\t" << queue_->length() << endl;
    }
    else
    {
        trace_ << "d\t" << Scheduler::now () << "\t" << itemInService_->id_ << "\t" << 0 << "\t" << queue_->length() << endl;
    }

    if (queue_->length() > 0)
    {
        // TASK-PART-1
        // put the next event in queue to service
        // Hint: is there any function in queue.cc that can be put to use?
        // 1 line of code
        itemInService_ = queue_->deque();

        // TASK-PART-2
        // write to the trace file after putting the event in service
        // can be done in a single line
        trace_ << "s\t" << Scheduler::now() << "\t" << itemInService_->id_ << "\t" << status_ << "\t" << queue_->length() << endl;

        double t = exponential (departureMean_);
        d_.activate (t);
    }
    else
    {
        // update state variables if there's no event in queue (queue_length=0)
        status () = 0;
        itemInService_ = 0;
    }
}
// ------------------------------------Task-8 (end)--------------------------------------------------

