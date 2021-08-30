#include <iostream>

class Fruit
{
protected:
	
	
public:

	std::string nameF;
	std::string colorF;
	Fruit() {}
	Fruit(std::string color) :colorF(color) {}
	
	std::string getName();
	std::string getColor();
};

class Apple : public Fruit
{
public:
	
	Apple() 
	{ 
		nameF = "Apple";
		colorF = "red"; 
	}
	
	Apple(std::string color)
	{
		nameF = "Apple";
		colorF = color;
	}

};

class Banana : public Fruit
{
public:

	Banana() 
	{
		nameF = "Banana";
		colorF = "yellow";
	}

	Banana(std::string color)
	{
		nameF = "Banana";
		colorF = color;
	}

};

class GrannySmith : public Apple
{
public:

	GrannySmith()
	{
		nameF = "Granny Smith apple";
		colorF = "green";
	}

	GrannySmith(std::string color)
	{
		nameF = "Granny Smith apple";
		colorF = color;
	}

};


std::string Fruit::getName()
{
	return nameF;
}

std::string Fruit::getColor()
{
	return colorF;
}

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}