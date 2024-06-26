// #include "RBT.hpp"
// #include "map.hpp"
// #include "pair.hpp"
// #include <iostream>
// #include <map>
// #include <iterator>
// #include "vector.hpp"
// using namespace ft;

// #define RED_COLOR "\e[0;31m"
// #define BLACK_COLOR "\e[0;35m"
// #define RESET_COLOR "\e[0;0m"

// struct subTree
// {
//     subTree *_prev;
//     std::string _str;

//     subTree(subTree *prev, std::string str) : _prev(prev), _str(str)    {}
// };

// template <class T, class U>
// std::ostream &operator<<(std::ostream &stream, ft::pair<T, U> const &pair)
// {
// 	stream << "(" << pair.first << ", " << pair.second << ')';
// 	return (stream);
// }

// void printTrunks(std::ostream &stream, subTree *p)
// {
//     if (!p)
//         return;
//     printTrunks(stream, p->_prev);
//     stream << p->_str;
// }

// template<typename T>
// void printTree(std::ostream &stream, Node<T>* node, Node<T>* nil, subTree *prev, bool isLeft)
// {
//     if (node == nil)
//         return;
//     std::string prev_str = "    ";
//     subTree sub = subTree(prev, prev_str);
//     printTree(stream, node->right, nil, &sub, true);
//     if (!prev)
//         sub._str = "———";
//     else if (isLeft)
//     {
//         sub._str = ",———";
//         prev_str = "   |";
//     }
//     else
//     {
//         sub._str = "`———";
//         prev->_str = prev_str;
//     }
//     printTrunks(stream, &sub);
//     stream << " " << (node->color == 1 ? RED_COLOR : BLACK_COLOR) <<  node->value << RESET_COLOR << std::endl;
//     if (prev)
//         prev->_str = prev_str;
//     sub._str = "   |";
//     printTree(stream, node->left, nil, &sub, false);
// }

// template <class T, class B>
// std::ostream &operator<<(std::ostream &stream, ft::map<T, B> & tree)
// {
//     printTree(stream, tree._tree.root, tree._tree.nill, NULL, false);
//     stream << std::endl;
//     return (stream);
// }

// template <typename T>
// std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
// {
// 	o << "key: " << iterator->first << " | value: " << iterator->second;
// 	if (nl)
// 		o << std::endl;
// 	return ("");
// }

// template <typename T_MAP>
// void	printSize(T_MAP const &mp, bool print_content = 1)
// {
// 	std::cout << "size: " << mp.size() << std::endl;
// 	std::cout << "max_size: " << mp.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != ite; ++it)
// 			std::cout << "- " << printPair(it, false) << std::endl;
// 	}
// }

// template <typename R>
// void print_info(R &map)
// {
// 	std::cout << "\n\n###############################################" << std::endl;
// 	printSize(map);
// 	std::cout << "\n" << map << '\n';
// 	std::cout << "Root value : " << map._tree.root->value.first << std::endl;
// 	std::cout << "Max value : " << map._tree.maximum(map._tree.root)->value.first << std::endl;
// 	std::cout << "Nill parent value : " << map._tree.nill->parent->value.first << std::endl;
// 	std::cout << "\n###############################################" << std::endl;
// }

// int main()
// {
// 	ft::map<int, int> map;
// 	map.insert(ft::make_pair(1, 1));
// 	map.insert(ft::make_pair(2, 2));
// 	map.insert(ft::make_pair(3, 3));
// 	map.insert(ft::make_pair(4, 4));
// 	map.insert(ft::make_pair(5, 5));
// 	map.insert(ft::make_pair(6, 6));
// 	map.insert(ft::make_pair(7, 7));
// 	map.insert(ft::make_pair(8, 8));
// 	print_info(map);

// 	return (0);
// }


#include <iostream>
#include <string>
#include <list>
#include <cstdlib>

#ifndef NS
# define NS std
# include <vector>
# include <stack>
# include <map>
# include <utility>
# include <set>
#else
# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"
# include "pair.hpp"
# include "set.hpp"
#endif

using namespace NS;

class test
{
	public:

		test(double val) : value(val) {}
		test() {}
		~test() {}
		
		double getValue() const { return (value);}

	private:

		double value;

};

std::ostream & operator<<( std::ostream & o, test const & rhs )
{
	o << rhs.getValue();
	return o;
}

