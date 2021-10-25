#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cctype>
#include <iterator>
#include <locale.h>
#include "Timer.h"

// Part 1
template <typename T>
void Swap(T* first, T* second) {
	T temp = *first;
	*first = *second;
	*second = temp;
}

// Part 2
template <typename T>
void SwapPointers(std::vector<T*> &point) {
	std::sort(point.begin(), point.end(),
		[](const T* lvalue, const T* rvalue) {return *lvalue < *rvalue;});
}

// Part 3

void VowelsSearch() {
	
	const size_t vowelLimeSize = 20;
	std::string line;
	std::string vowelLine = "àóîûèýÿþ¸åÀÓÎÛÈÝßÞ¨Å";
	uint32_t sum1 = 0;
	uint32_t sum2 = 0;
	uint32_t sum3 = 0;
	uint32_t sum4 = 0;

	std::ifstream in("Peace and war.txt");
	if (in.is_open()) {
		while (getline(in,line))
		{
			Timer timer1("Count + find");
			sum1 += std::count_if(line.begin(), line.end(),
				[&vowelLine](const char element) 
				{
					return (vowelLine.find(element) != std::string::npos);
				});
			timer1.print();
			Timer timer2("Count + for");
			for (auto c : vowelLine) {
				sum2 += std::count_if(line.begin(),line.end(), 
					[&c](const char f) {
						return (c == f);
					});
			}
			timer2.print();
			Timer timer3("for + find");
			for (auto  c2: line) {
				if (vowelLine.find(c2) != std::string::npos) {
					++sum3;
				}
					
			}
			timer3.print();
			Timer timer4("for + for");
			for (auto c3 : line) {
				for (auto c4 : vowelLine) {
					if (c3 == c4) {
						++sum4;
					}
				}
			}
			timer4.print();
		}
	}
	in.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	VowelsSearch();
	return 0;
}