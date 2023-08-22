#include <iostream>

int main()
{
	char information[10];

	std::cout << "Hi there! What is your name?";
	std::cin.getline(information, 10);
	std::cout << information;
}