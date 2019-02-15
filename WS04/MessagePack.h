//Stefani Georgievska
//MessagePack.h

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include "Message.h"

namespace sict {
	class MessagePack {
		Message* objRef; 
		size_t objAmount;
	public:
		MessagePack();
		MessagePack(Message* arrayMsg[], size_t elementAmount);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, MessagePack& MsgPackObj);
}


#endif