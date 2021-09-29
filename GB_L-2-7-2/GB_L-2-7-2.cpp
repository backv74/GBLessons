#include <iostream>
#include <memory>

class Date {
protected:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day, int month, int year) :m_day(day), m_month(month), m_year(year) {}

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
	int getDay() const {
		return m_day;
	}
	int getMonth() const{
		return m_month;
	}
	int getYear() const{
		return m_year;
	}

};

int ComparisonPtr(Date *m_date1, Date *m_date2) {

	if (m_date1->getDay() >= m_date2->getDay())
	{
		return m_date1->getDay();
	}
	else {
		return m_date2->getDay();
	}
}

void SwapPtr(Date *date1, Date* date2) {
	int temp = 0;
	temp = date1->getDay();
	date1->setDay(date2->getDay());
	date2->setDay(temp);
}

int main() {
	std::unique_ptr<Date> date1(new Date(20, 9, 2021));
	std::unique_ptr<Date> date2(new Date(31, 9, 2021));

	std::cout << ComparisonPtr(date1.get(), date2.get());

	std::cout << std::endl;
	std::cout << "Date1 = " << *date1;
	std::cout << std::endl;
	std::cout << "Date2 = " << *date2;

	SwapPtr(date1.get(), date2.get());
	
	std::cout << std::endl;
	std::cout << "Date1 = " << *date1;
	std::cout << std::endl;
	std::cout << "Date2 = " << *date2;

	return 0;
}