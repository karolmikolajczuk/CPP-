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


char* MultiplyingBigNumbers(unsigned long* number1, unsigned long* number2) {

}

int main() {
	std::size_t f1 = 1;
	unsigned long f2 = 1;
	
	for (int ind=2; ind <= 500; ind++) {
		f1*=ind;
		f2*=ind;
	}

	return 0;
}
