//Message.h
//Stefani Georgievska

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <iostream>
#include <string>

namespace sict {
	class Message {
		std::string user_t; 
		std::string reply_t;
		std::string tweet_t;
		std::string ending;
		std::string reply_begin;
		std::string tweet_begin;
		
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}

#endif