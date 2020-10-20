/*
	Luchu Wifes
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

// global
vector<int> g_heights;
vector<int> luchu_h;

int distancia_menor (int target, int n) {

	int menor = 0;
	for (int i = 0; i < n; i++) {
		if (g_heights[i] < target) {
			menor = g_heights[i];
		}
	}
	if (menor == 0) 
		return 0;
	else 
		return menor;
}

int distancia_maior (int target, int n) {

	int maior = 0;
	for (int i = 0; i < n; i++) {
		if (g_heights[i] > target) {
			maior = g_heights[i];
			break;
		}
	}

	if (maior == 0)
		return 0;
	else 
		return maior;
}


void LuchuWife (int girls, int n) {

	int menor, maior;
	for (int i = 0; i < n; i++) {
		menor = distancia_menor (luchu_h[i], girls);
		maior = distancia_maior (luchu_h[i], girls);

		if (menor == 0) {
			printf ("X ");
		} else printf ("%d ", menor);

		if (maior == 0){
			printf("X\n");
		} else printf("%d\n", maior);
	}


	return;
}


int main (void) {

	int n_girls = 0;
	cin >> n_girls;

	for (int i = 0; i < n_girls; i++) {
		int aux;
		cin >> aux;
		g_heights.push_back(aux);
	}

	int q = 0; cin >> q;
	for (int i = 0; i < n_girls; i++) {
		int aux;
		cin >> aux;
		luchu_h.push_back(aux);
	}

	LuchuWife(n_girls, q);
	g_heights.clear();
	luchu_h.clear();

	return 0;
}