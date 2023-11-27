#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	try
	{
		Array<int> empt_array;
		if (empt_array.size() == 0)
			std::cout << "\t>>empt_array created" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Array<int> numbers(MAX_VAL);
	if (numbers.size() != 0)
		std::cout << "\t>>array  of size " << MAX_VAL << " created" << std::endl;
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "\t>>Writng through the operator[] success" << std::endl;
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	printf("Array/ numbers |Array/ mirror \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d     |", numbers[i]);
		printf("%d\n", mirror[i]);
	}
	std::cout << "\t>>Reading through the operator[] success" << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\t>>Out of bound exception Respected" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	std::cout << "\t>>Writng through the operator[] success after multiple scops" << std::endl;
	delete [] mirror;
	return 0;
}