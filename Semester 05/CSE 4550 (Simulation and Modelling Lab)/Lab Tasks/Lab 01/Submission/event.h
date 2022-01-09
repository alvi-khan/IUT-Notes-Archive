#ifndef event_h
#define event_h

class Server;

class Event
{
public:
    Event (Server* s) : server (s)
    {
        stime_ = 0.0;
        rtime_ = 0.0;
    }

    inline int& eventType ()
    {
        return (eventType_);
    }
    inline double& expire ()
    {
        return (rtime_);
    }
    inline double& start ()
    {
        return (stime_);
    }

    void activate (double t);
    void cancel ();
    virtual void handle () = 0;

    Event* next_;
protected:
    Server* server;

private:
    int eventType_;	// represented by event id
    double stime_;
    double rtime_;
    int status_;
};

class ArrivalEvent : public Event
{
public:
    ArrivalEvent (Server* s) : Event(s) {}
    void handle ();
};

class DepartureEvent : public Event
{
public:
    DepartureEvent (Server* s) : Event(s) {}
    void handle ();
};

#endif











