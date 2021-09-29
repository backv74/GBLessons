#include <iostream>

template <typename T, typename U>
class Pair
{
protected:
	T m_first;
	U m_second;
public:
	Pair(T first, U second) :m_first(first), m_second(second) {

	}

	T first() const &{
		return m_first;
	}

	U second() const &{
		return m_second;
	}
};

template<typename U>
class StringValuePair : public Pair<std::string, U>
{
public:
	StringValuePair(std::string first, U second) : Pair<std::string, U>(first, second) {}
};

int main() {

	StringValuePair<int> svp("a", 7);

	std::cout << svp.first() << " " << svp.second() << std::endl;

	return 0;
}