//LVPair.h
//Stefani Georgievska 

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>
#include <string>
namespace sict {
	template <typename L, typename V>
	class LVPair {
		L label_t;
		V value_t;
	public:
		LVPair() : label_t(), value_t{}{}
		LVPair(const L& label, const V& value) : label_t{ label }, value_t{ value } {};
		virtual void display(std::ostream& os) const {
			os << label_t << " : " << value_t << std::endl;
		};
			/*label_t = label;
			value_t = value;
		}*/

		const L& label() const {
			return label_t;
		}
		const V& value() const {
			return value_t; 
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V> & pair) {
		pair.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V initialSummation;
		static size_t minFieldWidth;
	public:
		SummableLVPair() {
			//leaves obj in safe empty state
		}

		SummableLVPair(const L& label, const V& v) : LVPair<L, V>::LVPair(label, v) {
			LVPair(label, v);
			if (minFieldWidth < label.size())
				minFieldWidth = label.size();
			//minFieldWidth++;

		}
		const V& getInitialValue() {
			return initialSummation;
		}

		V sum(const L& label, const V& sum) const {
			//returns a V objected containing SUM of the value of current object, and partially accumulated sum
			V vObject = sum; 
			if (label == LVPair<L, V>::label())
				vObject = LVPair<L, V>::value() + sum;
			return vObject;
		}

		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minFieldWidth);
			LVPair<L, V>::display(os);
		}
	};

	template<typename L, typename V>
	size_t SummableLVPair<L, V>::minFieldWidth = 0;

	template <> 
	int SummableLVPair<std::string, int>::initialSummation = 0;

	template<> 
	std::string SummableLVPair<std::string, std::string>::initialSummation = "";

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label,
		const std::string& sum) const {
		std::string final = sum;
		if (label == LVPair<std::string, std::string>::label())
			final = sum + " " + LVPair<std::string, std::string>::value();
		return final;
	}
}
#endif
