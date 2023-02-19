


// int main()
// {
// 	pair<int, int> p;
// 	pair<int, int> d(15, 16);
// 	std::cout << p.first << " " << p.second << '\n';
// 	std::cout << std::boolalpha << (p == d) << '\n';
// 	std::cout << std::boolalpha << (p <= d) << '\n';
// 	std::cout << std::boolalpha << (p < d) << '\n';
// 	std::cout << std::boolalpha << (p > d) << '\n';
// 	std::cout << std::boolalpha << (p >= d) << '\n';
// 	std::cout << std::boolalpha << (p != d) << '\n';
// 	pair<int, char> p1 = make_pair(42, 'c');
// 	std::cout << "The value of p1 is " << "(" << p1.first << ", " << p1.second << ")\n";

// 	return 0;
// }

// #include <algorithm>    // std::lexicographical_compare
// #include <cctype>       // std::tolower

// // a case-insensitive comparison function:
// bool mycomp (char c1, char c2)
// { return std::tolower(c1)<std::tolower(c2); }

// int main () {
//   char foo[]="Apple";
//   char bar[]="apartment";

//   std::cout << std::boolalpha;

//   std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

//   std::cout << "Using default comparison (operator<): ";
//   std::cout << lexicographical_compare(foo,foo+5,bar,bar+9);
//   std::cout << '\n';

//   std::cout << "Using mycomp as comparison object: ";
//   std::cout << lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
//   std::cout << '\n';

//   return 0;
// }

// equal algorithm example
// #include <iostream>     // std::cout
// #include <algorithm>    // std::equal
// #include <vector>       // std::vector
// #include "equal.hpp"

// bool mypredicate (int i, int j) {
//   return (i==j);
// }

// int main () {
//   int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
//   std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

//   // using default comparison:
//   if ( ft::equal (myvector.begin(), myvector.end(), myints) )
//     std::cout << "The contents of both sequences are equal.\n";
//   else
//     std::cout << "The contents of both sequences differ.\n";

//   myvector[3]=81;                                 // myvector: 20 40 60 81 100

//   // using predicate comparison:
//   if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
//     std::cout << "The contents of both sequences are equal.\n";
//   else
//     std::cout << "The contents of both sequences differ.\n";

//   return 0;
// }


// int main() {
//   std::cout << std::boolalpha;
//   std::cout << "is_integral:" << std::endl;
//   std::cout << "char: " << is_integral<char>::value << std::endl;
//   std::cout << "int: " << is_integral<int>::value << std::endl;
//   std::cout << "float: " << is_integral<float>::value << std::endl;
//   return 0;
// }

#include <vector>

using namespace ft;
