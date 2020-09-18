/*
	Rat in a Maze Problem
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int answer;

void getCheese (int n, vector<vector<int>> matrix, int i, int j) {
	// found the cheese!
	if (i == n-1 && j == n-1) {
		answer++;
		return;
	}
	matrix[i][j] = 1; // visited, closes path

	if (i-1 >= 0 && matrix[i-1][j] != 1) {
		getCheese (n, matrix, i-1, j);
	}

	if (j-1 >= 0 && matrix[i][j-1] != 1) {
		getCheese (n, matrix, i, j-1);	
	}

	if (i+1 < n && matrix[i+1][j] != 1){
		getCheese (n, matrix, i+1, j);
	}

	if (j+1 < n && matrix[i][j+1] != 1){
		getCheese (n, matrix, i, j+1);
	}	
	matrix[i][j] = 0;
}


int main (void) {

	int n;
	cin >> n;
	vector<vector<int>> matrix (n, vector<int>(n));

	// reads the maze
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	answer = 0;
	
	getCheese (n, matrix, 0, 0);
	cout << answer << endl;

	return 0;
}