/*************/ 
#include <iostream>
#include <cstdint>
class Stack
{
private:
    static const size_t ARRAY_SIZE = 10;
    int32_t array[ARRAY_SIZE] = { 0,0,0,0,0,0,0,0,0,0 };
    uint16_t stackSize = 0;

public:
    Stack() {}
    ~Stack() {}
    //Обнуляем стек
    void reset()
    {
        if (stackSize != 0)
        {
            for (size_t i = 0; i < stackSize; i++)
            {
                array[i] = 0;
            }
        }
        stackSize = 0;
    }
    //Добавляем в стек элемент
    bool push(int32_t number)
    {
        if (stackSize <= ARRAY_SIZE)
        {
            stackSize++;
            array[stackSize - 1] = number;
            return true;
        }
        else
        {
            std::cout << "Stack is full! \n";
            return false;
        }

    }
    //Убираем элемент из стека
    void pop()
    {
        if (stackSize > 0)
        {
            array[stackSize - 1] = 0;
            stackSize--;
        }
        else
        {
            std::cout << "Error! Stack already empty! \n";
        }
    }
    //Выводим стек на экран
    void print()
    {
        if (stackSize > 0)
        {
            std::cout << " ( ";
            for (size_t i = 0; i < stackSize; i++)
            {
                std::cout << array[i] << " ";
            }
            std::cout << ")\n";
        }
        else
        {
            std::cout << " ( ) \n";
        }
    }
};