#include "Node.h"
#include <iostream>
using namespace std;
#ifndef __RB_TREE_H__
#define __RB_TREE_H__

template<class T>
class RB_Tree{
public :
	Node<T> *root;
	Node<T> *NIL;  //root->parent && node->left = NIL node->right = NIL
	RB_Tree();
	void Insert(T);
	void Delete(Node<T>*);
	Node<T> *Lookup(T);
	void Print();
private :
	void RB_Insert_Fixup(Node<T> *);
	Node<T> *LeftRotation(Node<T>*);
	Node<T> *RightRotation(Node<T>*);
	void PreOrder();
	void InOrder();
	void PostOrder();

	void __preOrder(Node<T>*);
	void __inOrder(Node<T>*);
	void __postOrder(Node<T>*);
};

template <class T>
RB_Tree<T>::RB_Tree(){
	NIL = new Node<T>(0, RED);
	NIL->left = NIL;
	NIL->right = NIL;
	NIL->color = BLACK;
	root = NIL;
}

template <class T>
Node<T> *RB_Tree<T>::LeftRotation(Node<T> *node){
	Node<T> *rightNode = node->right;
	node->right = rightNode->left;
	rightNode->left->parent = node;
	rightNode->left = node;
	rightNode->parent = node->parent;
	if (node->parent != NIL)
		if (node->parent->left == node)
			node->parent->left = rightNode;
		else
			node->parent->right = rightNode;
	else
		root = rightNode;
	node->parent = rightNode;
	return rightNode;
}

template <class T>
Node<T> *RB_Tree<T>::RightRotation(Node<T> *node){
	Node<T> *leftNode = node->left;
	node->left = leftNode->right;
	leftNode->right->parent = node;
	leftNode->right = node;
	leftNode->parent = node->parent;
	if (node->parent != NIL)
		if (node->parent->left == node)
			node->parent->left = leftNode;
		else
			node->parent->right = leftNode;
	else
		root = leftNode;
	node->parent = leftNode;
	return leftNode;
}

template <class T>
void RB_Tree<T>::__preOrder(Node<T> *node){
	if (node == NIL)
		return;
	cout << node->data << "(" << node->color << ") ";
	__preOrder(node->left);
	__preOrder(node->right);
}
template <class T>
void RB_Tree<T>::PreOrder(){
	cout << "PreOrder : ";
	__preOrder(root);
	cout << endl;
}

template <class T>
void RB_Tree<T>::__inOrder(Node<T> *node){
	if (node == NIL)
		return;
	__inOrder(node->left);
	cout << node->data << "(" << node->color << ") ";
	__inOrder(node->right);
}
template <class T>
void RB_Tree<T>::InOrder(){
	cout << "InOrder : ";
	__inOrder(root);
	cout << endl;
}

template <class T>
void RB_Tree<T>::__postOrder(Node<T> *node){
	if (node == NIL)
		return;
	__postOrder(node->left);
	__postOrder(node->right);
	cout << node->data << "(" << node->color << ") ";
}
template <class T>
void RB_Tree<T>::PostOrder(){
	cout << "PostOrder : ";
	__postOrder(root);
	cout << endl;
}

template <class T>
void RB_Tree<T>::Print(){
	cout << " ====================================" << endl;
	PreOrder();
	InOrder();
	PostOrder();
	cout << " ====================================" << endl;
}

template <class T>
void RB_Tree<T>::RB_Insert_Fixup(Node<T> *node){
	Node<T> *uncle = NULL;
	while (node->parent->color == RED){
		if (node->parent == node->parent->parent->left){
			uncle = node->parent->parent->right;
			if (uncle->color == RED){  //case 1
				uncle->color = BLACK;
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else if (node == node->parent->right){  //case 2
				node = node->parent;
				LeftRotation(node);
			}
			else{  //case 3
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				RightRotation(node->parent->parent);
			}
		}
		else{
			uncle = node->parent->parent->left;
			if (uncle->color == RED){
				uncle->color = BLACK;
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else if (node == node->parent->left){
				node = node->parent;
				RightRotation(node);
			}
			else{
				node->parent->parent->color = RED;
				node->parent->color = BLACK;
				LeftRotation(node->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

template <class T>
void RB_Tree<T>::Insert(T data){
	Node<T> *newNode = new Node<T>(data, RED);
	Node<T> *node = root;
	Node<T> *parent = NIL;
	while (node != NIL){
		parent = node;
		if (data < node->data)
			node = node->left;
		else if (data > node->data)
			node = node->right;
		else{
			cout << data << " is already in this tree! " << endl;
			return;
		}
	}
	newNode->parent = parent;
	newNode->left = NIL;
	newNode->right = NIL;

	if (parent == NIL){  //tree is empty
		root = newNode;
	}
	else if (data < parent->data){
		parent->left = newNode;
	}
	else{
		parent->right = newNode;
	}
	RB_Insert_Fixup(newNode);
};
#endif