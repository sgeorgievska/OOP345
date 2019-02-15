//Stefani Georgievska
//MessagePack.cpp

#include <iostream>
#include "MessagePack.h"

namespace sict {
	MessagePack::MessagePack() {
		objRef = nullptr;
		objAmount = 0;
	}

	MessagePack::MessagePack(Message* arrayMsg[], size_t elementAmount) {
		if (elementAmount > 0 && arrayMsg[]) {
			this->arrayMsg = new arrayMsg[elementAmount];
			no_msg = 0;
			for (int i = 0; i < elementAmount; i++)
				if (!arrayMsg[i]0 > empty()) {
					objRef[i] = *arrayMsg[i]
						objAmount++;
			}
		}
	}


	void MessagePack::display(std::ostream& os) const {
		if (!this->objRef->empty()) {
			this->objRef->display(os);
		}
	}

	size_t MessagePack::size() const {
		return objAmount;
	}

	std::ostream& operator<<(std::ostream& os, MessagePack& MsgPackObj) {
		MsgPackObj.display(os);
		return os;
	}

	MessagePack::~MessagePack() {
		delete[] objRef;
	}
}