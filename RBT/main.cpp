#include "RBT.hpp"
#include "map.hpp"
#include "../pair.hpp"
#include <iostream>

using namespace ft;

int main()
{
	RBT<ft::pair<int, int> >	tree;
	ft::pair<int, int> pr(6,20);
	ft::pair<int, int> pr2(4,8);
	tree.insert_node(pr);
	return (0);
}