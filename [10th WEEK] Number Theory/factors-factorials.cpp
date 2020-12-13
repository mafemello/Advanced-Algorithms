/*
	Factorial Problem
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

#define NUMPRIME 25

//map <int, int> primes;
// since the upper limit for N is 100, then the largest prime that can divide N! is 97
//long p[NUMPRIME] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

// global
int num;
vector<int> primes;
vector<int> factors;


vector<int> sieve () {

	bool prime[num+1];
	vector<int> p;
	memset (prime, true, sizeof(prime));

	int i = 2;
	while (i <= num) {
		if (prime[i]) {
			p.push_back(i);
			for (int j = i*i; j <= num; j+=i) prime[j] = false;
		}
		i++;
	}

	return p;
}

vector<int> FactorsFunc () {
	
	int sz = (int)primes.size();
	vector<int> sol;
	sol.assign(sz, 0);

	int i = num;
	while (i >= 2) {
		int tmp = i;
		for (int j = 0; j < sz && primes[j] <= i; j++) {
			if (tmp % primes[j] == 0) {
				sol[j]++;
				tmp /= primes[j];
				j--;
			}
		}
		i--;
	}

	return sol;
}

int main (void) {

	while (cin >> num) {
		if (num == 0) break;
		primes = sieve();
		factors = FactorsFunc();
		int sz = (int)factors.size();

		printf ("%3d! =", num);
		for (int i = 0; i < sz; i++) {
			if (i > 0 && i % 15 == 0) printf ("\n      ");
			printf ("%3d", factors[i]);
		}
		printf ("\n");
		primes.clear();
		factors.clear();
	}
	return 0;
}