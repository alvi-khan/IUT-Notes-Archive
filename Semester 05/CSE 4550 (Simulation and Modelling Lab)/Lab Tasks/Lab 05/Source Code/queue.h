#ifndef queue_h
#define queue_h

typedef struct ItemType {
	int id_;
	double arrivalTime_;
	ItemType *next_;
    int currentStation;
    int stationCount;
    int stationList[10];
} Item;

class Queue 
{
	public:
		Queue ();
		inline int& length () { return (length_); }
		void enque (Item *im);
		Item* deque ();
    int length_;
		
	private:

		Item *head_;
		Item *tail_;
};

#endif    






