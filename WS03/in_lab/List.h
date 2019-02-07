//List.h
//Stefani Georgievska 


#ifndef SICT_LIST_H
#define SICT_LIST_H

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
}

#endif