#include <iostream>

int add(int x, int y);

int main() {
	std::cout << "Enter two values to add";
	
	int valueA{};
	int valueB{};

	std::cin >> valueA >> valueB;
	std::cout << add(valueA, valueB);
	
	return 0;
}