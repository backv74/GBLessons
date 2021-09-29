#include <iostream>
#include <cmath>

const double Null = 0;
const double PI = 3.141592653589793238463;


class Figure
{
public:
	virtual void area() = 0;

	virtual ~Figure()
	{
	//	std::cout << "Figure out" << std::endl;
	}
};

class Parallelogram : public Figure
{
private:
	double sizeA = Null;
	double sizeB = Null;
public:

	virtual void area()
	{
		std::cout << "No area!" << std::endl;
	}

	Parallelogram(double paramA, double paramB): sizeA(paramA), sizeB(paramB) {	}

	virtual ~Parallelogram()
	{
	//	std::cout << "Parallegram out" << std::endl;
	}
};

class Rectangle : public Parallelogram
{
private:
	double sizeA = Null;
	double sizeB = Null;

public:
	Rectangle(double paramA, double paramB) : Parallelogram(paramA, paramB), sizeA(paramA),
		sizeB(paramB) {}

	virtual ~Rectangle()
	{
	//	std::cout << "Rectangle out" << std::endl;
	}

	virtual void area()
	{
		std::cout << "Rectangle area - " << sizeA * sizeB << std::endl;
	}
};

class Squre : public Parallelogram
{
private:
	double sizeA = Null;
	double sizeB = Null;

public:
	Squre(double paramA, double paramB) : Parallelogram(paramA, paramB), sizeA(paramA),
		sizeB(paramB) {	}

	virtual ~Squre()
	{
	//	std::cout << "Squre out" << std::endl;
	}

	virtual void area()
	{
		std::cout << "Squre area - " << sizeA * sizeB << std::endl;
	}
};

class Rhombus : public Parallelogram
{
private:
	double sizeA = Null;
	double angle = Null;

public:
	Rhombus(double paramA, double paramB) : Parallelogram(paramA, paramB), sizeA(paramA),
		angle(paramB) {	}

	virtual ~Rhombus()
	{
	//	std::cout << "Rhombus out" << std::endl;
	}

	virtual void area()
	{
		std::cout << "Rhombus area - " << sizeA * sizeA * sin(angle*PI/180) << std::endl;
	}
};

class Circle : public Figure
{
private:
	double radius = Null;

public:
	explicit Circle(double paramA): radius(paramA) { }

	virtual void area()
	{
		std::cout << "Circle area - " << 2 * PI * radius * radius << std::endl;
	}

	virtual ~Circle()
	{
	//	std::cout << "Circle out" << std::endl;
	}
};

int main()
{
	Circle krug(10);
	Rectangle priamougolnic(10, 10);
	Squre kvadrat(5, 5);
	Rhombus romb(5, 60);

	Figure* ptA = &krug;

	krug.area();
	priamougolnic.area();
	kvadrat.area();
	romb.area();

	ptA->area();

	return 0;
}