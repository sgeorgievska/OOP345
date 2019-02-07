//List.h
//Stefani Georgievska 

#ifndef SICT_LIST_H
#define SICT_LIST_H
#include <iostream>

namespace sict {
	template <typename T, int N>
	class List {
		size_t elementAmount = 0;
		T arrayAmount[N];

	public: 
		size_t size() const {
			return elementAmount;
		}

		const T& operator[](size_t i) const {
			return arrayAmount[i];
		}
		
		void operator+=(const T& t) {
			if (elementAmount < N) {
				arrayAmount[elementAmount++] = t;
			}
		}
	};

	template <typename T, typename L, typename V, int N>
	class LVList : public List <T, N> {
	public: 
		V accumulate(const L& label) const {
			SummableLVPair<L, V> tempSummable;
			V sumResult = tempSummable.getInitialValue();

			for (size_t i = 0; i < ((List<T, N>&)*this).size(); i++) {
				tempSummable = ((List<T, N>&)*this)[i];
				sumResult = tempSummable.sum(label, sumResult);
			}
			return sumResult;
		} 
	};
}

#endif