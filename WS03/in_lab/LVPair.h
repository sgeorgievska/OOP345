//LVPair.h
//Stefani Georgievska 

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

namespace sict {
	template <typename L, typename V>
	class LVPair {
		L label_t;
		V value_t; 
	public: 
		LVPair() {
			//leave object in safe empty state
		}

		LVPair(const L& label, const V& value) {
			label_t = label;
			value_t = value;
		}

		void display(std::ostream& os) const {
			os << this->label_t << " : " << this->value_t << std::endl;
		}

	};

	template <typename L, typename V>
		std::ostream& operator<<(std::ostream& os, const LVPair<L, V> & pair) {
			pair.display(os);
			return os;
		}
}

#endif