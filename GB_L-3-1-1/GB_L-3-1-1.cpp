#include <iostream>
#include <vector>
#include <tuple>
#include <optional>

struct Person {
	std::string surname;
	std::string name;
	std::optional<std::string> patronymic;
};

std::ostream& operator<<(std::ostream& os, const Person& pers) {
	os << pers.name << "  ";
	if (pers.patronymic) {
		os << *pers.patronymic << "  ";
	}
	os << pers.surname;
	return os;
}

bool operator<(const Person& per1, const Person& per2) {
	return std::tie(per1.name, per1.patronymic, per1.surname) < std::tie(per2.name, per2.patronymic, per2.surname);
}

bool operator==(const Person& per1, const Person& per2) {
	return std::tie(per1.name, per1.patronymic, per1.surname) == std::tie(per2.name, per2.patronymic, per2.surname);
}

struct PhoneNumber {
	int country_code;
	int sity_code;
	std::string number;
	std::optional<int> additional_number;
};

std::ostream& operator<<(std::ostream& os, const PhoneNumber& phone) {
	os << "+ " << phone.country_code << " (" << phone.sity_code << ") " << phone.number;
	if (phone.additional_number) {
		os << " " << *phone.additional_number;
	}
	return os;
}



int main() {


	return 0;
}