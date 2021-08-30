#include <iostream>

class Fruit
{
protected:
	std::string nameF;
	std::string colorF;
	
public:
		
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
	
	Apple(std::string color): Fruit(color)
	{
		nameF = "Apple";
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

	Banana(std::string color):Fruit(color)
	{
		nameF = "Banana";
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

	GrannySmith(std::string color):Apple(color)
	{
		nameF = "Granny Smith apple";
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