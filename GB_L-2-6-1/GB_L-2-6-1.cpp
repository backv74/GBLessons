#include <iostream>

bool CheckNumber(const std::string& num) {
	bool flag;

	if ((num[0] == '-') || ((num[0] >= '0') && (num[0] <= '9'))) {
		flag = true;
	}
	else {
		flag = false;
		return flag;
	}

	for (size_t i = 1; i < num.size();i++) {
		if ((num[i] < '0') || (num[i] > '9')) {
			flag = false;
		}
	}

	return flag;
}

int main() {
	bool flag1 = true;
	std::string number;
	while (flag1) {
		std::cout << "Input number: ";
		std::cin >> number;
		if (!CheckNumber(number)) {
			std::cout << "Error! Input only integer number!" << std::endl;
		} 
		else { flag1 = false; }
	}
	
	int total = std::atoi(number.c_str());
	std::cout << "Number - " << total;
	return 0;
}