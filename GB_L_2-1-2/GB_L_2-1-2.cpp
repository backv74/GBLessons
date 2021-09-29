//**********//
#include <iostream>
#include <cstdint>

class RGBA
{
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
public:

    RGBA() {}

    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        :m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}

    ~RGBA() {}

    void print()
    {
        std::cout << "Red = " << (int)m_red << "\n"
            << "Green = " << (int)m_green << "\n"
            << "Blue = " << (int)m_blue << "\n"
            << "Alpha = " << (int)m_alpha << "\n";
    }
};

int main()
{
    RGBA one;
    RGBA two(3, 3, 3, 3);
    std::cout << "Default \n";
    one.print();
    std::cout << "Init \n";
    two.print();

    return 0;
}