//Thomas Salemy
//Project Euler Solutions
//Problem 23: Non-abundant sums
//Question: Find the sum of all the positive integers 
//which cannot be written as the sum of two abundant numbers

#include <iostream>
#include <time.h>
using namespace std;

int main() {
    clock_t time = clock();

    int bound = 28123 / 2 + 1;
    int *factorSumMap = new int[28124]();

    for (int i = 1; i < bound; i++) {
	    for (int j = i * 2; j < 28124; j += i) {
		    factorSumMap[j] += i;
	    }
    }

    int sum = 0;
    bool *abundantMap = new bool[28124]();
    for (int i = 4; i < 28124; i++) {
	    if (factorSumMap[i] > i && i < bound) {
		    abundantMap[i * 2] = true;
		    for (int j = i + 1; j < 28124; j++) {
			    if (factorSumMap[j] > j && i + j < 28124) {
				    abundantMap[i + j] = true;
			    }
		    }
	    }
    }

    for (int i = 0; i < 28124; i++) {
	    if (!abundantMap[i]) {
		    sum += i;
	    }
    }

    cout << "Answer: " << sum << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

    delete [] factorSumMap;
    delete [] abundantMap;
};
