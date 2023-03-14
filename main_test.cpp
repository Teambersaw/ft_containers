#include "RBT.hpp"
#include "map.hpp"
#include "pair.hpp"
#include <iostream>
#include <map>
#include <iterator>
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

template <class T, class B>
std::ostream &operator<<(std::ostream &stream, ft::map<T, B> & tree)
{
    printTree(stream, tree._tree.root, tree._tree.nill, NULL, false);
    stream << std::endl;
    return (stream);
}

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
}

template <typename R>
void print_info(R &map)
{
	std::cout << "\n\n###############################################" << std::endl;
	printSize(map);
	std::cout << "\n" << map << '\n';
	std::cout << "Root value : " << map._tree.root->value.first << std::endl;
	std::cout << "Max value : " << map._tree.maximum(map._tree.root)->value.first << std::endl;
	std::cout << "Nill parent value : " << map._tree.nill->parent->value.first << std::endl;
	std::cout << "\n###############################################" << std::endl;
}
int main()
{
	ft::map<int, const char*> map;
	map.insert(ft::make_pair(0, "A"));
	map.insert(ft::make_pair(1, "B"));
	map.insert(ft::make_pair(2, "C"));
	map.insert(ft::make_pair(3, "D"));
	map.insert(ft::make_pair(4, "E"));
	map.insert(ft::make_pair(5, "F"));
	map.insert(ft::make_pair(6, "G"));
	map.insert(ft::make_pair(7, "H"));
	map.insert(ft::make_pair(8, "I"));
	map.insert(ft::make_pair(9, "J"));
	map.insert(ft::make_pair(10, "K"));
	map.insert(ft::make_pair(11, "L"));
	map.insert(ft::make_pair(12, "M"));

	std::cout << "begin" << std::endl;
	map.erase(map.begin());
	print_info(map);

	std::cout << "--end" << std::endl;	
	map.erase(--map.end());
	map.erase(--map.end());
	map.erase(--map.end());
	map.erase(--map.end());
	map.erase(--map.end());
	map.erase(--map.end());
	print_info(map);



	map.erase(--(--(--map.end())));
	print_info(map);

	// map.erase(--(--(--map.end())));
	// map.erase(--(--(--map.end())));

	print_info(map);

	return (0);
}
