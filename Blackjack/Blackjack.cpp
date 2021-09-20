#include <iostream>
#include <vector>
#include <algorithm>

const int SumTotal = 11;
const int Ace11 = 10;
const int Total21 = 21;
const int DillerSum16 = 16;
const int DeckSize = 52;
const int StartCards = 2;
const int MAX_Players = 7;

class Card
{
protected:
	bool m_face = true;
public:
	enum Suit {
		Hearts,
		Diamonds,
		Clubs,
		Spades
	};

	enum Number {
		Ace = 1,
		Two = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Ten = 10,
		Jack = 10,
		Queen = 10,
		King = 10,
		Joker = 10
	};
	Number m_cardNumber;
	Suit m_cardSuit;

	friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

	Card(Number num1, Suit num2, bool num3) : m_cardSuit(num2), m_cardNumber(num1), m_face(num3) {

	}

	void Flip()
	{
		if (m_face) {
			m_face = false;
		}
		else {
			m_face = true;
		}
	}

	int getValue() const {
		int count = 0;
		count = m_cardNumber;
		return count;
	}
};

std::ostream& operator<<(std::ostream& os, const Card& aCard) {
	const std::string RANKS[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J","Q", "K", "Jok" };
	const std::string SUITS[] = { "H", "D", "C", "S" };
	if (aCard.m_face) {
		os << RANKS[aCard.m_cardNumber] << " " << SUITS[aCard.m_cardSuit];
	}
	else {
		os << "XX";
	}
	return os;
}

class Hand {
protected:
	std::vector<Card*> m_Cards;
public:

	void AddCard(Card* pCard) {
		m_Cards.push_back(pCard);
	}

	void Clear() {
		for (auto iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
			delete* iter;
			*iter = 0;
		}
		m_Cards.clear();
	}

	int GetValue() const {
		int count = 0;
		bool aceFlag = false;

		if (m_Cards.empty() == 0) { return 0; }

		for (auto iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
			if ((*iter)->getValue() == Card::Number::Ace)
			{
				aceFlag = true;
			}
			count += (*iter)->getValue();
		}

		if (aceFlag && count <= SumTotal) {
			count += Ace11;
		}

		return count;
	}

	virtual ~Hand() {
		Clear();
	}
};

class GenericPlayer : public Hand {
protected:
	std::string m_name;
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aPlayer);
public:
	GenericPlayer(const std::string& name) :m_name(name) {}

	virtual ~GenericPlayer() {}

	virtual bool isHitting() const = 0;

	bool isBoosted() const {
		if (GetValue() > Total21)
		{
			return true;
		}
		else { return false; }
	}
	void Bust() {
		std::cout << "Player " << m_name << " is boosted!" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aPlayer) {
	os << aPlayer.m_name << ": ";
	if (!aPlayer.m_Cards.empty()) {
		for (auto pCard = aPlayer.m_Cards.begin(); pCard != aPlayer.m_Cards.end(); pCard++) {
			os << *(*pCard) << " ";
		}
		if (aPlayer.GetValue() != 0) {
			os << " ( " << aPlayer.GetValue() << " ) ";
		}
	}
	else {
		os << "empty!";
	}
	return os;
}

class Player : public GenericPlayer {
public:
	Player(const std::string& name) :GenericPlayer(name) {}
	virtual ~Player() {}

	virtual bool isHitting() const
	{
		std::string m_answer;
		bool flag = true;
		while (flag)
		{
			std::cout << "Do you need 1 more card? Y/N ";
			std::cin >> m_answer;
			if (m_answer[0] == 'Y' || m_answer[0] == 'y') {
				return true;
				flag = false;
			}
			else {
				if (m_answer[0] == 'N' || m_answer[0] == 'n') {
					return false;
					flag = false;
				}
				else {
					std::cout << "Wrong answer! Enter Y or N" << std::endl;
				}
			}
		}
		return flag;
	}

	void Win() const {
		std::cout << "Player " << m_name << " is win!" << std::endl;
	}

	void Lose() const {
		std::cout << "Player " << m_name << " is lose!" << std::endl;
	}

	void Push() const {
		std::cout << "Player " << m_name << " is draw!" << std::endl;
	}
};

class House : public GenericPlayer {
public:
	House(const std::string& name = "House") :GenericPlayer(name) {}

	virtual ~House() {}

	virtual bool isHitting() const {
		if (GetValue() < DillerSum16) {
			return true;
		}
		else { return false; }
	}
	void FlipFirstCard() {
		if (!(m_Cards.empty())) {
			m_Cards[0]->Flip();
		}
		else {
			std::cout << "No card to flip" << std::endl;
		}
	}
};

class Deck : public Hand {
public:
	Deck() {
		Populate();
	}

	void Populate() {
		Clear();

		for (int i = Card::Hearts; i <= Card::Spades; ++i) {
			for (int j = Card::Ace; j <= Card::Joker; ++j) {
				AddCard(new Card(static_cast<Card::Number>(j), static_cast<Card::Suit>(i), true));
			}
		}
	}

	void Shuffle() {
		std::random_shuffle(m_Cards.begin(), m_Cards.end());
	}

	void Deal(Hand& aHand) {
		if (!m_Cards.empty()) {
			aHand.AddCard(m_Cards.back());
			m_Cards.pop_back();
		}
		else {
			std::cout << "Out of cards!";
		}
	}

	void AdditionalCards(GenericPlayer& aPlayer) {
		std::cout << std::endl;

		while (!(aPlayer.isBoosted()) && aPlayer.isHitting()) {
			Deal(aPlayer);
			std::cout << aPlayer << std::endl;
			if (aPlayer.isBoosted()) {
				aPlayer.Bust();
			}
		}
	}
};

class Game {
private:
	Deck m_Deck;
	House m_House;
	std::vector<Player> m_Players;

public:
	Game(const std::vector<std::string>& names) {
		for (auto pName = names.begin(); pName != names.end(); ++pName) {
			m_Players.push_back(Player(*pName));
		}

		m_Deck.Populate();
		m_Deck.Shuffle();
	}

	void Play() {

		for (int i = 0; i < StartCards; i++) {
			for (auto pPlyers = m_Players.begin(); pPlyers != m_Players.end(); pPlyers++) {
				m_Deck.Deal(*pPlyers);
			}
			m_Deck.Deal(m_House);
		}

		m_House.FlipFirstCard();

		for (auto pPlyers = m_Players.begin(); pPlyers != m_Players.end(); pPlyers++) {
			std::cout << *pPlyers << std::endl;
		}

		std::cout << m_House << std::endl;

		for (auto pPlyers = m_Players.begin(); pPlyers != m_Players.end(); pPlyers++) {
			m_Deck.AdditionalCards(*pPlyers);
		}

		m_House.FlipFirstCard();
		std::cout << std::endl << m_House;
		m_Deck.AdditionalCards(m_House);

		if (m_House.isBoosted()) {
			for (auto pPlyers = m_Players.begin(); pPlyers != m_Players.end(); pPlyers++) {
				if (!(pPlyers->isBoosted())) {
					pPlyers->Win();
				}
			}
		}
		else {
			for (auto pPlyers = m_Players.begin(); pPlyers != m_Players.end(); pPlyers++) {
				if (!(pPlyers->isBoosted())) {
					if (pPlyers->GetValue() > m_House.GetValue()) {
						pPlyers->Win();
					}
					else {
						if (pPlyers->GetValue() < m_House.GetValue()) {
							pPlyers->Lose();
						}
						else {
							pPlyers->Push();
						}
					}
				}
			}
		}
		for (auto pPlyers = m_Players.begin(); pPlyers != m_Players.end(); pPlyers++) {
			pPlyers->Clear();
		}
		m_House.Clear();
	}
};

int main() {

	std::cout << "BlackJack GAME!" << std::endl << std::endl;

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > MAX_Players) {
		std::cout << "Input players number(1-7): ";
		std::cin >> numPlayers;
	}

	std::vector<std::string> plyerNames;
	std::string name;
	for (int i = 0; i < numPlayers; i++) {
		std::cout << "Enter player name: ";
		std::cin >> name;
		plyerNames.push_back(name);
	}

	std::cout << std::endl;

	Game newGame(plyerNames);
	char flag2 = 'y';
	while (flag2 != 'n' && flag2 != 'N') {
		newGame.Play();
		std::cout << std::endl << "New game? (Y/N): ";
		std::cin >> flag2;
	}

	return 0;
}

