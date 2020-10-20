/*
	Four Wheels Problem
	Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <queue>
#include <stdio.h>
#include <cstring>
using namespace std;

struct state {
	int depth; //o qnt desceu na arvore
	int digit[4]; // pos da roleta
	int f, h; //A* parameters
	/*
		f = g + h
		g = depth
		h = heuristic
		================
		current.f = current.depth + current.h
	*/
};

struct compareH {
	bool operator()(state const& s1, state const& s2) {
		return s1.f > s2.f; 
	}
};

int moves [8][4] = {{-1,0,0,0},
					 {1,0,0,0},
					 {0,-1,0,0},
					 {0,1,0,0},
					 {0,0,-1,0},
					 {0,0,1,0},
					 {0,0,0,-1},
					 {0,0,0,1}};

int equal (state current, state target) {
	for (int i = 0; i < 4; i++) {
		if (current.digit[i] != target.digit[i])
			return 0;
	}
	return 1;
}


int heuristic (state current, state target) {
	
	int answer = 0;

	for (int i = 0; i< 4; i++) {
		int smaller = min(target.digit[i], current.digit[i]);
		int bigger = max (target.digit[i], current.digit[i]);

		int diff_1 = bigger-smaller;
		int diff_2 = smaller+10-bigger;

		answer += min(diff_1, diff_2);
	}
	return answer;
}

void next_state (state current, state next[8]) {
	for (int i = 0; i < 8; i++) {
		next[i] = current;
		next[i].depth = current.depth + 1;
		for (int j = 0; j < 4; j++) {
			next[i].digit[j] += moves[i][j];
			if (next[i].digit[j] < 0)
				next[i].digit[j] = 9;
			if (next[i].digit[j] > 9) 
				next[i].digit[j] = 0;
		}
	}
	return;
}

int wheels_play (state current, state target, int visited[10][10][10][10]) {
	priority_queue <state, vector<state>, compareH> priori;
	state next[8];

	// is it available?
	if (!visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]]){
		visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]] = 1; // visited
		priori.push(current); 
		
		while (!priori.empty()) {
			current = priori.top();
			priori.pop();

			if (equal(current, target)){
				return current.depth; // done :)
			}
			
			// not equal, so we choose which is going to be the next state
			// next state chosen based on heuristic
			next_state (current, next);
			for (int i = 0; i < 8; i++) {
				if (!visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]]) {
					visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]] = 1;	
					next[i].f = next[i].depth + heuristic(next[i], target);
					priori.push (next[i]);
				}
			}
		}
	}

	return -1;
}


int main (void) {

	int test_cases = 0; int num_forbidden = 0; int visited[10][10][10][10];
	state initial, target, forbidden;
	
	cin >> test_cases;
	for (int k = 0; k < test_cases; k++) {
		scanf ("%d %d %d %d", &initial.digit[0], &initial.digit[1], &initial.digit[2], &initial.digit[3]);
		scanf ("%d %d %d %d", &target.digit[0], &target.digit[1], &target.digit[2], &target.digit[3]);

		cin >> num_forbidden;	
		memset(visited, 0, sizeof (visited));

		for (int i = 0; i < 10; i++) 
			for (int j = 0; j < 10; j++) 
				for (int k = 0; k < 10; k++) 
					for (int l = 0; l < 10; l++) 
						visited[i][j][k][l] = 0;
		
		for (int i = 0; i < num_forbidden; i++) {
			scanf ("%d %d %d %d", &forbidden.digit[0], &forbidden.digit[1], &forbidden.digit[2], &forbidden.digit[3]);
			visited[forbidden.digit[0]][forbidden.digit[1]][forbidden.digit[2]][forbidden.digit[3]] = 1;
		}

		initial.depth = 0;
		printf ("%d\n", wheels_play(initial, target, visited));
	}
	return 0;
}