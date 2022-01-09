#include "scheduler.h"
#include "event.h"

#include <iostream>
#include <fstream>
using namespace std;

Event* Scheduler :: eventList_;
double Scheduler :: clock_;
Scheduler* Scheduler::instance_;

Scheduler :: Scheduler () {
	eventList_ = 0;
}

double
Scheduler :: now () {
	return clock_;
}


Scheduler&
Scheduler :: instance () {
	return (*instance_);
}

void
Scheduler :: schedule (Event* e) {
	addEvent (e);
}


void
Scheduler :: updateClock (double t) {
	clock_ = t;
}

void
Scheduler :: initialize () {
	clock_ = 0;
}

void
Scheduler :: addEvent (Event *e) {

	Event *current;
	Event *previous;

	// add in an empty list
	if (!eventList_) {
		eventList_ = e;
		e->next_ = 0;

		return;
	}

	// add as a first element in a non-empty list
	previous = eventList_;
	if (e->expire () < eventList_->expire()) {
		e->next_ = eventList_;
		eventList_ = e;

		return;
	}

	// add as an intermediate element
	current = previous -> next_;
	while (current != 0) {
		if (e->expire() < current->expire ()) {
			e->next_ = current;
			previous->next_=e;
			return;
		} else {
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
Scheduler :: removeEvent () {
	Event* temp;

	temp = eventList_;
	eventList_ = eventList_->next_;

	return temp;
}

void
Scheduler :: cancel (Event *e) {
	Event* current;
	Event* previous;

	previous = eventList_;
	if (previous->eventType ()!= e->eventType ()) {
		eventList_ = eventList_->next_;
		return;
	}
	current = previous->next_;
	while (current->next_!=0) {
		if (current->eventType ()== e->eventType ()) {
			previous->next_ = current->next_;
			return;
		} else {
			previous = current;
			current = current->next_;
		}
	}
}

void
Scheduler :: trigger () {
	Event* temp;

	temp = removeEvent ();
	temp->handle ();
}


void
Scheduler :: run () {
	Event * temp;

	while (eventList_ != 0) {
		temp = removeEvent ();

		updateClock (temp->expire ());

		temp->handle ();
	}
}






