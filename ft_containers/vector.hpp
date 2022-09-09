#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
// # include <vector>
# include <exception>

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		private:
			Allocator	_alloc;
			size_t		_count, _cap;
			T*			_head;


		public:
			// CONSTRUCTORS //
			vector() :
				_alloc(0), _count(0), _cap(0), _head(0) {
				return ;
			}

			explicit vector(const Allocator& alloc = Allocator()) :
				_alloc(alloc), _count(0), _cap(0), _head(0) {
				return ;
			}

			explicit vector(T count, const T& value = T(), const Allocator& alloc = Allocator()) :
				_alloc(alloc), _count(count), _cap(count) {
				_head = _alloc.allocate(_count);
				for (size_t i = 0; i < _count; ++i) {
					_alloc.construct(_head + i, value);
				}
				return ;
			}

			template <class InputIt>
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) :
				_alloc(alloc), _count(0), _cap(0), _head(0) {
				return ;
			}

			vector(const vector& other) {
				*this = other;
				return ;
			}

			//	DESTRUCTOR //
			~vector() {
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				return ;
			}

			// ASSIGN OPERATOR //
			vector&	operator=(const vector& other) {
				if (this == &other)
					return (*this);
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				_count = other._count;
				_cap = other._cap;
				_alloc = other._alloc;
				_head = _alloc.allocate(_count);
				for (size_t i = 0; i < _count; ++i) {
					_alloc.construct(_head + i, other[i]);
				}
				return (*this);
			}

			// ASSIGN //
			void	assign(T count, const T& value){
				return ;
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last) {
				return ;
			}

			// ELEMENT ACCESS //
			T& at(T pos) {
				if (pos >= _count)
					throw OutOfRange();
				return (_head[pos]);
			}

			const T& at(T pos) const {
				if (pos >= _count)
					throw OutOfRange();
				return (_head[pos]);
			}

			T&	operator[](T pos) {
				if (pos >= _count)
					throw OutOfBounds();
				return (_head[pos]);
			}

			const T&	operator[](T pos) const {
				if (pos >= _count)
					throw OutOfBounds();
				return (_head[pos]);
			}

			// MODIFIERS

			// EXCEPTIONS
			class OutOfRange: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::vector");
				}
			};

			class OutOfBounds: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::vector[] index out of bounds");
				}
			};

	};
}

#endif