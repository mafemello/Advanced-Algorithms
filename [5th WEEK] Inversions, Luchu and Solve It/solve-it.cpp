/*
	Solve It
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

// p ∗ e^−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x^2 + u = 0
// where x >= 0 && x <= 1
//global


#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define EPS 1e-9
int p, q, r, s, t, u;


double calcule (double x) {
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double solveIt () {

	double lower_bound = 0, higher_bound = 1;
	double aux1 = calcule(lower_bound);
	double aux2 = calcule (0.5000);

	while (!(fabs(higher_bound - lower_bound) < EPS)) {
		double center = (lower_bound + higher_bound)/2;
		
		if (lower_bound == 0 && center == 0.5) {
			if (aux1*aux2 <= 0) {
				higher_bound = center;
			} else {
				lower_bound = center;
			}
		} else {
			if (calcule(lower_bound)*calcule(center) <= 0) {
				higher_bound = center;
			} else {
				lower_bound = center;
			}
		}
	}
	return (lower_bound + higher_bound)/2;
}


int main (void) {

	while (cin >> p) {
		cin >> q; cin >> r; cin >> s; cin >> t; cin >> u;
		if (p == 0 && q == 0 && r == 0 && s == 0 && t == 0 && u == 0) cout << "0.0000" << endl;
		else {
			if (calcule(0) * calcule(1) > 0) cout << "No solution" << endl;
			else printf ("%.4lf\n", solveIt());
		}
	}
	return 0;
}