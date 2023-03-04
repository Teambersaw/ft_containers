#include "RBT.hpp"
#include "map.hpp"
#include "../pair.hpp"
#include <iostream>
#include <map>
using namespace ft;

#define RED_COLOR "\e[0;31m"
#define BLACK_COLOR "\e[0;35m"
#define RESET_COLOR "\e[0;0m"

struct subTree
{
    subTree *_prev;
    std::string _str;

    subTree(subTree *prev, std::string str) : _prev(prev), _str(str)    {}
};

template <class T, class U>
std::ostream &operator<<(std::ostream &stream, ft::pair<T, U> const &pair)
{
	stream << "(" << pair.first << ", " << pair.second << ')';
	return (stream);
}

void printTrunks(std::ostream &stream, subTree *p)
{
    if (!p)
        return;
    printTrunks(stream, p->_prev);
    stream << p->_str;
}

template<typename T>
void printTree(std::ostream &stream, Node<T>* node, Node<T>* nil, subTree *prev, bool isLeft)
{
    if (node == nil)
        return;
    std::string prev_str = "    ";
    subTree sub = subTree(prev, prev_str);
    printTree(stream, node->right, nil, &sub, true);
    if (!prev)
        sub._str = "———";
    else if (isLeft)
    {
        sub._str = ",———";
        prev_str = "   |";
    }
    else
    {
        sub._str = "`———";
        prev->_str = prev_str;
    }
    printTrunks(stream, &sub);
    stream << " " << (node->color == 1 ? RED_COLOR : BLACK_COLOR) <<  node->value << RESET_COLOR << std::endl;
    if (prev)
        prev->_str = prev_str;
    sub._str = "   |";
    printTree(stream, node->left, nil, &sub, false);
}

template <class T>
std::ostream &operator<<(std::ostream &stream, RBT<T> & tree)
{
    printTree(stream, tree.root, tree.nill, NULL, false);
    stream << std::endl;
    return (stream);
}

int main()
{
	RBT<ft::pair<int, int> >	tree;
	tree.insert_node(ft::make_pair(11, 42));
	tree.insert_node(ft::make_pair(2, 42));
	tree.insert_node(ft::make_pair(14, 42));
	tree.insert_node(ft::make_pair(15, 42));
	tree.insert_node(ft::make_pair(1, 42));
	tree.insert_node(ft::make_pair(7, 42));
	tree.insert_node(ft::make_pair(5, 42));
	tree.insert_node(ft::make_pair(8, 42));
	std::cout << tree << '\n';
	tree.insert_node(ft::make_pair(4, 42));
	tree.delete_node(ft::make_pair(14, 42));
	std::cout << tree << '\n';
	return (0);
}


// int main()
// {
// 	std::map<int, int> tree;
// 	ft::pair<int, int> pr(50,1);
// 	ft::pair<int, int> pr2(30,1);
// 	ft::pair<int, int> pr3(10,1);
// 	ft::pair<int, int> pr4(40,1);
// 	ft::pair<int, int> pr5(60,1);
// 	ft::pair<int, int> pr6(60,1);
	
	
// 	return (0);
// }

			// 	while (tmp->left != nill && tmp->right != nill)
			// 	{
			// 		if (value < tmp->value) {
			// 			if (tmp->left == nill)
			// 				break;
			// 			std::cout << "loop left" << std::endl;
			// 			tmp = tmp->left;
			// 		}
			// 		else {
			// 			if (tmp->right == nill)
			// 				break;
			// 			std::cout << "loop right" << std::endl;
			// 			tmp = tmp->right;
			// 		}
			// 	}
			// 	if (value < tmp->value) {
			// 		std::cout << "new node left" << std::endl;
			// 		tmp->left = new_node(value, tmp->left);
			// 	}
			// 	else {
			// 		std::cout << "new node right" << std::endl;
			// 		tmp->right = new_node(value, tmp->right);
			// 	}
			// }