#include <iostream>

int main() {
	int statuesIn;
	int printers = 1;
	int days = 0;

	std::cin >> statuesIn;

	while(printers < statuesIn) {
		printers = printers * 2;
		days += 1;
	}

	days += 1;
	std::cout << days << std::endl;
}