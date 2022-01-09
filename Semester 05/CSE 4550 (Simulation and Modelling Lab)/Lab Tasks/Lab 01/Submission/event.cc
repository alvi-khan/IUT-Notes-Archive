#include "event.h"
#include "server.h"
#include "scheduler.h"

void
Event :: activate (double t)
{
    Scheduler &s = Scheduler :: instance ();
    stime_ = Scheduler :: now ();
    rtime_ = stime_ + t;

    s.schedule (this);
}

void
Event :: cancel ()
{
    //Scheduler :: cancel (this);
}

// ------------------------------------Task-9 (start)--------------------------------------------------
// handle an arrival event
void
ArrivalEvent :: handle ()
{
    // Hint: which class handles the arrival?
    // only 1 line of code is needed
    server->arrivalHandler();
}
// ------------------------------------Task-9 (end)--------------------------------------------------


// ------------------------------------Task-10 (start)--------------------------------------------------
// handle a departure event
void
DepartureEvent :: handle ()
{
    // Hint: which class handles the departure?
    // only 1 line of code is needed
    server->departureHandler();
}
// ------------------------------------Task-10 (end)--------------------------------------------------




