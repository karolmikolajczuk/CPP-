#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <string>

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
	std::cout << "Printing a number: ";
	bool flag = true;
	for(int i=0; i<=19; i++) {
		if((int)number[i]!=0) flag = false;
		if(flag && (int)number[i]==0)continue;
		if(flag && i==19) std::cout << 0;
		else std::cout << (int)number[i];
	}
	std::cout << '\n';
}

char* ParseNumber(unsigned long* number) {
	char* parsed_number = new char[20] {0};
	short index = 19;
	while((*number)>0) {
		parsed_number[index] = (*number)%10;
		(*number)/=10;
		index--;
	}
	return parsed_number;
}

char* MultiplyingBigNumbers(unsigned long* number1, unsigned long* number2) {
	char* number_1 = ParseNumber(number1);
	char* number_2 = ParseNumber(number2);

	PrintNumber(number_1);
	PrintNumber(number_2);
	
	char sums_to_add[20][361] {0};

	int indexes_of_sums = 360;
	int index_of_last_row = 360;

	for(int i=19; i>=0; i--) {
		int divider = (int)number_2[i];
		int number_from_before = 0;

		for(int j=19; j>=0; j--) {
			int result = divider * (int)number_1[j];
			sums_to_add[-i+19][indexes_of_sums]=result%10+number_from_before;	
			number_from_before = result/10;

			indexes_of_sums--;
		}

		index_of_last_row--;
		indexes_of_sums = index_of_last_row;
	}	
	
	char* multiply = new char[361] {0};
	
	int add_to_next_column = 0;
	for(int i=360; i>=0; i--) {
		int sum_of_column = 0;
		for(int j=19; j>=0; j--	) {
			sum_of_column += (int)sums_to_add[j][i];
		}
		multiply[i]=sum_of_column%10 + add_to_next_column;
		add_to_next_column = sum_of_column/10;
	}
	return multiply;
}

void PrintResult(char* result) {
	std::cout << "Result:" << std::endl;
	bool dropZero = true;
	for(int i=0; i<=360; i++) {
		if((int)result[i] != 0) dropZero = false;
		if(dropZero) continue;
		if(dropZero && i==360) std::cout << 0;
		else std::cout<<(int)result[i];
	}
}

int main(int argc, char **argv) {
	
	if (argc != 3) {
		std::cerr << "2 arguments";
	}
	
	std::string str_a = std::string(argv[1]);
	std::string str_b = std::string(argv[2]);
	unsigned long a = std::strtoul(str_a.c_str(), NULL, 0);
	unsigned long b = std::strtoul(str_b.c_str(), NULL, 0);

	std::cout << a << " oraz " << b << std::endl;
	
	PrintResult(MultiplyingBigNumbers(&a, &b));

	return 0;
}
