#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <math.h>

void Answer(std::string str)
{
	std::cout << "Okay, let's do " << str << "!\n";
}

bool AddOrSubtract(bool adding)
{
	int num1 = 0;
	int num2 = 0;

	std::cout << "What is the first number? ";
	std::cin >> num1;
	if (std::cin.fail())
	{
		return 0;
	}

	std::cout << "What is the second number? ";
	std::cin >> num2;
	if (std::cin.fail())
	{
		return 0;
	}

	if (adding)
	{
		std::cout << num1 << " + " << num2 << " = " << num1 + num2;
	}
	else
	{
		std::cout << num1 << " - " << num2 << " = " << num1 - num2;
	}

	return 1;
}

bool MultiplyOrDivide(bool multiplying)
{
	int num1 = 0;
	int num2 = 0;

	std::cout << "What is the first number? ";
	std::cin >> num1;
	if (std::cin.fail())
	{
		return 0;
	}

	std::cout << "What is the second number ? ";
	std::cin >> num2;
	if (std::cin.fail())
	{
		return 0;
	}

	if (multiplying) std::cout << num1 << " * " << num2 << " = " << num1 * num2;
	else  std::cout << num1 << " / " << num2 << " = " << num1 / num2;

	return 1;
}

bool AngleConversion(bool degrees)
{
	float num = 0;

	std::cout << "What value would you like to convert? ";
	std::cin >> num;
	if (std::cin.fail()) return 0;

	if (degrees) std::cout << num << " degrees equals " << num * M_PI / 180 << " radians";
	else std::cout << num << " radians equals " << num * 180 / M_PI << " degrees";

	return 1;
}

bool TemperatureConversion(bool celsius)
{
	float num = 0;

	std::cout << "What temperature would you like to convert? ";
	std::cin >> num;
	if (std::cin.fail()) return 0;

	if (celsius) std::cout << num << " degrees celsius equals " << (num * 9 / 5) + 32 << " degrees fahrenheit";
	else std::cout << num << " degrees fahrenheit equals " << (num - 32) * 5 / 9 << " degrees celsius";

	return 1;
}

void AskForOperation()
{
operation:
	std::string str;

	std::cout << "What operation would you like to use?\n1. addition \n2. subtraction \n3. multiplication \n4. division \n5. degrees to radians\n6. radians to degrees \n7. celsius to fahrenheit \n8. fahrenheit to celsius \n";

	std::cin >> str;

	if (str.compare("1") == 0)
	{
	add:
		Answer("addition");
		bool usedInts = AddOrSubtract(true);

		if (!usedInts)
		{
			std::cout << "Uhm, that's not a number...\n";
			std::cin.clear();
			std::cin.ignore(1);
			goto add;
		}
	}
	else if (str.compare("2") == 0)
	{
	subtract:
		Answer("subtraction");
		bool usedInts = AddOrSubtract(false);

		if (!usedInts)
		{
			std::cout << "Uhm, that's not a number...\n";
			std::cin.clear();
			std::cin.ignore(1);
			goto subtract;
		}
	}
	else if (str.compare("3") == 0)
	{
	multiply:
		Answer("multiplication");
		bool usedInts = MultiplyOrDivide(true);
		
		if (!usedInts)
		{
			std::cout << "Uhm, that's not a number...\n";
			std::cin.clear();
			std::cin.ignore(1);
			goto multiply;
		}
	}
	else if (str.compare("4") == 0)
	{
	divide:
		Answer("division");
		bool usedInts = MultiplyOrDivide(false);

		if (!usedInts)
		{
			std::cout << "Uhm, that's not a number...\n";
			std::cin.clear();
			std::cin.ignore(1);
			goto divide;
		}
	}
	else if (str.compare("5") == 0)
	{
	degtorad:
		Answer("degrees to radians");
		bool usedFloats = AngleConversion(true);

		if (!usedFloats)
		{
			std::cout << "Uhm, that's not a number...\n";
			std::cin.clear();
			std::cin.ignore(1);
			goto degtorad;
		}
	}
	else if (str.compare("6") == 0)
	{
	radtodeg:
		Answer("radians to degrees");
		bool usedFloats = AngleConversion(false);

		if (!usedFloats)
		{
			std::cout << "Uhm, that's not a number...\n";
			std::cin.clear();
			std::cin.ignore(1);
			goto radtodeg;
		}
	}
	else if (str.compare("7") == 0)
	{
	celtofah:
		Answer("celsius to fahrenheit");
		bool usedFloats = TemperatureConversion(true);

		if (!usedFloats)
		{
			std::cout << "Uhm, that's not a number...\n";
			std::cin.clear();
			std::cin.ignore(1);
			goto celtofah;
		}
	}
	else if (str.compare("8") == 0)
	{
	fahtocel:
		Answer("fahrenheit to celsius");
		bool usedFloats = TemperatureConversion(false);

		if (!usedFloats)
		{
			std::cout << "Uhm, that's not a number...\n";
			std::cin.clear();
			std::cin.ignore(1);
			goto fahtocel;
		}
	}
	else
	{
		std::cout << "That is not an option!\n";
		goto operation;
	}
}

int main()
{
	bool run = true;
	while (run)
	{
		AskForOperation();

	rerun:
		std::string str;

		std::cout << "\nWould you like to do another operation? yes no ";
		std::cin >> str;

		if (str.compare("yes") == 0) run = true;
		else if (str.compare("no") == 0) run = false;
		else
		{
			std::cout << "That is not an option!";
			goto rerun;
		}
	}

	return 0;
}