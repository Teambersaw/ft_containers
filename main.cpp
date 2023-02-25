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
//     std::cout << "The contents of both sequSences are equal.\n";
//   else
//     std::cout << "The contents of both sequences differ.\n";

//   return 0;
// }

// using namespace ft;

// int main() {
// 	int tab[] = {1, 2, 3, 3, 3};
// 	int tab2[] = {1, 2, 3, 3, 3};
// 	std::vector<int> v1(tab2, tab2 + 5);
// 	ft::vector<int> v2(tab, tab + 5);

// 	std::cout << "Size: " << v1.size() << "\nCapacity: " << v1.capacity() << std::endl;
// 	v1.reserve(100);
// 	std::cout << "Size: " << v1.size() << "\nCapacity: " << v1.capacity() << std::endl;
// 	std::cout << v1[1] << std::endl;
// 	v1.resize(2);
// 	std::cout << "Size: " << v1.size() << "\nCapacity: " << v1.capacity() << std::endl;
// 	v1.resize(120);
// 	std::cout << "Size: " << v1.size() << "\nCapacity: " << v1.capacity() << std::endl;
// 	std::cout << v1[1] << std::endl;
// 	std::cout << v1[40] << std::endl;
// 	std::cout << "LE MIENS : \n" << std::endl;
// 	std::cout << "Size: " << v2.size() << "\nCapacity: " << v2.capacity() << std::endl;
// 	v2.reserve(100);
// 	std::cout << "Size: " << v2.size() << "\nCapacity: " << v2.capacity() << std::endl;
// 	std::cout << v2[1] << std::endl;
// 	v2.resize(2);
// 	std::cout << "Size: " << v2.size() << "\nCapacity: " << v2.capacity() << std::endl;
// 	v2.resize(120);
// 	std::cout << "Size: " << v2.size() << "\nCapacity: " << v2.capacity() << std::endl;
// 	std::cout << v2[1] << std::endl;
// 	std::cout << v2[40] << std::endl;

//   return 0;
// }

// int main ()
// {
//   ft::vector<int> myvector;
//    std::cout << "size: " << myvector.size() << " capacity: " << myvector.capacity() << std::endl;

//   myvector.push_back (100);
//    std::cout << "size: " << myvector.size() << " capacity: " << myvector.capacity() << std::endl;

//    myvector.push_back (200);
//    std::cout << "size: " << myvector.size() << " capacity: " << myvector.capacity() << std::endl;

//    myvector.push_back (300);
//    std::cout << "size: " << myvector.size() << " capacity: " << myvector.capacity() << std::endl;


//   myvector.pop_back();

//    ft::vector<int>::iterator ite;
//    ite = myvector.end();
//    std::cout << "size: " << myvector.size() << " capacity: " << myvector.capacity() << std::endl;
//    for (ft::vector<int>::iterator it = myvector.begin(); it != ite; it++)
//    	std::cout << "Mon vector a comme valeur: " << *it << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::vector<int> myvector;
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//   std::cout << myvector.size() << "\n";

//   myvector.clear();
//   std::cout << myvector.size() << "\n";
//   myvector.push_back (1101);
//   myvector.push_back (2202);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//   std::cout << myvector.size() << "\n";


//   return 0;
// }

// int main ()
// {
//   std::vector<int> foo (3,100);   // three ints with a value of 100
//   std::vector<int> bar (2,200);   // two ints with a value of 200

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }



// 	template <class T, class Alloc>
// 	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
// 		if (lhs.size() != rhs.size())
// 			return (false);
// 		return (equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
// 	}

// 	template <class T, class Alloc>
// 	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
// 		return (!(lhs == rhs));
// 	}

// 	template <class T, class Alloc>
// 	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
// 		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
// 	}

// 	template <class T, class Alloc>
// 	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
// 		return (!(rhs < lhs));
// 	}

// 	template <class T, class Alloc>
// 	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
// 		return (rhs < lhs);
// 	}

// 	template <class T, class Alloc>
//     bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
// 		return (!(lhs < rhs));
// 	}
// }

// #endif


#include <iostream>
#include <vector>
#include "vector.hpp"
#include "surcharge.hpp"

template<class T>
std::ostream &operator<<(std::ostream &stream, std::vector<T> const &v)
{
	typename std::vector<T>::const_iterator it;

	stream << "[";
	for (it = v.begin(); it != v.end(); it++)
		stream << *it << (it + 1 == v.end() ? "" : ", ");
	stream << "]\n";
	stream << "size of Vct: " << v.size() << "\nCapacity of vct: " << v.capacity() << std::endl;
	return (stream);
}


	// std::cout << myvector.capacity() << std::endl;
  // it = myvector.begin();
  //  myvector.insert ( it , 200 );
  //  std::cout << myvector.capacity() << std::endl;
  // it = myvector.begin();
  //  myvector.insert ( it , 200 );
  //  std::cout << myvector.capacity() << std::endl;
  // it = myvector.begin();
  //  myvector.insert ( it , 200 );
  //  std::cout << myvector.capacity() << std::endl;
  // it = myvector.begin();
  //  myvector.insert ( it , 200 );
  //  std::cout << myvector.capacity() << std::endl;
  // it = myvector.begin();
  //  myvector.insert ( it , 200 );
  //  std::cout << myvector.capacity() << std::endl;
  // myvector.insert (it,16,300);

