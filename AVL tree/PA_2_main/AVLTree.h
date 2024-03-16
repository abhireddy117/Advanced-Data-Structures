#include "AVLNode.h"
#include <algorithm>

using namespace std; 

template <class T>
class AVLTree
{
private:
	
	
public:
	AVLNode<T>* root;
	AVLTree();
	

	void calc_height(AVLNode<T>* &node);
	void right_rotation(AVLNode<T>* &node);
	void left_rotation(AVLNode<T>* &node);
	int calc_balance_factor(AVLNode<T>* node);
	void tree_balance(AVLNode<T>* &node, int& balanceFactor);
	void insert(AVLNode<T>* &node, const T& key);
	bool contains(AVLNode<T>* root, const T& key);
	bool validate(AVLNode<T>* node);
	/*void insert_main(const T& key);*/
	
	
};



template<class T>
AVLTree<T>::AVLTree()
{
	root = nullptr;
}

template<class T>
void AVLTree<T>::calc_height(AVLNode<T>* &node) {
	if (node->left == nullptr && node->right == nullptr) {
		node->height = 0;
	}

	else if (node->left == nullptr) {
		node->height = (node->right)->height + 1;
	}

	else if (node->right == nullptr) {
		node->height = (node->left)->height + 1;
	}

	else {
		node->height = std::max((node->left)->height, (node->right)->height) + 1;
	}
}
template<class T>
void AVLTree<T>::right_rotation(AVLNode<T>* &node) {
	AVLNode<T>* left = node->left;
	AVLNode<T>* temp = node;

	node->left = left->right;
	left->right = node;
	node = left;


	calc_height(temp);
	calc_height(left);
	calc_height(node);
}

template<class T>
void AVLTree<T>::left_rotation(AVLNode<T>* &node) {

	AVLNode<T>* right = node->right;
	AVLNode<T>* temp = node;

	node->right = right->left;
	right->left = node;
	node = right;


	calc_height(temp);
	calc_height(right);
	calc_height(node);
}

template<class T>
int AVLTree<T>::calc_balance_factor(AVLNode<T>* node) {
	if (node == nullptr) {
		return 0;
	}

	
	else {
		
		if (node->left == nullptr && node->right == nullptr) {
			return 0;
		}
		else if (node->left == nullptr) {
			return (-1) - (node->right)->height;
		}
		else if (node->right == nullptr) {
			return (node->left)->height - (-1);
		}
		else {
			return (node->left)->height - (node->right)->height;
		}
	}
}

template<class T>
void AVLTree<T>::tree_balance(AVLNode<T>* &node, int& balanceFactor) {

	
	if (balanceFactor > 1 && calc_balance_factor(node->left) >= 0) {
		right_rotation(node);
	}
	if (balanceFactor < -1 && calc_balance_factor(node->right) <= 0) {
		left_rotation(node);
	}
	if (balanceFactor > 1 && calc_balance_factor(node->left) < 0){
		left_rotation(node->left);
		right_rotation(node);
	}
	if (balanceFactor < -1 && calc_balance_factor(node->right) > 0){
		right_rotation(node->right);
		left_rotation(node);
	}
}
template<class T>
void AVLTree<T>::insert(AVLNode<T>* &node, const T& key) {
	if (node == nullptr) {
		node = new AVLNode<T>(key);
	}
	else if (key > node->key) {
		insert(node->right, key);
	}
	else {
		insert(node->left, key);
	}
	calc_height(node);
	int balanceFactor = calc_balance_factor(node);
	tree_balance(node, balanceFactor);
}
template<class T>
bool AVLTree<T>::contains(AVLNode<T>* root, const T& key) {

	
	if (root == nullptr) {
		return false;
	}

	else if (root->key == key) {
		return true;
	}
	if (key < root->key) {
		contains(root->left, key);
	}
	else if (key > root->key) {
		contains(root->right, key);
	}
}

template<class T>
bool AVLTree<T>::validate(AVLNode<T>* node) {
	if (node->left->height - node->right->height == 0) {
		return true;
	
	}
	else
	{
		return false;
	}
}




