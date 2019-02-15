//Stefani Georgievska
//Notifications.h

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace sict {
	class Notifications {
		const Message** msgObj;
		int maxAdd;
		int addAmnt;
	public:
		Notifications();
		Notifications(int);
		~Notifications();
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, Notifications& incomingObject);
}

#endif