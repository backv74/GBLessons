/****************/
#include <iostream>
#include <cmath>

class Power
{
private:
    double one, two;
public:
    
    Power() {}
    ~Power() {}

    void setNum(double oneS, double twoS)
    {
        one = oneS;
        two = twoS;
    }

    double calculate()
    {
        return pow(one, two);
    }
};

int main()
{
    Power superMan;
    const double A = 2.4;
    const double B = 3.0;

    superMan.setNum(2.4, 2.5);
    std::cout << "Number = " << superMan.calculate();
}