#include <iostream>
#include <vector>

const int FieldSize = 10;

enum MoveDirection {
	Right = 0,
	Left = 1,
	Up = 2,
	Down = 3
};

class OffTheField {
private:
	int m_corX;
	int m_corY;
	std::string m_direct;
public:
	OffTheField(int corX, int corY, std::string direct)
		:m_corX(corX), m_corY(corY), m_direct(direct){}

	void getError() {
		std::cout << "Going beyond the border " << "X =" << m_corX << ", " << "Y = " << m_corY
			<< "; " << " Direction = " << m_direct << std::endl;
	}	
};

class IllegalCommand {
private:
	int m_corX;
	int m_corY;
	std::string m_direct;
public:
	IllegalCommand(int corX, int corY, std::string direct)
		: m_corX(corX), m_corY(corY), m_direct(direct) {}

	void getError() {
		std::cout << "Wrong direction of travel " << "X =" << m_corX << ", " << "Y = " << m_corY
			<< "; " << " Direction = " << m_direct << std::endl;
	}
};

class Robot {
private:
	int m_coordinateX;
	int m_coordinateY;
	std::vector<std::vector<char>> field{ FieldSize, std::vector<char>(FieldSize) };
	MoveDirection toGo = Left;
public:
	
	Robot(int x = 0, int y = 0):m_coordinateX(x), m_coordinateY(y) {} 

	void creatField() {
		for (size_t i = 0; i < FieldSize; i++) {
			for (size_t j = 0; j < FieldSize; j++) {
				field[i][j] = '.';
			}
		}
		field[m_coordinateX][m_coordinateY] = 'X';
	}

	void drawField() {
		std::cout << std::endl << std::endl;
		for (size_t i = 0; i < FieldSize; i++) {
			std::cout << "\t\t";
			for (size_t j = 0; j < FieldSize; j++) {
				std::cout <<  field[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	
	void setDirection(const char& direct) {
		if (direct == 'r' || direct == 'R') {
			toGo = Right;
		}
		else {
			if (direct == 'l' || direct == 'L') {
				toGo = Left;
			}
			else {
				if (direct == 'U' || direct == 'u') {
					toGo = Up;
				}
				else {
					if (direct == 'D' || direct == 'd') {
						toGo = Down;
					}
				}
			}
		}
	}

	void moveRight(MoveDirection direct) {
		if (direct != toGo) {
			throw IllegalCommand(m_coordinateX, m_coordinateY, "Right");
		}
		else {
			if (m_coordinateY - 1 < 0) {
				throw OffTheField(m_coordinateX, m_coordinateY, "Right");
			}
			else {
				field[m_coordinateX][m_coordinateY] = '.';
				m_coordinateY -= 1;
				field[m_coordinateX][m_coordinateY] = 'X';
			}
		}
		
	}
	const char* DirectToString(MoveDirection direct) {
		if (direct == 'r' || direct == 'R') {
			return  "Right";
		}
		else {
			if (direct == 'l' || direct == 'L') {
				return "Left";
			}
			else {
				if (direct == 'U' || direct == 'u') {
					return "Up";
				}
				else {
					if (direct == 'D' || direct == 'd') {
						return "Down";
					}
				}
			}
		}
	}
	void moveLeft(MoveDirection direct) {
		if (direct != toGo) {
			throw IllegalCommand(m_coordinateX, m_coordinateY, DirectToString(toGo));
		}
		else {
			if (m_coordinateY + 1 == 10) {
				throw OffTheField(m_coordinateX, m_coordinateY, DirectToString(toGo));
			}
			else {
				field[m_coordinateX][m_coordinateY] = '.';
				m_coordinateY += 1;
				field[m_coordinateX][m_coordinateY] = 'X';
			}
		}
	}

	void moveUp(MoveDirection direct) {
		if (direct != toGo) {
			throw IllegalCommand(m_coordinateX, m_coordinateY, DirectToString(toGo));
		}
		else {
			if (m_coordinateX - 1 < 0) {
				throw OffTheField(m_coordinateX, m_coordinateY, DirectToString(toGo));
			}
			else {
				field[m_coordinateX][m_coordinateY] = '.';
				m_coordinateX -= 1;
				field[m_coordinateX][m_coordinateY] = 'X';
			}
		}
	}

	void moveDown(MoveDirection direct) {
		if (direct != toGo) {
			throw IllegalCommand(m_coordinateX, m_coordinateY, DirectToString(toGo));
		}
		else {
			if (m_coordinateX + 1 == 10) {
				throw OffTheField(m_coordinateX, m_coordinateY, DirectToString(toGo));
			}
			else {
				field[m_coordinateX][m_coordinateY] = '.';
				m_coordinateX += 1;
				field[m_coordinateX][m_coordinateY] = 'X';
			}
		}
	}
};

char DirectFunc(const std::string& st) {
	char m_direct;
	while (true) {
		std::cout << std::endl << st;
		std::cin >> m_direct;
		if (m_direct == 'L' || m_direct == 'l' || m_direct == 'R' || m_direct == 'r'
			|| m_direct == 'U' || m_direct == 'u' || m_direct == 'D' || m_direct == 'd') {
			break;
		}
		else {
			std::cout << "Error! Wrong input direct!";
		}
	}
	return m_direct;
}

int main() {
	Robot ro;
	bool flag = true;
	ro.creatField();
	char direct;
	char stop;
	ro.drawField();
	while (flag) {
		try
		{
			direct = DirectFunc("Input move direction (L/R/U/D): ");
			ro.setDirection(direct);
			direct =  DirectFunc("Input move command (L/R/U/D): ");
			if (direct == 'r' || direct == 'R') {
				ro.moveRight(Right);
			}
			else {
				if (direct == 'l' || direct == 'L') {
					ro.moveLeft(Left);
				}
				else {
					if (direct == 'U' || direct == 'u') {
						ro.moveUp(Up);
					}
					else {
						if (direct == 'D' || direct == 'd') {
							ro.moveDown(Down);
						}
					}
				}
			}
			system("cls");
			ro.drawField();
			std::cout << "Press F to stop: ";
			std::cin >> stop;
			if (stop == 'F') { break; }
		}
		catch (IllegalCommand& exception)
		{
			exception.getError();
		}
		catch (OffTheField& exception) {
			exception.getError();
		}
	}
	return 0;
}