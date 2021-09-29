#include <iostream>
#include <memory>

class Date {
protected:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day, int month, int year):m_day(day), m_month(month), m_year(year){}
	
	friend std::ostream& operator<< (std::ostream& os, const Date& date) {
		os << date.m_day << "." << date.m_month << "." << date.m_year;
		return os;
	}

	void setDay(int day) {
		m_day = day;
	}
	void setMonth(int month) {
		m_month = month;
	}
	void setYear(int year) {
		m_year = year;
	}
};

int main() {
	std::unique_ptr<Date> date(new Date(20,9,2021));
	date->setDay(21);
	date->setMonth(9);
	date->setYear(2021);
	
	std::cout << *date;
	std::cout << std::endl;
	auto today = std::move(date);
	std::cout << *today;
	std::cout << std::endl;
	if (date == nullptr) {
		std::cout << "Date Nullptr";
	}
	else {
		std::cout << "Date not Nullptr";
	}
	if (today == nullptr) {
		std::cout << std::endl << "Today Nullptr";
	}
	else {
		std::cout << std::endl << "Today not Nullptr";
	}
	return 0;
}