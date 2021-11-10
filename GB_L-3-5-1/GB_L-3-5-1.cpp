#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <iterator>
#include <type_traits>

// Lesson 5 Part 1 Start
template <typename Iterrator, typename ValueType = typename std::iterator_traits<Iterrator>::value_type>
void uniqueWords(const Iterrator& begin, const Iterrator& end) {
	std::set<ValueType> unique;
	for (auto it = begin; it != end; ++it) {
		unique.insert(*it);
	}
	std::copy(unique.begin(), unique.end(), std::ostream_iterator<ValueType> {std::cout, " \n"});
}
// Lesson 5 Part 1 End

// Lesson 5 Part 2 Start
void ScreenReadSort() {
	const size_t sdvig = 1;
	std::multimap<size_t,std::string> screenSort;
	std::set<size_t> posNum;
	std::string screenRead;
	std::cout << "Input text: " << std::endl;
	std::getline(std::cin, screenRead);
	
	for (size_t it = 0; it < screenRead.size(); ++it) {
		if (screenRead[it] == '.' || screenRead[it] == '!' || screenRead[it] == '?') {
			posNum.insert(it);
		}
	}
	size_t buf = 0;
	for (auto c: posNum) {
		screenSort.insert({ c-buf + sdvig,screenRead.substr(buf, c - buf + sdvig) });
		std::cout << screenRead.substr(buf, c - buf + sdvig) << std::endl;
		buf = c + sdvig + sdvig;	
	}
	for (auto c : screenSort) {
		std::cout << c.second << " " << c.first << std::endl;
	}
}
// Lesson 5 Part 2 End

int main() {
	std::vector<std::string> v{ "abc", "abc", "bcd", "bcd", "uit" };
	uniqueWords(v.begin(), v.end());
	ScreenReadSort();
	
	return 0;
}