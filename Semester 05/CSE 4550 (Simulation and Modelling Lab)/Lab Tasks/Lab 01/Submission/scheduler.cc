#include "scheduler.h"
#include "event.h"

#include <iostream>
#include <fstream>
using namespace std;

Event* Scheduler :: eventList_; // always points to the first event
double Scheduler :: clock_; // keeps track of clock time
Scheduler* Scheduler::instance_;

Scheduler :: Scheduler ()
{
    eventList_ = 0;
}

double
Scheduler :: now ()
{
    return clock_;
}


Scheduler&
Scheduler :: instance ()
{
    return (*instance_);
}

void
Scheduler :: schedule (Event* e)
{
    addEvent (e);
}


void
Scheduler :: updateClock (double t)
{
    // ------------------------------------Task-1 (start)--------------------------------------------------
    // update clock time
    // Hint: is there any variable to hold the clock time?
    // only 1 line of code is needed
    clock_ = t;

    // ------------------------------------Task-1 (end)--------------------------------------------------
}

void
Scheduler :: initialize ()
{
    // ------------------------------------Task-2 (start)--------------------------------------------------
    // initialize the simulator
    // Hint: What's the value of clock in the beginning?
    // only 1 line of code is needed
    clock_ = 0;
    // ------------------------------------Task-2 (end)--------------------------------------------------
}

void
Scheduler :: addEvent (Event *e)
{

    Event *current;
    Event *previous;

    // add in an empty list
    if (!eventList_)
    {
        eventList_ = e;
        e->next_ = 0;

        return;
    }



    previous = eventList_;
    // ------------------------------------Task-3 (start)--------------------------------------------------
    // Add the event as a first element in a non-empty list (its just linked list manipulation)
    // Hint: check if  event to be added expires before the current first event
    // Should not require more than 4 lines of code
    // Don't forget to return after adding the event

    if (eventList_->expire() > e->expire())
    {
        e->next_ = eventList_;
        eventList_ = e;
        return;
    }





    // ------------------------------------Task-3 (end)--------------------------------------------------




    current = previous -> next_;
    while (current != 0)
    {
        if (e->expire() < current->expire ())
        {
            e->next_ = current;
            previous->next_=e;
            return;
        }
        else
        {
            current = current->next_;
            previous = previous->next_;
        }
    }



    // add as the last element
    previous->next_ = e;
    e->next_ = 0;

    return;
}

Event*
Scheduler :: removeEvent ()
{
    Event* temp;

    temp = eventList_;
    eventList_ = eventList_->next_;

    return temp;
}


void
Scheduler :: trigger ()
{
    Event* temp;

    temp = removeEvent ();
    temp->handle ();
}

// ------------------------------------Task-4 (start)--------------------------------------------------
// Complete the run() function

void
Scheduler :: run ()
{
    Event * temp;
    // Hint: Follow the flow-chart provided in theory class
    // Hint: loop through the eventList_ to perform necessary actions
    // Should not require more than 4 lines of code

    while (eventList_ != 0)
    {
        temp = eventList_;
        updateClock(temp->expire());
        trigger();
    }


}
// ------------------------------------Task-4 (end)--------------------------------------------------





