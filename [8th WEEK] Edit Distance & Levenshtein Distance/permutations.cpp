/*
	Permutations of Arrays 
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

// global variables
vector<int> original;
vector<int> target;
int num;

int solvePermutation () {

	int DP[num+1][num+1];

	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= num; j++) {
			if (i == 0) DP[i][j] = j;
			else if (j == 0) DP[i][j] = i;
			else if (original[i-1] == target[j-1]) DP[i][j] = DP[i-1][j-1];
			else DP[i][j] = 1 + min(DP[i][j - 1], DP[i - 1][j]); 
		}
	}
	
	return DP[num][num];
}

int main (void) {

	int tests; cin >> tests;

	for (int j = 0; j < tests; j++) {
		cin >> num;

		// reading inputs
		for (int i = 0; i < num; i++) {
			int aux = 0; cin >> aux;
			original.push_back(aux);
		}
		for (int i = 0; i < num; i++) {
			int aux = 0; cin >> aux;
			target.push_back(aux);
		}

		cout << "Case "<< j+1 << ": " << solvePermutation () << endl;
		original.clear();
		target.clear();
	}

	return 0;
}