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
	for(int i=0; i<=19; i++) std::cout << (int)number[i];
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
	char* multiply = new char[128] {0};
	int index_of_multiply = 127;
	
	std::cout << "Parsed" << std::endl;

	std::cout << (*number1) << " " << (*number2) << std::endl;
	char* number_1 = ParseNumber(number1);
	char* number_2 = ParseNumber(number2);
	
	std::cout << "Printing" << std::endl;

	PrintNumber(number_1);
	PrintNumber(number_2);
	
	// multiplying 

	// multiply index 19 with index 19, 
	// multiply index 19 with index 18
	// ..
	// ..
	// ..
	// multiply index 19 with index 0
	// multiply index 18 with index 19
	// ..
	// ..
	// ..
	// sum the results
	//
	// dont forget to add 0 on the beginnig of multiplying
	// lower indexes
	//
	

	// matrix of sums 19 rows and 361 columns
	char sums_to_add[19][361];
	
	int indexes_of_sums = 360;
	int index_of_last_row = 360;

	for(int i=19; i>=0; i--) {
		int add_to_up_next_index = 0;
		
		for(int j=19; j>=0; j--) {
			int down_1 = (int)number2[i], 
			    up_1 = (int)number1[j];

			int result = down_1*up_1;
			// set 
			sums_to_add[i][indexes_of_sums]=result%10+add_to_up_next_index;
					
			add_to_up_next_index = result/10;
		}
	}	
	
	return multiply;
}

int main() {

	unsigned long a = 1082518925;
	unsigned long b = 1085151252;
	std::cout << a << " oraz " << b << std::endl;
	MultiplyingBigNumbers(&a, &b);

	return 0;
}
