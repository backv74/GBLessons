#include <iostream>
#include <vector>

class Hand {
private:
	vector<Card*> m_Cards;
public:
	
	void AddCard(Card* pCard)
	{
		m_Cards.push_back(pCard);
	}

	void Clear() {

	}

	void GetValue() {

	}
};