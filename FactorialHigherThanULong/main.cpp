#include <iostream>
#include <cstdio>
#include <climits>

/**
 *
 * interpretowanie liczby jako tablica znakow(bo malo zajmuje) 
 * gdzie dokonujemy mnozenia pisemnego
 *
 * 	1 8 2
 *    *   2 3
 *    _________
 *    	5 4 6
 *    3	6 4 0
 *    _________
 *    4 1 8 6
 */

void PrintNumber(char* number) {
	for(int i=0; i<=19; i++) std::cout << number[i];
	std::cout << '\n';
}

char* ParseNumber(unsigned long* number) {
	char* parsed_number = new char[20] {0};
	short index = 19;
	while((*number)>0) {
		std::cout << "Liczba: " << (*number)%10 << std::endl;
		parsed_number[index] = (*number)%10;
		(*number)/=10;
		index--;
		std::cout << "Index: " << index << " Parse: " << (int)parsed_number[index+1] << std::endl;
	}
	return parsed_number;
}

char* MultiplyingBigNumbers(unsigned long* number1, unsigned long* number2) {
	char* multiply = new char[128] {0};
	
	std::cout << "Parsed" << std::endl;

	std::cout << (*number1) << " " << (*number2) << std::endl;
	char* number_1 = ParseNumber(number1);
	char* number_2 = ParseNumber(number2);
	
	std::cout << "Printing" << std::endl;

	PrintNumber(number_1);
	PrintNumber(number_2);
		
	
	return multiply;
}

int main() {

	unsigned long a = 1082518925;
	unsigned long b = 1085151252;
	std::cout << a << " oraz " << b << std::endl;
	MultiplyingBigNumbers(&a, &b);

	return 0;
}
