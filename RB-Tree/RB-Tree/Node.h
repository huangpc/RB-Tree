#include <iostream>
using namespace std;
#ifndef __NODE_H__
#define __NODE_H__
typedef bool ColorType;
const ColorType RED = false;
const ColorType BLACK = true;

template<class T>
class Node{
public :
	T data;  //data of node
	ColorType color; //color of node
	Node<T> *left;
	Node<T> *right;
	Node<T> *parent;
	Node(T _data, ColorType _color) : data(_data), color(_color), left(NULL), right(NULL), parent(NULL){};

	Node<T> *minimum();
	Node<T> *maximum();
};

template <class T>
Node<T> *Node<T>::minimum(){
	Node<T> *node = this;
	while (node->left){
		node = node->left;
	}
	return node;
}

template <class T>
Node<T> *Node<T>::maximum(){
	Node<T> *node = this;
	while (node->right)
		node = node->right;
	return node;
}
#endif