template <class T1, class T2>
void print_map(NS::map<T1, T2> const &mymap)
{
	std::cout << "size : " << mymap.size() << "\nempty map : " << mymap.empty() << "\nmax size : " << mymap.max_size() << std::endl;
	for (typename NS::map<T1, T2>::const_iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		std::cout << "Key : " << it->first << " | " << "Value : " << it->second << std::endl;
	}
	std::cout << std::endl << std::endl;
}

template <class T1>
void print_set(NS::set<T1> const &myset)
{
	std::cout << "size : " << myset.size() << "\nempty set : " << myset.empty() << "\nmax size : " << myset.max_size() << std::endl;
	for (typename NS::set<T1>::const_iterator it = myset.begin(); it != myset.end(); it++)
	{
		std::cout << "Value :" << *it << std::endl;
	}
	std::cout << std::endl << std::endl;
}

template <class T>
void print_vect(NS::vector<T> const &myvector)
{
	std::cout << "size : " << myvector.size() << ", capacity : " << myvector.capacity() << std::endl;
	for (typename NS::vector<T>::const_iterator it = myvector.begin(); it != myvector.end(); it++)
	{
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl << std::endl;
}


void vect_test()
{
	std::cout << "\033[31m" << "\n\n#################################VECTOR TEST#############################\n" << "\033[0m\n" << std::endl;

	std::cout << "\033[31m" << "######## CONSTRUCTOR OPERATOR= TEST ########\n" << "\033[0m\n" << std::endl;

	NS::vector<test>	myvector(5, test(4));
	NS::vector<test>	myvector6;
	std::cout << "myvector : \n";
	print_vect(myvector);
	std::cout << "myvector6 : \n";
	print_vect(myvector6);
	myvector6 = myvector;
	std::cout << "myvector6 : \n";
	print_vect(myvector6);

	NS::vector<int>		myvector2(10, 20);
	NS::vector<int>		myvector3(myvector2);
	std::cout << "myvector 2 : \n";
	print_vect(myvector2);
	std::cout << "myvector 3 : \n";
	print_vect(myvector3);

	NS::vector<int>		myvector4 = myvector3;
	std::cout << "myvector 4 : \n";
	print_vect(myvector4);

	NS::vector<int>		myvector5(10, 42);
	std::cout << "myvector 5 : \n";
	print_vect(myvector5);
	myvector4 = myvector5;
	std::cout << "myvector 4 : \n";
	print_vect(myvector4);

	std::cout << "\033[31m" << "######## ELEMENT ACCESS ########\n" << "\033[0m\n" << std::endl;

	myvector3.push_back(8);
	myvector3[5] = 42;
	myvector3[0] = 23;
	std::cout << "myvector 3 : \n";
	print_vect(myvector3);
	std::cout << "front function value : ";
	std::cout << myvector3.front() << std::endl;
	std::cout << "begin function value : ";
	std::cout << *myvector3.begin() << std::endl;
	std::cout << "back function value : ";
	std::cout << myvector3.back() << std::endl;
	std::cout << "at(5) function value : ";
	std::cout << myvector3.at(5) << std::endl;

	std::cout << "\033[31m" << "\n######## CAPACITY TEST ########\n" << "\033[0m\n" << std::endl;

	std::cout << "max_size myvector : ";
	std::cout << myvector.max_size() << std::endl;
	std::cout << "max_size myvector 3 : ";
	std::cout << myvector3.max_size() << std::endl;

	std::cout << "\nresize(30, 67) myvector 2 : \n";
	myvector2.resize(30, 67);
	print_vect(myvector2);

	std::cout << "resize(15, 12) myvector 2 : \n";
	myvector2.resize(15, 12);
	print_vect(myvector2);

	NS::vector<int>	myvector7;
	std::cout << "empty myvector 4 : ";
	std::cout << myvector4.empty() << std::endl;
	std::cout << "empty myvector 7 : ";
	std::cout << myvector7.empty() << std::endl;

	std::cout << "\nmyvector 3 : \n";
	print_vect(myvector3);
	std::cout << "reserve(40) myvector 3 : ";
	myvector3.reserve(40);
	print_vect(myvector3);
	std::cout << "reseve(20) myvector 3 : ";
	myvector3.reserve(20);
	print_vect(myvector3);

	std::cout << "\033[31m" << "\n######## MODIFIER TEST ########\n" << "\033[0m\n" << std::endl;

	std::cout << "myvector 5 : \n";
	print_vect(myvector5);
	std::cout << "myvector 5 erase(begin, begin + 5) : \n";
	myvector5.erase(myvector5.begin(), myvector5.begin() + 5);
	print_vect(myvector5);
	std::cout << "myvector 5 erase(end() - 3) : \n";
	myvector5.erase(myvector5.end() - 3);
	print_vect(myvector5);

	std::cout << "myvector 5 insert(begin() + 2, 7) : \n";
	myvector5.insert(myvector5.begin() + 2, 7);
	print_vect(myvector5);
	std::cout << "myvector 5 insert(begin() + 3, 10, 30) : \n";
	myvector5.insert(myvector5.begin() + 3, 10, 30);
	print_vect(myvector5);


	std::cout << "myvector 3 : \n";
	print_vect(myvector3);
	std::cout << "myvector 5 insert(begin() + 7, myvector3.begin(), myvector3.end()) : \n";
	myvector5.insert(myvector5.begin() + 7, myvector3.begin(), myvector3.end());
	print_vect(myvector5);

	std::cout << "myvector 3 assign(myvector5.begin(), myvector5.end()) : \n";
	myvector3.assign(myvector5.begin(), myvector5.end());
	print_vect(myvector3);

	std::cout << "myvector 3 assign(10, 10) : \n";
	myvector3.assign(10, 10);
	print_vect(myvector3);

	std::cout << "myvector 4 : \n";
	print_vect(myvector4);
	std::cout << "myvector 4 clear(): \n";
	myvector4.clear();
	std::cout << "myvector 4 : \n";
	print_vect(myvector4);

	std::cout << "myvector 3 swap myvector 4 : \n";
	myvector3.swap(myvector4);
	std::cout << "myvector 4 : \n";
	print_vect(myvector4);
	std::cout << "myvector 3 : \n";
	print_vect(myvector3);

	std::cout << "myvector 4 push_back * 4, 5: \n";
	myvector4.push_back(5);
	myvector4.push_back(5);
	myvector4.push_back(5);
	myvector4.push_back(5);
	print_vect(myvector4);

	std::cout << "myvector 4 pop_back * 4: \n";
	myvector4.pop_back();
	myvector4.pop_back();
	myvector4.pop_back();
	myvector4.pop_back();
	print_vect(myvector4);


	std::cout << "\033[31m" << "\n######## RELATIONAL OPERATOR TEST ########\n" << "\033[0m\n" << std::endl;
	NS::vector<int> foo (10,200);
	NS::vector<int> bar (50,600);
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo<bar) std::cout << "foo is less than bar\n";
	if (foo>bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	swap(foo, bar);
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo<bar) std::cout << "foo is less than bar\n";
	if (foo>bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n\n";
	foo = bar;
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo<bar) std::cout << "foo is less than bar\n";
	if (foo>bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << "\033[31m" << "\n######## REVERSE ITERATOR TEST ########\n" << "\033[0m\n" << std::endl;


	std::cout << "Reverse iterator print myvector 5 : " << std::endl;
	NS::vector<int>::reverse_iterator rit = myvector5.rbegin();
	for (; rit!= myvector5.rend(); ++rit)
		std::cout << "[" << *rit << "] ";
	std::cout << "\n\nmyvector 5 : \n";
	print_vect(myvector5);

	std::cout << "iterator print myvector 5" << std::endl;
	for (NS::vector<int>::iterator it = myvector5.begin(); it != myvector5.end(); it++)
	{
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl << std::endl;
}

void stack_test()
{
	std::cout << "\033[31m" << "\n######## STACK TEST ########\n" << "\033[0m\n" << std::endl;

	{
		std::cout << "stack with ft::vector" << std::endl;
		NS::stack<int>	mstack;

		std::cout << "empty: ";
		std::cout << mstack.empty() << std::endl;

		std::cout << "push * 2" << std::endl;
		mstack.push(1);
		mstack.push(2);


		std::cout << "empty: ";
		std::cout << mstack.empty() << std::endl;

		std::cout << "return top function: "<< mstack.top() << std::endl;

		std::cout << "pop" << std::endl;
		mstack.pop();

		std::cout << "Size of stack: " << mstack.size() << std::endl;

		std::cout << "push * 4" << std::endl;
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);

		std::cout << "Size of stack: " << mstack.size() << std::endl;
		std::cout << "return top function: "<< mstack.top() << std::endl;

	}

	std::cout << "\n\n";

	{
		std::cout << "stack with std::list" << std::endl;
		NS::stack<int, std::list<int> >	mstack;

		std::cout << "empty: ";
		std::cout << mstack.empty() << std::endl;

		std::cout << "push * 2" << std::endl;
		mstack.push(1);
		mstack.push(2);

		std::cout << "empty: ";
		std::cout << mstack.empty() << std::endl;

		std::cout << "return top function: "<< mstack.top() << std::endl;

		std::cout << "pop" << std::endl;
		mstack.pop();

		std::cout << "Size of stack: " << mstack.size() << std::endl;

		std::cout << "push * 4" << std::endl;
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);

		std::cout << "Size of stack: " << mstack.size() << std::endl;
		std::cout << "return top function: "<< mstack.top() << std::endl;

	}

	{
		std::cout << "\n\nrelational operator" << std::endl;
		NS::stack<int> a, b, c;
		a.push(10);
		a.push(20);
		a.push(30);

		b.push(10);
		b.push(20);
		b.push(30);

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
	}

	std::cout << "\n\n";
}

