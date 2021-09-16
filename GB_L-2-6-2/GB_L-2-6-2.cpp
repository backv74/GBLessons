#include <iostream>

namespace std {
	template<class CharT, class Traits = char_traits<CharT>>
	std::basic_ostream <CharT, Traits>& endll(std::basic_ostream<CharT, Traits>& os) {
		os.put(os.widen('\n'));
		os.put(os.widen('\n'));
		os.flush();
		return os;
	}

}

int main() {

	std::cout << "1 2 3" << std::endll << "1 2 3";

	return 0;
}