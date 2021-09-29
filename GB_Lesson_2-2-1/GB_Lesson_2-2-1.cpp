#include <iostream>
#include <string>
#include <cstdlib>

const int16_t ZeroState = 0;

class Person
{
public:
	enum Genders
	{
		Male,
		Female
	};

	Person();
	~Person();
	void setName(std::string sName);
	std::string getName();
	void setAge(uint16_t sAge);
	uint16_t getAge();
	void setGender(uint16_t sGender);
	uint16_t getGender();
	void setWeight(uint16_t sWeight);
	uint16_t getWeight();



private:
	std::string name;
	uint16_t age = ZeroState;
	uint16_t gender = Male;
	uint16_t weight = ZeroState;
};

class Student : public Person
{
public:
	Student();
	~Student();

	void setYear(uint16_t sYear);
	uint16_t getYear();
	void increaseYear(uint16_t sYear);

	static void PrintCount()
	{
		std::cout << "Student: " << count() << "\n";
	}

private:
	uint16_t studyYear = ZeroState;

	static int count(const int16_t deltha = ZeroState)
	{
		static int16_t counter = ZeroState;
		return  counter += deltha;
	}
};

Person::Person()
{
}

Person::~Person()
{
}

void Person::setName(std::string sName)
{
	name = sName;
}

std::string Person::getName()
{
	return name;
}

void Person::setAge(uint16_t sAge)
{
	age = sAge;
}

uint16_t Person::getAge()
{
	return age;
}

void Person::setGender(uint16_t sGender)
{
	gender = sGender;
}

uint16_t Person::getGender()
{
	return gender;
}

void Person::setWeight(uint16_t sWeight)
{
	weight = sWeight;
}

uint16_t Person::getWeight()
{
	return weight;
}

Student::Student()
{
	Student::count(1);
}

Student::~Student()
{
	Student::count(-1);
	//std::cout << "-1";
}

void Student::setYear(uint16_t sYear)
{
	studyYear = sYear;
}

uint16_t Student::getYear()
{
	return studyYear;
}

void Student::increaseYear(uint16_t sYear)
{
	studyYear += sYear;
}


int main()
{

	//Student student1;
	//student1.setName("Andrey");
	/*Student student2;
	Student student3;
	student2.setName("Ivan");
	student3.setName("Dmitry");
	std::string personName;
	std::cout << "Input student name: ";
	std::cin >> personName;
	*/

	static int16_t studentCount = 0;
	bool flag = true;
	while (flag)
	{
		std::cout << "Input number of student's: ";
		std::cin >> studentCount;

		if (studentCount <= 0)
		{
			std::cout << "Wrong number! Input again!\n";
		}
		else
		{
			flag = false;
		}
	}

	Student* students = new Student[studentCount];


	for (uint16_t i = 0; i < studentCount; i++)
	{
		std::string sName;
		std::cout << "Input student name: ";
		std::cin >> sName;

		uint16_t sAge;
		std::cout << "Input student age: ";
		std::cin >> sAge;

		uint16_t sWeight;
		std::cout << "Input student weight: ";
		std::cin >> sWeight;

		uint16_t stYear;
		std::cout << "Input year of study: ";
		std::cin >> stYear;

		students[i].setName(sName);
		students[i].setYear(stYear);
		students[i].setAge(sAge);
		students[i].setWeight(sWeight);
	}

	bool flag1 = true;

	system("cls");

	while (flag1)
	{


		std::string sName;
		std::cout << "Input name: ";
		std::cin >> sName;

		for (uint16_t i = 0; i < studentCount; i++)
		{
			if (students[i].getName() == sName)
			{
				std::cout << "WE have this student!\n";
				std::cout << "Student " << students[i].getName() << std::endl;
				std::cout << "Age: " << students[i].getAge() << std::endl;
				std::cout << "Weight " << students[i].getWeight() << std::endl;
				std::cout << "Year of education " << students[i].getYear() << std::endl;
				flag1 = false;
			}
			if (flag1)
			{
				std::cout << "Student not focund! \n";
			}
		}
	}

	delete[] students;

	return 0;
}