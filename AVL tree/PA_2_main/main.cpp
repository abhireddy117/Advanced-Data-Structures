#include "AVLTree.h"

using namespace std;

#include <vector>
#include <stdio.h>
#include <time.h>    
#include <algorithm>
#include <random>

int main() {
	

	AVLNode<int>* H = new AVLNode<int>();

	int data[50] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99 };

	AVLTree<int> * ascending = new AVLTree<int>();
	AVLTree<int>* descending = new AVLTree<int>();
	AVLTree<int>* random = new AVLTree<int>();
	
	for (int i = 0; i < 50; i++) {


		ascending->insert(ascending->root, data[i]);
		descending->insert(descending->root, data[i]);
		
	}

	std::random_shuffle(data, data + 50);

	for (int i = 0; i < 50; i++) {
		random->insert(random->root, data[i]);
	}

	

	ascending->calc_height(ascending->root);
	cout << "Height of Asending Tree:      " << ascending->root->height << endl << endl;
	descending->calc_height(descending->root);
	cout << "Height of Desending  Tree:     " << descending->root->height << endl << endl;
	random->calc_height(random->root);
	cout << "Height of Random Tree :      " << random->root->height << endl << endl;
	
	
	
	if (ascending->validate(ascending->root) == true) {
		cout << "The Ascending Tree is balanced" << endl << endl;

	}
	else {
		cout << "The Ascending Tree is not-balanced" << endl << endl;
	}

	if (descending->validate(descending->root) == true) {
		cout << "The Descending Tree is balanced" << endl << endl;

	}
	else {
		cout << "The Descending Tree is not-balanced" << endl << endl;
	}
	if (random->validate(random->root) == true) {
		cout << "The Random Tree is balanced" << endl << endl;

	}
	else {
		cout << "The Random Tree is not-balanced" << endl << endl;
	}
	
	return 0;
}