#include <iostream>

template <typename T, typename U>
class Pair
{
private:
	T m_first;
	U m_second;
public:

	Pair(T first, U second) : m_first(first), m_second(second) {

	}

	T first() const  {
		return m_first;
	}

	U second() const {
		return m_second;
	}
};

int main() {
	Pair<int, double> p1(6, 7.8);

	std::cout << "Pair: " << p1.first() << " " << p1.second() << std::endl;

	const Pair<double, int> p2(3.4, 5);
	std::cout << "Pair: " << p2.first() << " " << p2.second() << std::endl;

	return 0;
}