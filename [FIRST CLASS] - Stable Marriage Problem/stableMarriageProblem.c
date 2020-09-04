/*
	Stable Matching Problem
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <stdio.h>
#include <stdlib.h>
#define SINGLE 0
#define ENGAGED 1
#define EMPTY -1

// Function that checks if she prefers her current husband or the man proposing now
int checksHerPreference (int current_man, int current_husband, int** w_pref, int num, int woman) {

	int auxiliar_1 = 0;
	int auxiliar_2 = 0;
	// checks who appears first on her list
	for (int j = 0; j < num+1; j++) {
		if (w_pref[woman][j] == current_husband)
			auxiliar_1 = j;
	}
	for (int k = 0; k < num+1; k++) {
		if (w_pref[woman][k] == current_man)
			auxiliar_2 = k;
	}
	// she wants to change husband
	if (auxiliar_2 < auxiliar_1) {
		return 2;
	}
	// she prefers her current husband
	return 1;
}

// Function to check if the man is single
int checkSingleMan (int* single_men, int num) {
	int singleMan = EMPTY; 
	for (int i = 0; i < num; i++) {
		if (single_men[i] == SINGLE) {
			singleMan = i;
			return singleMan; // return which man is single
		}
	}
	return singleMan;
}

void stableMarriage (int num, int** w_pref, int** m_pref) {

	int* single_men = (int*)malloc(sizeof(int)*num); // list of single men
	int* single_women = (int*)malloc(sizeof(int)*num); // list of single women
	int* wifes = (int*)malloc(sizeof(int)*num); // list of wifes
	int* husbands = (int*)malloc(sizeof(int)*num); // list of husbands
	
	// everybody starts single 
	for (int i = 0; i < num; i++) {
		single_women[i] = SINGLE; single_men[i] = SINGLE; wifes[i] = SINGLE; husbands[i] = SINGLE;	
	}

	int flagWhile = 0; // flag shows when to stop while
	int current_man = 0; // who is the current man proposing
	while (flagWhile == 0) {
		int checkSingle = checkSingleMan (single_men, num); // checks if there are still single men
		if (checkSingle == EMPTY) {
			flagWhile = 1; //stops while, he is already married
			break;
		} else {
			flagWhile = 0;
			current_man = checkSingle+1; // the man is about to make proposals now
		}

		// tinder roulet 
		for (int i = 1; i < num+1; i++) { 
			int current_woman = m_pref[current_man-1][i];
			if (single_women[current_woman-1] == SINGLE) { //if his first opt is single, they get engaged
				// getting married!! :)
				wifes[current_man-1] = current_woman;
				husbands[current_woman-1] = current_man;
				single_women[current_woman-1] = ENGAGED;
				single_men[current_man-1] = ENGAGED;
				break;
			} else { // she's not single...
				int current_husband = husbands[current_woman-1]; // who she is married now
				int check = 0;
				check = checksHerPreference (current_man, current_husband, w_pref, num, current_woman-1); // let's check which man she prefers
				if (check == 2) { // she prefers the new man...
					// getting married!! :)
					wifes[current_man-1] = current_woman;
					husbands[current_woman-1] = current_man;
					single_women[current_woman-1] = ENGAGED;
					single_men[current_man-1] = ENGAGED;

					// and his ex-husband becomes single again! :(
					wifes[current_husband-1] = SINGLE;
					single_men[current_husband-1] = SINGLE; // he'll come back and propose the next woman on his list
					break;
				}
			}
		}
	}

	// prints results!	
	for (int i = 1; i <= num; i++) 
		printf("%d %d\n", i, wifes[i-1]);

	return;
}



int main (void) {

	int test = 0;
	scanf ("%d", &test);
	int num = 0;

	while (test > 0) {
		scanf ("%d", &num);

		// alocating memory
		int **w_pref = (int**)malloc(sizeof(int*)*num);
		int **m_pref = (int**)malloc(sizeof(int*)*num);
		for (int i = 0; i < num; i++) {
			w_pref[i] = (int*)malloc(sizeof(int)*num+1);
			m_pref[i] = (int*)malloc(sizeof(int)*num+1);
		}

		// reading data
		// women list of preference
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num+1; j++) {
				scanf ("%d", &w_pref[i][j]);
			}
		}
		// men list of preference
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num+1; j++) {
				scanf ("%d", &m_pref[i][j]);
			}
		}
		stableMarriage (num, w_pref, m_pref);
		test--;
	}
	return 0;
}