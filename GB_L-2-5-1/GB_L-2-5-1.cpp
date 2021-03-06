#include <iostream>
template <class T>
class Pair1
{
private:
	T m_first;
	T m_second;

public:
	Pair1(T first, T second): m_first(first), m_second(second) {}

	T first() const {
		return m_first;
	}

	T second() const {
		return m_second;
	}
};

int main() {

	Pair1<int> p1(6, 9);
	std::cout << "Pair: " << p1.first() << " " << p1.second() << std::endl;

	const Pair1<double> p2(2.3, 7.8);
	std::cout << "Pair: " << p2.first() << " " << p2.second() << std::endl;
	return 0;
 }