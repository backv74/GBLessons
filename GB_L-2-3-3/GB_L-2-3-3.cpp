#include <iostream>

class Fraction
{
private:
    int16_t numerator;
    int16_t denominator;
public:
    Fraction() {
        setNumerator(0);
        setDenominator(1);
    }

    Fraction(int16_t num, int16_t denom) {
        setNumerator(num);
        setDenominator(denom);

    }
   
    Fraction(const Fraction& other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    void setNumerator(int16_t num) {
        numerator = num;
    }

    void setDenominator(int16_t denom) {
        if (denom != 0) {
            denominator = denom;
        }
        else { denominator = 1; }
    }

    int16_t getNumerator() const {
        return numerator;
    }

    int16_t getDenominator() const {
        return denominator;
    }

    int16_t gcf(int16_t num1, int16_t num2) {
        if (num2 == 0) {
            return abs(num1);
        }
        else { return gcf(num2, num1 % num2); }
    }

    int16_t lcm(int16_t num1, int16_t num2) {
        int16_t n = gcf(num1, num2);
        return num1 / n * num2;
    }

    Fraction add(const Fraction& other) {
        int16_t lcd = lcm(denominator, other.denominator);
        int16_t sDenam1 = lcd / denominator;
        int16_t sDenam2 = lcd / other.denominator;
        return Fraction(numerator * sDenam1 + other.numerator * sDenam2, lcd);
    }

    Fraction operator+(const Fraction& other) {
        return add(other);
    }

    Fraction sub(const Fraction& other) {
        int16_t lcd = lcm(denominator, other.denominator);
        int16_t sDenam1 = lcd / denominator;
        int16_t sDenam2 = lcd / other.denominator;
        return Fraction(numerator * sDenam1 - other.numerator * sDenam2, lcd);
    }

    Fraction operator-(const Fraction& other) {
        return sub(other);
    }

    Fraction operator*(const Fraction& other) {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction operator-() {
        return Fraction(-numerator, denominator);
    }

    bool operator==(const Fraction& other) {
        return (numerator == other.numerator && denominator == other.denominator);
    }

    bool operator!=(const Fraction& other) {
        return (numerator != other.numerator || denominator != other.denominator);
    }

    bool operator>(const Fraction& other) {
        return !((numerator * other.denominator) <= (denominator * other.numerator));
    }

    bool operator<(const Fraction& other) {
        return !((numerator * other.denominator) >= (denominator * other.numerator));
    }

    bool operator>=(const Fraction& other) {
        return !((numerator * other.denominator) < (denominator * other.numerator));
    }

    bool operator<=(const Fraction& other) {
        return !((numerator * other.denominator) > (denominator * other.numerator));
    }
};

int main()
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 - f2;
    std::cout << "f1 = " << f1.getNumerator() << " / " << f1.getDenominator() << std::endl;
    std::cout << "f2 = " << f2.getNumerator() << " / " << f2.getDenominator() << std::endl;
    std::cout << "f1-f2 = " << f3.getNumerator() << " / " << f3.getDenominator() << std::endl;
    f3 = f1 + f2;
    std::cout << "f1+f2 = " << f3.getNumerator() << " / " << f3.getDenominator() << std::endl;
    f3 = f1 * f2;
    std::cout << "f1*f2 = " << f3.getNumerator() << " / " << f3.getDenominator() << std::endl;
    f3 = f1 / f2;
    std::cout << "f1/f2 = " << f3.getNumerator() << " / " << f3.getDenominator() << std::endl;
    
    std::cout << "f1 > f2 = " << (f1 > f2) << std::endl;
    std::cout << "f1 < f2 = " << (f1 < f2) << std::endl;
    std::cout << "f1 == f2 = " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2 = " << (f1 != f2) << std::endl;
    std::cout << "f1 >= f2 = " << (f1 >= f2) << std::endl;
    std::cout << "f1 <= f2 = " << (f1 <= f2) << std::endl;
    return 0;
}
