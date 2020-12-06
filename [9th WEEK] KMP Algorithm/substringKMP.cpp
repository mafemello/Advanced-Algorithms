/*
	Substring KMP Algorithm
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


void computePattern (int* prefix, string pattern, int m) {
	
	long int i = 0;
	long int j = -1;
	prefix[0] = -1;

	while (i < m) {
		while (j >= 0 && pattern[i] != pattern[j]) j = prefix[j];

		i++; j++;
		prefix[i] = j;
	}
	return;
}

void KMP (string txt, string pattern) {
	int a = txt.size();
	int b = pattern.size();

	int prefix[1001];
	computePattern (prefix, pattern, b);

	long int i = 0; // txt
	long int j = 0; // pattern

	while (i < a) {
		while (j >= 0 && txt[i] != pattern[j]) j = prefix[j];
		i++; j++;

		if (j == b) {
			cout << "O padrao foi encontrado na posicao " << i-j << endl;
			j = prefix[j];
		}
	}
	return;
}




int main (void) {

	string txt, pattern;
	cin >> txt; cin >> pattern;

    KMP (txt, pattern);

	return 0;
}