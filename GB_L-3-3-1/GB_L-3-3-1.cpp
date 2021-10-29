#include <iostream>
#include <list>
#include <vector>

// Start Part 1
void ListAverage(std::list<float>& list) {
	size_t count = 0;
	float average = 0.0f;
	for (auto it : list) {
		average += it;
		count++;
	}
	average /= count;
	list.push_back(average);
}
// End Part 1

// Start Part 3
template <typename T>
class MyIterrator {
protected:
	T* m_ptr;
	size_t itSize = 0;
public:
	
	MyIterrator(size_t n = 0) : itSize(n) 
	{
		m_ptr = new T[n];
	}
	
	T& operator[] (const size_t& n) {
		if (n > 0 && n < itSize) {
			return m_ptr[n];
		}
		return m_ptr[0];
	}
	T* begin() { return &m_ptr[0]; }
	T* end() { return &m_ptr[itSize]; }
	friend std::ostream& operator<<(std::ostream& s, const MyIterrator<T>& n);
	
	MyIterrator& operator ++ () { return *this+1; } ;
	friend bool operator != (const MyIterrator<T>& lhs, const MyIterrator<T>& rhs);
};

template <typename T>
std::ostream& operator<<(std::ostream& s, const MyIterrator<T>& n) {
	s << MyIterrator<T>::arr[n];
	return s;
}

template <typename T>
bool operator != (const MyIterrator<T>& lhs, const MyIterrator<T>& rhs) {
	return lhs.m_ptr != rhs.m_ptr;
}
// End Part 3
int main() {

	std::list<float> book;
	book.push_back(3.3f);
	book.push_back(5);
	book.push_back(9.3f);
	ListAverage(book);
	
	for (auto it : book) {
		std::cout << it << std::endl;
	}
	return 0; 
	
	MyIterrator<int> iter(3); 
	iter[0] = 3;
	iter[1] = 2;
	iter[2] = 10;
	for (auto it : iter) {
		std::cout << it << std::endl;
	}
}