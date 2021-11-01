#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <map>
#include <functional>
#include <numeric>

// Start Part 1 lesson 3-4
template <class T, typename Container>
void insert_sorted(Container &cont, const T &num) {
	
	auto low = std::lower_bound(cont.begin(), cont.end(), num);
	cont.insert(low, num);
}
// End Part 1 lesson 3-4

// Start Part 2 lesson 3-4
void errorSum() {
	float param;
	std::vector<float> base(100);
	std::generate(base.begin(), base.end(),
		[]() {return float(rand())/ 100;});
	std::vector<float> fraction;
	std::copy(base.begin(), base.end(), std::back_inserter(fraction));
	
	std::transform(fraction.begin(), fraction.end(), fraction.begin(),
		[&param](float x) {
			return std::pow(modf(x, &param),2);});

	for (auto n : base) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (auto n : fraction) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	float sum = std::accumulate(fraction.begin(), fraction.end(), 0.0f);
	std::cout << sum;
}
// End Part 2 lesson 3-4

int main() {

	errorSum();
	return 0;
}