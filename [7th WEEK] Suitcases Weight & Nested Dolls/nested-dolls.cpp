/*
	Russian Dolls
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <queue>
#include <set>
using namespace std;

// comparing function to sort the vector of pairs
bool compare (pair<int,int> &a, pair<int,int> &b) {
	if(a.first == b.first) 
		return a.second > b.second;
	return a.first < b.first;
}

// main function
void matryoshka (int dolls, vector<pair<int,int>> medidas) {
	
	sort (medidas.begin(), medidas.end(), compare);

	deque<int> seq;
	
	for (int i = 0; i < dolls; i++) {
		int indice = lower_bound (seq.begin(), seq.end(), medidas[i].second) - seq.begin();
		if (indice == 0) seq.push_front (medidas[i].second);
		else seq[indice-1] = medidas[i].second;
	}

    cout << seq.size() << endl;
}

int main (void) {

	int tests = 0; cin >> tests;

	// test cases
	while (tests--) {
		int dolls = 0; cin >> dolls;
		vector<pair<int,int>> medidas;
		set <int> esq;
		int widht, height;
		
		for (int i = 0; i < dolls; i++) {
			esq.insert(i);
			cin >> widht; cin >> height;
			medidas.push_back ({widht, height});
		}
		matryoshka (dolls, medidas);
	}
	return 0;
}