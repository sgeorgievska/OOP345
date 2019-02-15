//Message.cpp
//Stefani Georgievska
#include <iostream>
#include <string>
#include <fstream>
#include "Message.h"

namespace sict; 

Message::Message() {
	user_t = "";
	reply_t = "";
	tweet_t = "";
}

bool Message::empty() const {
	return(user_t.empty() &&
		tweet_begin.empty() &&
		reply_begin.empty());
}

Message::Message(const std::string& str) { 
	size_t ending = std::string::npos;

	size_t reply_begin = str.find('@');

	size_t tweet_begin;

	size_t space = str.find(' ');
	
	if (space != ending) {
		if (reply_begin == ending) {
			tweet_begin = space + 1;
			reply_t = "";
			tweet_t = str.substr(tweet_begin);
		}
		else {
			tweet_begin = str.find(' ', reply_begin + 1);
			reply_t = str.substr(reply_begin + 1, tweet_begin - (reply_begin + 1));
			tweet_t = str.substr(tweet_begin + 1);
		}
	user_t = str.substr(0, space);
		}
	}

void Message::display(std::ostream& os) const {
	if (!empty()) {
		if (reply_t != "") {
			os << ">User  : " user_t << std::endl;
			<< "Reply  : " reply_t << std::endl;
			<< "Tweet  : " tweet_t << std::endl;
		}
		else {
			os ">User  : " << user_t << std::endl;
			<< "Tweet  : " << tweet_t << std::endl;
		}
	}
}
