#include <iostream>

class Card
{
private:
	enum class Suit {
		Hearts,   //черви
		Diamonds, //бубны
		Clubs, //крести
		Spades //пики
	};
	enum class Number {
		Ace,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Joker
	};
	bool face = true; // Истина - рубашка, ложь - лицом вверх
	Suit cardSuit;
	Number cardNumber;
public:
	
	Card(Suit num1, Number num2, bool num3) : cardSuit(num1), cardNumber(num2), face(num3) {

	}

	bool Flip()
	{
		if (face)
		{
			face = false;
			return face;
		}
		else {
			face = true;
			return face;
		}
	}
	Number getValue() const {
		return cardNumber;
	}
};