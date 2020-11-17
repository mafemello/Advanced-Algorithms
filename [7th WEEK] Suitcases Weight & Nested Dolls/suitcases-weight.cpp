/*
	Suitcases Weight
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <cstring>
using namespace std;

// function based on the knapsack algorithm 
int Suitcases_Weight (int max_weight, int count, int Weight[]) {
	int matrix [count+1][max_weight+1];

	for (int i = 0; i <= count; i++) {
		for (int j = 0; j <= max_weight; j++) {
			if (i == 0 || j == 0) matrix[i][j] = 0;
			else if (Weight[i-1] <= j) {
				int bigger = 0;
				if (Weight[i-1] + matrix[i-1][j-Weight[i-1]] > matrix[i-1][j]) bigger = Weight[i-1] + matrix[i-1][j-Weight[i-1]];
				else bigger = matrix[i-1][j];
				matrix[i][j] = bigger;
			}
			else matrix[i][j] = matrix[i-1][j];
		}
	}
	return matrix[count][max_weight];
}

int main (void) {

	int tests = 0; cin >> tests;
	getchar();

	while (tests--) {
		int Weight[21];
		int sum = 0, count = 0;
		char aux;

		// reading inputs
		while (scanf("%d%c", &Weight[count], &aux)) {
			sum += Weight[count];
			count++;
			if (aux == '\n') break;
		}
		
		// knapsack algorithm 
		if(sum%2 == 1) cout<<"NO"<<endl;
        else if (Suitcases_Weight(sum/2, count, Weight) == sum/2) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
		
	}
	return 0;
}