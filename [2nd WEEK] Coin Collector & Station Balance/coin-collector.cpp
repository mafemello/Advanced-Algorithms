/*
	Coin Collector Problem
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

// greedy approach ==> O(n)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void coinCollector (vector<int> coins, int num_coins) {

	int sum = coins[0]; // sum initializes with first coin
	int counter = 1; 

	// trying to take the smaller value
	for (int i = 1; i < num_coins-1; i++) {
		if (coins[i] + sum < coins[i+1]) { // you can get that coin!
			sum += coins[i];
			counter++; 
		}
	}
	cout << counter+1 << endl;
	return;
}

int main (void) {

	int test = 0;
	int num_coins = 0;
	int item;
	cin >> test; 

	// reading data
	while (test > 0) {
		vector<int>coins;	
		cin >> num_coins; // how many different coins
		for (int i = 0; i < num_coins; i++) {
			cin >> item;
			coins.push_back(item); // inserts data into the vector
		}		
		coinCollector (coins, num_coins);
		test--;
	}
	
	return 0;
}
