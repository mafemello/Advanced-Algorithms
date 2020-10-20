/*
	Counting Invertions
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

// global
vector<int>elem; 
vector<int> aux;


int Combine (int left, int middle, int right) {
	
	int i = left; // left vector
	int j = middle; // right vector
	int k = left; // combined vector
	int count = 0;

	// treats the inversions between the left and right parts
	while ((i <= middle-1) && (j <= right)) {
		if (elem[i] <= elem[j]) // no inversion!
			aux[k++] = elem[i++];
		else {
			// there is an inversion!
			aux[k++] = elem[j++];
			count += (middle-i); 
		}
	}

	// copying the elements
	while (i <= middle-1) aux[k++] = elem[i++];
	while (j <= right) aux[k++] = elem[j++];
	for (i = left; i <= right; i++) elem[i] = aux[i];


	return count;
}


int SortAndCount (int left, int right) {

	int middle = 0, x = 0, y = 0, z = 0;

	// dividing the vector in 2 parts
	if (right > left) {
		middle = (right+left)/2; 
		x += SortAndCount (left, middle); // inversions on the left part
		y += SortAndCount (middle+1, right); // inversions on the right part
		z += Combine (left, middle+1, right);  // inversions on the combined part
	}
	// answer = left + right + combined
	return x+y+z;
}


int Divide (int size) {

	// if the vector size if 1, there is no inversion
	if (size == 1) return 0; 
	else {
		aux.resize(size); // auxiliar vector
		return SortAndCount (0, size-1); // sorts and count the inversions
	}
}	


int main (void) {

	int test_cases = 0;
	cin >> test_cases;
	int num_elem = 0;
	

	for (int i = 0; i < test_cases; i++) {
		cin >> num_elem;
		//vector<int>elem; 

//		memset ((void*)&elem, 0, num_elem);

		for (int j = 0; j < num_elem; j++) {
			int temp = 0;
			cin >> temp;
			elem.push_back(temp);
		}
	
		// Divide + Sort + Count + Combine!
		cout << Divide (num_elem) << endl;
		elem.clear();
	}
	return 0;
}