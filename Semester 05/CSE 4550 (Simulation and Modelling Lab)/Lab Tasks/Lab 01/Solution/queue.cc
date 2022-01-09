#include "queue.h"

Queue :: Queue () {
	head_ = tail_ = 0;
	length_ = 0;
}

void
Queue :: enque (Item *im) {
	Item* it = tail_;

	if (!tail_) {
		head_ = tail_ = im;
	} else {
		tail_->next_ = im;
		tail_ = im;
	}

	tail_->next_ = 0;
	++length_;
}

Item*
Queue :: deque () {
	if (!head_)
		return 0;

	Item* it = head_;
	head_ = it->next_;
	if (it == tail_)
		head_ = tail_ = 0;
	--length_;

	return it;
}