//  std::cout << myvector.capacity() << std::endl;
//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

// 	std::cout << myvector.capacity() << std::endl;

  
//   int myarray [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ,16 ,17 ,18 ,19 ,20};
//   std::cout << myvector << std::endl;
//   std::cout << "Size: " << myvector.size() << "\nCapacity: " << myvector.capacity() << std::endl;
//   myvector.insert (myvector.begin(), myarray + 3, myarray + 5);
//  myvector.insert (myvector.begin(), myvector.begin(), myvector.end());
// //      myvector.insert (myvector.begin(), myvector.begin(), myvector.end());
//   std::cout << "Size: " << myvector.size() << "\nCapacity: " << myvector.capacity() << std::endl;
//   std::cout << myvector << std::endl;
//   return 0;
// }



// 			// 	for (size_type i = 0; i < dist; i++) {
// 			// 		_alloc.construct(_vector + nb_elem + _size - i - 1, _vector[_size - i - 1]);
// 			// 		_alloc.destroy(_vector + (nb_begin + i - 1));
// 			// 	}
// 			// 	for (size_type i = 0; i < nb_elem; i++) {
// 			// 		_alloc.construct(_vector + (nb_begin + i), *(first++));
// 			// 	}
// 			// 	_size += nb_elem;
// 			// }

// int		main(void)
// {
// // 	ft::vector<int> vct(7)

// // 	for (unsigned long int i = 0; i < vct.size(); ++i)
// // 	{
// // 		vct.at(i) = (vct.size() - i) * 3;
// // 		std::cout << "vct[]: " << vct[i] << std::endl;
// // 	}
// // 	std::cout << vct.size() << '\n';

// // 	ft::vector<int> const vct_c(vct);

// // 	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
// // 	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

// // 	for (unsigned long int i = 0; i < vct_c.size(); ++i)
// // 		std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
// // 	try {
// // 		std::cout << vct_c.at(10) << std::endl;
// // 	}
// // 	catch (std::out_of_range &e) {
// // 		std::cout << "Catch out_of_range exception!" << std::endl;
// // 	}
// // 	catch (std::exception &e) {
// // 		std::cout << "Catch exception: " << e.what() << std::endl;
// // 	}
// // std::cout << vct.size() << '\n';
// }

// int main ()
// {
//   ft::vector<int> myvector (3,100);
//   ft::vector<int>::iterator it;

//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   ft::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// int main() { //PAS MAAAAAAAAAAAAAAL

// 	std::vector<int> vct;
// 	for (int i = 0; i <= 10; i++)
// 		vct.push_back(i);
// 	std::cout << vct << std::endl;

// 	std::cout << "test 1" << std::endl;
// 	vct.erase(vct.begin() + 2);
// 	std::cout << vct << std::endl;

// 	std::cout << "test 2" << std::endl;
// 	vct.erase(vct.begin());
// 	std::cout << vct << std::endl;

// 	std::cout << "test 3" << std::endl;
// 	vct.erase(vct.end() - 1);
// 	std::cout << vct << std::endl;

// 	std::cout << "test 4" << std::endl;
// 	vct.erase(vct.begin(), vct.begin() + 3);
// 	std::cout << vct << std::endl;

// 	std::cout << "test 5" << std::endl;
// 	vct.erase(vct.end() - 3, vct.end() - 1);
// 	std::cout << vct << std::endl;

// 	vct.push_back(15);
// 	vct.push_back(20);

// 	std::cout << "test 6" << std::endl;
// 	vct.erase(vct.end() - 3, vct.end());
// 	std::cout << vct << std::endl;

// 	vct.push_back(21);
// 	vct.push_back(22);
// 	vct.push_back(23);
// 	vct.push_back(24);
// 	std::cout << vct << std::endl;

// 	std::cout << "test 7" << std::endl;
// 	vct.erase(vct.begin(), vct.end());
// 	std::cout << vct << std::endl;
// }

// int		main(void)
// {
// 	const int size = 5;
// 	ft::vector<int> vct(size);
// 	ft::vector<int>::reverse_iterator it = vct.rbegin();
// 	ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

// 	for (int i = 0; i < size; ++i)
// 		it[i] = (size - i) * 5;

// 	it = it + 5;
// 	it = 1 + it;
// 	it = it - 4;
// 	std::cout << *(it += 2) << std::endl;
// 	std::cout << *(it -= 1) << std::endl;

// 	*(it -= 2) = 42;
// 	*(it += 2) = 21;

// 	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

// 	std::cout << "(it == const_it): " << (ite == it) << std::endl;
// 	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
// 	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;
// 	std::cout << vct << std::endl;
// }
#include "stack.hpp"
#include <stack>
int		main(void)
{
	ft::stack<int> stck;

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	stck.push(41);
	stck.push(29);
	stck.push(10);
	stck.push(42);
	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;
	//std::cout << stck << std::endl;

	return (0);
}
