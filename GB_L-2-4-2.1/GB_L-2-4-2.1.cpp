#include <iostream>
#include <vector>
#include <set>
int main()
{
	std::vector<int> array = {1,2,2,3,4,5,5,6,7,7,7};
	std::set<int> array1;

	for (int i = 0; i < array.size();i++) {
		std::cout << array[i] << " ";
		array1.insert(array[i]);
	}
	
	std::cout << std::endl << array1.size();

	return 0;
}