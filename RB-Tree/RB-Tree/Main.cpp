#include "RB-Tree.h"
#include <iostream>
using namespace std;

int main(){
	RB_Tree<int> *tree = new RB_Tree<int>();
	tree->Insert(11);
	tree->Insert(2);
	tree->Insert(14);

	tree->Print();

	tree->Insert(1);
	tree->Print();

	tree->Insert(7);
	tree->Insert(5);
	tree->Print();

	tree->Insert(8);
	tree->Insert(15);
	tree->Print();

	tree->Insert(4);
	tree->Print();
	system("pause");
	return 0;
}