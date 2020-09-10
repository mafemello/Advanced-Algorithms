/*
	Station Balance Problem
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void IMBALANCE (vector<int>masses, int num_species, int num_chambers, int set, int sum) {
	
	double imbalance = 0;
	double am = sum/num_chambers; 

	// resizes the vector so it can have its maximum size (twice as the num_chambers)
	masses.resize(2*num_chambers); 
	// sorts the masses to make the problem easier
	sort (masses.begin(), masses.end()); 


	// after sorting, the best option is to take the first and the last species togheter in one chamber
	printf("Set #%d\n", set);
		for( int i = 0; i < num_chambers; i++) {
			printf( " %d:", i);
			if (masses[i] != 0) // so it doesn't print the 0s
				printf( " %d", masses[i]); // first
			if (masses[2*num_chambers-i-1] != 0) {// so it doesn't print the 0s
				printf( " %d\n", masses[2*num_chambers-i-1] ); // last
			} else {
				printf(" \n");
			}
			imbalance += abs(am - (masses[i] + masses[2 *num_chambers - i - 1])); // imbalance!
		}
		printf( "IMBALANCE = %.5lf\n\n", imbalance );
}



int main (void) {

	int num_chambers, num_species;
	double mass; // each species mass
	int set = 1;

	while (cin >> num_chambers) { 
		cin >> num_species;
		vector<int>masses;

		int sum = 0; // sum of the masses
		for (int i = 0; i < num_species; i++) {
			cin >> mass;
			masses.push_back(mass);
			sum += mass;
		}
		IMBALANCE (masses, num_species, num_chambers, set, sum);
		set++;
	}
	return 0;
}