//Stefani Georgievska
//Notifications.cpp

#include <iostream>
#include "Notifications.h"

namespace sict {
	Notifications::Notifications() {
		msgObj = nullptr;
		maxAdd = 0;
		addAmnt = 0;
	}
	Notifications::Notifications(int maximum) {
		if (maximum > 0) {
			msgObj = new const Message*[maximum];
				maxAdd = maximum;
		} else
		msgObj = nullptr;
	}
	
	Notifications::~Notifications() {
		delete[msgObj];
	}
	Notifications::Notifications& operator+=(const Message& msg) {
		if (!msg.empty() && (msgAdd < msg) {
			
		}
		return *this;
	}
	Notifications::Notifications& operator-=(const Message& msg) {

	}
	void Notifications::display(std::ostream& os) const {
		for (int i = 0; i < addAmnt; i++) {
			this->msgObj[i]->display(os);
		}
	}
	size_t Notifications::size() const {
		return addAmnt;
	}
}