void map_test()
{
	std::cout << "\033[31m" << "\n######## MAP TEST ########\n" << "\033[0m\n" << std::endl;

	std::cout << "\033[31m" << "######## CONSTRUCTOR OPERATOR TEST ########\n" << "\033[0m\n" << std::endl;
	
	NS::map<int, std::string> mymap;
	print_map(mymap);
	mymap.insert(NS::make_pair(4, "oui"));
	mymap.insert(NS::make_pair(12, "non"));
	mymap.insert(NS::make_pair(0, "peut-être"));
	mymap.insert(NS::make_pair(45, "probablement"));
	mymap.insert(NS::make_pair(100, "surement"));
	mymap.insert(NS::make_pair(86, "certainement"));
	mymap.insert(NS::make_pair(72, "pourquoi pas"));
	std::cout << "mymap :\n";
	print_map(mymap);

	std::cout << "mymap2 copy  iterator mymap :\n";
	NS::map<int, std::string> mymap2(mymap.begin(), mymap.end());
	print_map(mymap2);

	std::cout << "mymap3 copy construct mymap2 :\n";
	NS::map<int, std::string> mymap3(mymap2);
	print_map(mymap3);

	std::cout << "mymap4 operator = mymap3 :\n";
	NS::map<int, std::string> mymap4 = mymap3;
	print_map(mymap4);

	std::cout << "mymap operator[]" << std::endl;
	std::cout << mymap[4] << std::endl;
	std::cout << mymap[12]<< std::endl;
	std::cout << "mymap : ";
	print_map(mymap);
	mymap[4] = "plop42";
	std::cout << mymap[13] << std::endl;
	std::cout << "mymap :\n";
	print_map(mymap);


	std::cout << "\033[31m" << "######## Upper/Lower bound, equal range test ########\n" << "\033[0m\n" << std::endl;
	
	NS::map<char, int> mymaps;
	NS::map<char, int>::iterator itlow, itup;

	mymaps['a'] = 20;
	mymaps['b'] = 40;
	mymaps['c'] = 60;
	mymaps['d'] = 80;
	mymaps['e'] = 100;

	itlow=mymaps.lower_bound ('b');
	itup=mymaps.upper_bound ('d');

	std::cout << "low : " << itlow->first << '\n';
	std::cout << "up : " << itup->first << '\n';

	std::cout << "\nmymaps :\n";
	print_map(mymaps);

	std::cout << "equal range test : \n";
	NS::pair<NS::map<char,int>::iterator, NS::map<char,int>::iterator> ret;
	ret = mymaps.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	std::cout << "\033[31m" << "######## modifiers test ########\n" << "\033[0m\n" << std::endl;

	std::cout << "mymap :\n";
	print_map(mymap);

	NS::map<int, std::string> mymap_insert;
	mymap_insert.insert(NS::make_pair(120, "oui"));
	mymap_insert.insert(NS::make_pair(15, "non"));
	mymap_insert.insert(NS::make_pair(28, "peut-être"));
	mymap_insert.insert(NS::make_pair(33, "probablement"));
	mymap_insert.insert(NS::make_pair(55, "surement"));
	mymap_insert.insert(NS::make_pair(99, "certainement"));
	mymap_insert.insert(NS::make_pair(57, "pourquoi pas"));
	std::cout << "mymap_insert :\n";
	print_map(mymap_insert);

	mymap.insert(mymap_insert.begin(), mymap_insert.end());
	std::cout << "mymap insert(mymap_insert.begin(), mymap_insert.end()):\n";
	print_map(mymap);


	std::cout << "mymap_insert clear :\n";
	mymap_insert.clear();
	print_map(mymap_insert);


	mymap.erase((++(++(++(mymap.begin())))));
	mymap.erase((--(--(--(mymap.end())))));
	mymap.erase(33);
	std::cout << "mymap :\n";
	print_map(mymap);

	std::cout << "reverse iterator mymap : " << std::endl;
	NS::map<int, std::string>::reverse_iterator rit_map;
	for (rit_map = mymap.rbegin(); rit_map != mymap.rend(); ++rit_map)
		std::cout << rit_map->first << " => " << rit_map->second << '\n';

	std::cout << "\nmymap.swap(mymap_insert)" << std::endl;
	mymap.swap(mymap_insert);
	std::cout << "mymap :\n";
	print_map(mymap);

	std::cout << "mymap_insert :\n";
	print_map(mymap_insert);

	std::cout << "\033[31m" << "######## Relational operator/swap ########\n" << "\033[0m\n" << std::endl;
	NS::map<char, int> foo_m, bar_m;
	foo_m['a']=100;
	foo_m['b']=200;
	bar_m['a']=10;
	bar_m['z']=1000;

	if (foo_m==bar_m) std::cout << "\nfoo_m and bar_m are equal\n";
	if (foo_m!=bar_m) std::cout << "foo_m and bar_m are not equal\n";
	if (foo_m< bar_m) std::cout << "foo_m is less than bar_m\n";
	if (foo_m> bar_m) std::cout << "foo_m is greater than bar_m\n";
	if (foo_m<=bar_m) std::cout << "foo_m is less than or equal to bar_m\n";
	if (foo_m>=bar_m) std::cout << "foo_m is greater than or equal to bar_m\n";
	NS::swap(foo_m, bar_m);
	if (foo_m==bar_m) std::cout << "\nfoo_m and bar_m are equal\n";
	if (foo_m!=bar_m) std::cout << "\nfoo_m and bar_m are not equal\n";
	if (foo_m< bar_m) std::cout << "foo_m is less than bar_m\n";
	if (foo_m> bar_m) std::cout << "foo_m is greater than bar_m\n";
	if (foo_m<=bar_m) std::cout << "foo_m is less than or equal to bar_m\n";
	if (foo_m>=bar_m) std::cout << "foo_m is greater than or equal to bar_m\n";
	foo_m = bar_m;
	if (foo_m==bar_m) std::cout << "\nfoo_m and bar_m are equal\n";
	if (foo_m!=bar_m) std::cout << "foo_m and bar_m are not equal\n";
	if (foo_m< bar_m) std::cout << "foo_m is less than bar_m\n";
	if (foo_m> bar_m) std::cout << "foo_m is greater than bar_m\n";
	if (foo_m<=bar_m) std::cout << "foo_m is less than or equal to bar_m\n";
	if (foo_m>=bar_m) std::cout << "foo_m is greater than or equal to bar_m\n";
}

