#include <iostream>

const std::string DivisionByZero = "DivisionByZero!";

template <typename T>
T div(T a, T b) {
		if (b == 0) {
			throw DivisionByZero;
		}
	return a / b;
}

int main() {

	double a = 10;
	double b = 0;
	try {
		double c = div(a, b);
		std::cout << c;
	}
	catch (const std::string&) {
		std::cerr << "DivisionByZero!" << std::endl;
	}
	return 0;
}