#ifndef AVLNODE_H
#define AVLNODE_H

#include <queue>
#include <iostream>
#include <algorithm>

template <class T>

class AVLNode {
public:

	T key;
	AVLNode* left, * right;
	int height;


	
	AVLNode() {
		left = right = nullptr;
		height = 0;
	}

	
	AVLNode(const T& el, AVLNode* l = nullptr, AVLNode* r = nullptr) {
		key = el;
		left = l;
		right = r;
		height = 0;
	}

	         
};
#endif // !AVLNODE_H