void set_test()
{
	std::cout << "\033[31m" << "######## SET TEST ########\n" << "\033[0m\n" << std::endl;

	std::cout << "\033[31m" << "######## CONSTRUCTOR OPERATOR TEST ########\n" << "\033[0m\n" << std::endl;
	
	NS::set<int> myset;
	print_set(myset);
	myset.insert(2);
	myset.insert(12);
	myset.insert(96);
	myset.insert(77);
	myset.insert(85);
	myset.insert(42);
	myset.insert(4);
	std::cout << "myset :\n";
	print_set(myset);

	std::cout << "myset2 copy  iterator myset :\n";
	NS::set<int> myset2(myset.begin(), myset.end());
	print_set(myset2);

	std::cout << "myset3 copy construct myset2 :\n";
	NS::set<int> myset3(myset2);
	print_set(myset3);

	std::cout << "myset4 operator = myset3 :\n";
	NS::set<int> myset4 = myset3;
	print_set(myset4);

	std::cout << "\033[31m" << "######## Upper/Lower bound, equal range test ########\n" << "\033[0m\n" << std::endl;
	
	NS::set<int> mysets;
	NS::set<int>::iterator itlow_set, itup_set;


	itlow_set=mysets.lower_bound(77);
	itup_set=mysets.upper_bound(42);

	std::cout << "low : " << *itlow_set << '\n';
	std::cout << "up : " << *itup_set << '\n';

	std::cout << "\nmysets :\n";
	print_set(mysets);

	std::cout << "equal range test : \n";
	NS::pair<NS::set<int>::iterator, NS::set<int>::iterator> ret_sets;
	ret_sets = mysets.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << *ret_sets.first << " => " << *ret_sets.second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << *ret_sets.first << " => " << *ret_sets.second << '\n';

	std::cout << "\033[31m" << "######## modifiers test ########\n" << "\033[0m\n" << std::endl;

	std::cout << "myset :\n";
	print_set(myset);

	NS::set<int> myset_insert;
	myset_insert.insert((120));
	myset_insert.insert((15));
	myset_insert.insert((28));
	myset_insert.insert((33));
	myset_insert.insert((55));
	myset_insert.insert((99));
	myset_insert.insert((57));
	std::cout << "myset_insert :\n";
	print_set(myset_insert);

	myset.insert(myset_insert.begin(), myset_insert.end());
	std::cout << "myset insert(myset_insert.begin(), myset_insert.end()):\n";
	print_set(myset);


	std::cout << "myset_insert clear :\n";
	myset_insert.clear();
	print_set(myset_insert);


	myset.erase((++(++(++(myset.begin())))));
	myset.erase((--(--(--(myset.end())))));
	myset.erase(33);
	std::cout << "myset :\n";
	print_set(myset);

	std::cout << "reverse iterator myset : " << std::endl;
	NS::set<int>::reverse_iterator rit_set;
	for (rit_set = myset.rbegin(); rit_set != myset.rend(); ++rit_set)
		std::cout << *rit_set << '\n';

	std::cout << "\nmyset.swap(myset_insert)" << std::endl;
	myset.swap(myset_insert);
	std::cout << "myset :\n";
	print_set(myset);

	std::cout << "myset_insert :\n";
	print_set(myset_insert);

	std::cout << "\033[31m" << "######## Relational operator/swap ########\n" << "\033[0m\n" << std::endl;
	NS::set<char> foo_set, bar_set;
	foo_set.insert('a'); 
	foo_set.insert('b'); 
	bar_set.insert('a'); 
	bar_set.insert('z'); 


	if (foo_set==bar_set) std::cout << "\nfoo_set and bar_set are equal\n";
	if (foo_set!=bar_set) std::cout << "foo_set and bar_set are not equal\n";
	if (foo_set< bar_set) std::cout << "foo_set is less than bar_set\n";
	if (foo_set> bar_set) std::cout << "foo_set is greater than bar_set\n";
	if (foo_set<=bar_set) std::cout << "foo_set is less than or equal to bar_set\n";
	if (foo_set>=bar_set) std::cout << "foo_set is greater than or equal to bar_set\n";
	NS::swap(foo_set, bar_set);
	if (foo_set==bar_set) std::cout << "\nfoo_set and bar_set are equal\n";
	if (foo_set!=bar_set) std::cout << "\nfoo_set and bar_set are not equal\n";
	if (foo_set< bar_set) std::cout << "foo_set is less than bar_set\n";
	if (foo_set> bar_set) std::cout << "foo_set is greater than bar_set\n";
	if (foo_set<=bar_set) std::cout << "foo_set is less than or equal to bar_set\n";
	if (foo_set>=bar_set) std::cout << "foo_set is greater than or equal to bar_set\n";
	foo_set = bar_set;
	if (foo_set==bar_set) std::cout << "\nfoo_set and bar_set are equal\n";
	if (foo_set!=bar_set) std::cout << "foo_set and bar_set are not equal\n";
	if (foo_set< bar_set) std::cout << "foo_set is less than bar_set\n";
	if (foo_set> bar_set) std::cout << "foo_set is greater than bar_set\n";
	if (foo_set<=bar_set) std::cout << "foo_set is less than or equal to bar_set\n";
	if (foo_set>=bar_set) std::cout << "foo_set is greater than or equal to bar_set\n";
}

void speed_test()
{
	srand(42);
	NS::map<int, int> mymap;
	for (int i = 0; i < 3000000; i++)
	{
		mymap.insert(NS::make_pair(rand(), i));
	}

	NS::vector<int> myvector;
	for (int i = 0; i < 1000000; i++)
	{
		myvector.push_back(i);
	}

}

int main(int ac, char **av)
{
	(void) av;
	vect_test();
	stack_test();
	map_test();
	set_test();
	if (ac != 1)
		speed_test();
	return (0);
}

