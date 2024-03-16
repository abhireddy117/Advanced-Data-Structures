//#include "AVLTree.h"
//
//
//template<class T>
// AVLTree<T>::AVLTree()
//{
//	 root = nullptr;
//}
//
//template<class T>
//void AVLTree<T>::calc_height(AVLNode<T>* node) {
//	if (node->left == nullptr && node->right == nullptr) {
//		node->height = 0;
//	}
//
//	//No left child
//	else if (node->left == nullptr) {
//		node->height = (node->right)->height + 1;
//	}
//
//	//No right child
//	else if (node->right == nullptr) {
//		node->height = (node->left)->height + 1;
//	}
//
//	//Have both children
//	else {
//		node->height = std::max((node->left)->height, (node->right)->height) + 1;
//	}
//}
//
//template<class T>
//void AVLTree<T>::right_rotation(AVLNode<T>* node) {
//	AVLNode<T>* left = node->left;
//	AVLNode<T>* temp = node;
//
//	node->left = left->right;
//	left->right = node;
//	node = left;
//
//	/*Update heights*/
//	calc_height(temp);
//	calc_height(left);
//	calc_height(node);
//}
//
//template<class T>
//void AVLTree<T>::left_rotation(AVLNode<T>* node) {
//
//	AVLNode<T>* right = node->right;
//	AVLNode<T>* temp = node;
//
//	node->right = right->left;
//	right->left = node;
//	node = right;
//
//	/*Update heights*/
//	calc_height(temp);
//	calc_height(right);
//	calc_height(node);
//}
//
//template<class T>
//int AVLTree<T>::calc_balance_factor(AVLNode<T>* node) {
//	/*Nothing there to calculate*/
//	if (node == nullptr) {
//		return 0;
//	}
//
//	/*At least one node present in tree*/
//	else {
//		//No children
//		if (node->left == nullptr && node->right == nullptr) {
//			return 0;
//		}
//
//		//No left child
//		else if (node->left == nullptr) {
//			return (-1) - (node->right)->height;
//		}
//
//		//No right child
//		else if (node->right == nullptr) {
//			return (node->left)->height - (-1);
//		}
//
//		//Both children
//		else {
//			/*Left node height - right node height*/
//			return (node->left)->height - (node->right)->height;
//		}
//	}
//}
//
//template<class T>
//void AVLTree<T>::tree_balance(AVLNode<T>* node, int& balanceFactor) {
//
//	// Left-left case : right rotation
//	if (balanceFactor > 1 && calc_balance_factor(node->left) >= 0) {
//		right_rotation(node);
//	}
//
//	// Right-right case : left rotation
//	if (balanceFactor < -1 && calc_balance_factor(node->right) <= 0) {
//		left_rotation(node);
//	}
//
//	// Left-right case : left-right rotation
//	if (balanceFactor > 1 && calc_balance_factor(node->left) < 0)
//	{
//		left_rotation(node->left);
//		right_rotation(node);
//	}
//
//	// Right-left case : right-left rotation
//	if (balanceFactor < -1 && calc_balance_factor(node->right) > 0)
//	{
//		right_rotation(node->right);
//		left_rotation(node);
//	}
//}
//template<class T>
//void AVLTree<T>::insert(AVLNode<T>* node, const T& key) {
//	if (node == nullptr) {
//		node = new AVLNode<T>(key);
//	}
//	else if (key > node->key) {
//		insert(node->right, key);
//	}
//	else {
//		insert(node->left, key);
//	}
//
//	/*Update height*/
//	calc_height(node);
//
//	/*Calculate balance factor*/
//	int balanceFactor = calc_balance_factor(node);
//
//	/*Balance the tree*/
//	tree_balance(node, balanceFactor);
//}
//template<class T>
//bool AVLTree<T>::contains(AVLNode<T>* root, const T& key) {
//
//	/*Base case: key not found*/
//	if (root == nullptr) {
//		return false;
//	}
//
//	/*Second base case: key found*/
//	else if (root->key == key) {
//		return true;
//	}
//
//	// Move to left subtree
//	if (key < root->key) {
//		contains(root->left, key);
//	}
//
//	// Move to right subtree
//	else if (key > root->key) {
//		contains(root->right, key);
//	}
//}
//
//template<class T>
//bool AVLTree<T>::validate(AVLNode<T>* node) {
//	if (node->left->height - node->right->height == 0) {
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
////template<class T>
////void AVLTree<T>::insert_main(const T& key){
////	insert(root, key);
////}
//
////void TemporaryFunction()
////{
////	AVLTree<int> TempObj;
////	AVLTree<int>insert_main();
////	
////}
