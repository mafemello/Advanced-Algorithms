/*
	Levenshtein Distance
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
string a, b;

int min(int x, int y, int z) { 
	return min(min(x, y), z); 
}
 
int levenshteinDistance(int m, int n) {
 

	int DP[m+1][n+1] = {0};

	for (int i = n-1; i > -1; i--) 
		DP[m][i] = DP[m][i+1] + b[i]-'a'+1;

	for (int i = m-1; i > -1; i--)
		DP[i][n] = DP[i+1][n] + a[i]-'a'+1;

	for (int i = n-1; i > -1; i--) {
		for (int j = m-1; j > -1; j--) {
			DP[j][i] = min(DP[j][i+1] + b[i]-'a'+1, DP[j+1][i] + a[j] -'a'+1, abs(a[j]-b[i]) + DP[j+1][i+1]);
		}
	}

    return DP[0][0];    
}

int main (void) {
	
	cin >> a;
	cin >> b;

	cout << levenshteinDistance(a.size(), b.size()) << endl;

	return 0;
}