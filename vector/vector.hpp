#include <memory>
#include "iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef std::size_t												size_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef pointer 												iterator;
			typedef const_pointer											const_iterator;
			typedef reverse_iterator<iterator>								reverse_iterator;
			typedef reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;

			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _vector(NULL) {}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n) {
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n; i++) {
					_alloc.construct(_vector + i, val);
				}
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n) {
			}

			vector (const vector& x) _alloc(alloc), _capacity(0), _size(0), _vector(NULL) {
				*this = x;
			}

			~vector() {
				_alloc.deallocate(_vector, _capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);

			}

			vector& operator= (const vector& x) {
				if (this == &x)
					return (*this);
				return (*this);
			}

		private:

			allocator_type	_alloc;
			size_type		_capacity;
			size_type		_size;
			pointer			_vector;
	};
}