#include <iostream>

class Ex {
private:
	float m_x;
public:
	Ex(float x):m_x(x){}
};

class Bar {
private:
	float m_y;
public:
	Bar(float y=0):m_y(y) {}

	void serY(float a)  {
		if (m_y + a > 100) {
			throw Ex(a * m_y);
		}
		else {
			m_y = a;
		}
	}
};

int main() {
	Bar y;
	int n;
	try {
		do
		{
			std::cout << "Input number: ";
			std::cin >> n;
			y.serY(n);
		} while (n != 0);
		
	}
	catch (Ex) {
		std::cerr << "Error!";
	}
	return 0;
}