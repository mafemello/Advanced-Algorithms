/*
	Factovisors Problem
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


bool check (int m, int n, int counter) {   

    long prime = n;

    while (m / prime && counter > 0) {
        int aux = m/prime;
        counter -= aux;
        prime *= n;
    }
	
    if (counter <= 0) return true;
    return false;
}


void solveIt (int m, int n, int counter, int tmp, bool isDiv) {
    tmp = n;
    isDiv = true;

    for (int i = 2; i*i <= n && isDiv; i++) {
        counter = 0;
        while (n % i == 0) {
            n /= i;
            counter++;
        }
        if (counter > 0) isDiv = check (m, i, counter);
    }

    if (n > 1 && isDiv) isDiv = check (m, n, 1);

    if (isDiv) cout << tmp << " divides " << m << "!" << endl;
    else cout << tmp << " does not divide " << m << "!" << endl;

    return;
}

int main (void) {
    int m, n, counter = 0, tmp = 0;
    bool isDiv = true;;

	while (cin >> m && cin >> n) 
        solveIt (m, n, counter, tmp, isDiv);   
	
	return 0;
}