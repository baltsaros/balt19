#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "rbtree_iterator.hpp"
# include "map.hpp"
# define BLACK	false
# define RED	true

// colors: 0/false - Black; 1/true - Red

namespace ft {

	template <class Pair>
	struct Node {
		typedef	const Node	const_Node;

		Pair		value;
		bool		color;
		size_t		level;
		Node<Pair>	*left;
		Node<Pair>	*right;
		Node<Pair>	*parent;

		Node(Node *parent) : color(BLACK), level(0),
			parent(parent), left(nullptr), right(nullptr) {}

		Node(Pair v, bool c, size_t lvl, Node *p, Node *l, Node *r) :
			value(v), color(c), level(lvl), parent(p), left(l), right(r) {}

	};

	template <class Key,
				class Pair,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<Pair> >
	class RBTree {
		public:
		// TYPEDEFS
			typedef Key						key_type;
			typedef Pair					value_type;
			typedef std::size_t				size_type;
			typedef std::ptrdiff_t			difference_type;
			typedef Compare					key_compare;
			typedef Allocator				allocator_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef Node<Pair>				node;

			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename Allocator::template rebind<Node<value_type> >::other	alloc_node;
			
			typedef rbt_iterator<Pair>						iterator;
			typedef rbt_const_iterator<Pair>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			node			*_root;
			node			*_nil;
			allocator_type	_alloc;
			alloc_node		_node_alloc;
			size_type		_size;
			key_compare		_comp;

		public:
			explicit RBTree(key_compare const &comp = key_compare(),
				allocator_type const &alloc = allocator_type()) :
				_alloc(alloc), _node_alloc(alloc), _size(0), _comp(comp) {
				// std::cout << "constructor 1" << std::endl;
				_root = nullptr;
				_nil = _node_alloc.allocate(1);
				_node_alloc.construct(_nil, node(_root));
				_root = _nil;
			}

			RBTree(RBTree const &src) :
				_alloc(src._alloc), _node_alloc(src._alloc), _size(0), _comp(src._comp) {
				*this = src;
			}

			RBTree&	operator=(RBTree const &src) {
				if (this == &src)
					return (*this);
				_alloc = src._alloc;
				_node_alloc = src._node_alloc;
				_comp = src._comp;
				if (_root)
					clear();
				_root = nullptr;
				if (src._root && src._root != src._nil)
					copyTree(src._root, src._nil);
				else if (src._root == src._nil)
					_root = _nil;
				return (*this);
			}

			virtual ~RBTree() {
				// std::cout << "destructor\n";
				clear();
				_node_alloc.destroy(_nil);
				_node_alloc.deallocate(_nil, 1);
				_nil = nullptr;
			}

			void	copyTree(node *root, node *nil) {
				if (!_root) {
					node	*child;

					child = _node_alloc.allocate(1);
					_node_alloc.construct(child, node(root->value, root->color, root->level, _nil, _nil, _nil));
					_root = child;
					_nil->parent = _root;
					_size++;
				}
				else {
					node	*child;
					node	*head = _root;
					node	*parent = _nil;

					child = _node_alloc.allocate(1);
					_node_alloc.construct(child, node(root->value, root->color, root->level, nullptr, _nil, _nil));

					while (head != _nil)
					{
						parent = head;
						if (_comp(child->value.first, head->value.first))
							head = head->left;
						else
							head = head->right;
					}
					child->parent = parent;
					if (_comp(child->value.first, parent->value.first))
						parent->left = child;
					else
						parent->right = child;
					_size++;
				}
				if (root && root->left && root->left != nil)
					copyTree(root->left, nil);
				if (root && root->right && root->right != nil)
					copyTree(root->right, nil);
			}


			void	insertFixup(node *child) {
				node	*uncle;

				if (child == _root || child->parent == _root)
					return ;
				while (child != _root && child->parent->color) {
					if (child->parent == child->parent->parent->left) {
						uncle = child->parent->parent->right;
						if (uncle != _nil && uncle->color) {
							child->parent->color = BLACK;
							uncle->color = BLACK;
							child->parent->parent->color = RED;
							child = child->parent->parent;
						}
						else {
							if (child == child->parent->right) {
								child = child->parent;
								leftRotation(child);
							}
							child->parent->color = BLACK;
							child->parent->parent->color = RED;
							rightRotation(child->parent->parent);
						} 
					}
					else {
						uncle = child->parent->parent->left;
						if (uncle != _nil && uncle->color) {
							child->parent->color = BLACK;
							uncle->color = BLACK;
							child->parent->parent->color = RED;
							child = child->parent->parent;
						}
						else {
							if (child == child->parent->left) {
								child = child->parent;
								rightRotation(child);
							}
							child->parent->color = BLACK;
							child->parent->parent->color = RED;
							leftRotation(child->parent->parent);
						}
					}
				}
				_root->color = BLACK;
				_nil->parent = _root;
			}

			void	deleteAll(node *tmp) {
				if (tmp == _nil || !tmp)
					return ;
				if (tmp->left != _nil)
					deleteAll(tmp->left);
				if (tmp->right != _nil)
					deleteAll(tmp->right);
				_node_alloc.destroy(tmp);
				_node_alloc.deallocate(tmp, 1);
				_size--;
				tmp = nullptr;
			}

			void	deleteOne(node *toDelete)
			{
				node	*y, *x, *tmp;
				bool	y_color;

				y = toDelete;
				if (toDelete == _nil)
					return ;
				y_color = y->color;
				if (y->left == _nil) {
					x = y->right;
					transplant(y, y->right);
				}
				else if (y->right == _nil) {
					x = y->left;
					transplant(y, y->left);
				}
				else {
					tmp = y;
					y = findMin(tmp->right);
					y_color = y->color;
					x = y->right;
					if (y->parent != tmp) {
						transplant(y, y->right);
						y->right = tmp->right;
						tmp->right->parent = y;
					}
					transplant(tmp, y);
					y->left = tmp->left;
					y->left->parent = y;
					y->color = tmp->color;
				}
				// std::cout << "to delete2: " << toDelete->key << "\n";
				_node_alloc.destroy(toDelete);
				_node_alloc.deallocate(toDelete, 1);
				_size--;
				if (!y_color)
					deleteFixup(x);
				_nil->parent = _root;
			}

			void	deleteFixup(node *x) {
				node	*w;

				while (x != _root && !x->color) {
					if (x == x->parent->left) {
						w = x->parent->right;
						if (w->color) {
							w->color = BLACK;
							x->parent->color = RED;
							leftRotation(x->parent);
							w = x->parent->right;
						}
						if (!w->left->color && !w->right->color) {
							w->color = RED;
							x = x->parent;
						}
						else {
							if (!w->right->color) {
								w->left->color = BLACK;
								w->color = RED;
								rightRotation(w);
								w = x->parent->right;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right->color = BLACK;
							leftRotation(x->parent);
							x = _root;
						}
					}
					else {
						w = x->parent->left;
						if (w->color) {
							w->color = BLACK;
							x->parent->color = RED;
							rightRotation(x->parent);
							w = x->parent->left;
						}
						if (!w->right->color && !w->left->color) {
							w->color = RED;
							x = x->parent;
						}
						else {
							if (!w->left->color) {
								w->right->color = BLACK;
								w->color = RED;
								leftRotation(w);
								w = x->parent->left;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							rightRotation(x->parent);
							x = _root;
						}
					}
				}
			}

			void	rightRotation(node *x) {
				node	*y;

				// std::cout << "right rotation\n";
				y = x->left;
				x->left = y->right;
				if (y->right != _nil)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == _nil)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->right = x;
				x->parent = y;
			}

			void	leftRotation(node *x) {
				node	*y;

				// std::cout << "left rotation\n";
				y = x->right;
				x->right = y->left;
				if (y->left != _nil)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == _nil)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}


			node*	search(node *tmp, const value_type& key) const {
				if (!tmp || tmp == _nil || tmp->value.first == key.first)
					return (tmp);
				if (_comp(tmp->value.first, key.first))
					return search(tmp->right, key);
				else
					return search(tmp->left, key);
			}

			void	transplant(node *u, node *v) {
				// std::cout << "transplanting\n";
				if (u->parent == _nil)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
				_nil->parent = _root;
			}

			node*	findMin(node *tmp) const {
				if (!tmp || tmp == _nil)
					return (tmp);
				while (tmp->left != _nil)
					tmp = tmp->left;
				return (tmp);
			}

			node*	findMax(node *tmp) const {
				if (!tmp || tmp == _nil)
					return (tmp);
				while (tmp->right != _nil)
					tmp = tmp->right;
				return (tmp);
			}

			void	printNode() {
				int	level = 0;
				node	*tmp;

				if (!_root) {
					std::cout << "The tree does not exist!\n";
					return ;
				}
				fixLevels(_root, level);
				printNode(_root);
				tmp = findMin(_root);
				std::cout << "min: " << tmp->key << "\n";
				tmp = findMax(_root);
				std::cout << "max: " << tmp->key << "\n";
			}

			void	fixLevels(node *tmp, int lvl) {
				tmp->level = lvl;
				++lvl;
				if (tmp->left != _nil)
					fixLevels(tmp->left, lvl);
				if (tmp->right != _nil)
					fixLevels(tmp->right, lvl);
			}

			void	printNode(node *tmp) {
				std::cout.width(15); 
				std::cout << "root key: " << tmp->value.first << " | value: " << tmp->value.second;
				std::cout.width(10); 
				std::cout << " | color: " << tmp->color << " | level: " << tmp->level << "\n";
				if (tmp->left != _nil) {
					std::cout.width(15);
					std::cout << "left key: " << tmp->left->value.first<< " | value: " << tmp->left->value.second;
					std::cout.width(10);
					std::cout << " | color: " << tmp->left->color << " | level: " << tmp->left->level << "\n";
				}
				if (tmp->right != _nil) {
					std::cout.width(15);
					std::cout << "right key: " << tmp->right->value.first << " | value: " << tmp->right->value.second;
					std::cout.width(10);
					std::cout << " | color: " << tmp->right->color << " | level: " << tmp->right->level << "\n";
				}
				if (tmp->left != _nil)
					printNode(tmp->left);
				if (tmp->right != _nil)
					printNode(tmp->right);
			}

			// ITERATORS
			iterator	begin() {
				return (iterator(findMin(_root)));
			}

			const_iterator	begin() const {
				return (const_iterator(findMin(_root)));
			}

			iterator	end() {
				return (iterator(_nil));
			}

			const_iterator	end() const {
				return (const_iterator(_nil));
			}

			reverse_iterator	rbegin() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(end()));
			}

			reverse_iterator	rend() {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rend() const {
				return (const_reverse_iterator(begin()));
			}

			// CAPACITY
			bool	empty() const {
				return (!_size);
			}

			size_type	size() const {
				return (_size);
			}

			size_type	max_size() const {
				return (_node_alloc.max_size());
			}

			pair<iterator, bool>	create_root(const value_type& value) {
					node					*child;
					pair<iterator, bool>	ret;

					child = _node_alloc.allocate(1);
					_node_alloc.construct(child, node(value, BLACK, 0, _nil, _nil, _nil));
					_root = child;
					_nil->parent = _root;
					_size++;
					ret = ft::make_pair(iterator(child), true);
					return (ret);
			}

			// MODIFIERS
			pair<iterator, bool>	insert(const value_type& value) {
				if (!_root || _root == _nil)
					return (create_root(value));

				node					*child;
				node					*head = _root;
				node					*parent = _nil;
				node					*tmp;
				pair<iterator, bool>	ret;

				tmp = search(value);
				if (tmp != _nil) {
					ret = ft::make_pair(iterator(tmp), false);
					return (ret);
				}
				child = _node_alloc.allocate(1);
				_node_alloc.construct(child, node(value, RED, 0, nullptr, _nil, _nil));

				while (head != _nil)
				{
					parent = head;
					if (_comp(child->value.first, head->value.first))
						head = head->left;
					else
						head = head->right;
					child->level++;
				}
				child->parent = parent;
				if (_comp(child->value.first, parent->value.first))
					parent->left = child;
				else
					parent->right = child;
				_size++;
				insertFixup(child);
				ret = ft::make_pair(iterator(child), true);
				return (ret);
			}

			iterator	insert(iterator pos, const value_type& value) {
				(void)pos;
				if (!_root || _root == _nil)
					return (create_root(value).first);

				node	*child;
				node	*head = _root;
				node	*parent = _nil;
				node	*tmp;

				tmp = search(value);
				if (tmp != _nil)
					return (iterator(tmp));
				child = _node_alloc.allocate(1);
				_node_alloc.construct(child, node(value, RED, 0, nullptr, _nil, _nil));

				while (head != _nil)
				{
					parent = head;
					if (_comp(child->value.first, head->value.first))
						head = head->left;
					else
						head = head->right;
					child->level++;
				}
				child->parent = parent;
				if (_comp(child->value.first, parent->value.first))
					parent->left = child;
				else
					parent->right = child;
				_size++;
				insertFixup(child);
				return (iterator(child));
			}

			template <class InputIt>
			void	insert(InputIt first, InputIt last) {
				for (; first != last; ++first)
					insert(*first);
			}

			void	erase(iterator pos) {
				node	*tmp = pos.base();

				if (!tmp || tmp == _nil)
					return ;
				deleteOne(tmp);
			}

			void	erase(iterator first, iterator last) {
				for (; first != last; first++)
					erase(first);
			}
			
			bool	erase(const value_type& key) {
				node	*tmp = _root;

				tmp = search(key);
				if (!tmp || tmp == _nil)
					return (false);
				deleteOne(tmp);
				return (true);
			}

			void	clear() {
				if (_root == _nil)
					return ;
				deleteAll(_root);
				_root = nullptr;
			}

			void	swap(RBTree& other) {
				RBTree	tmp;

				tmp = *this;
				*this = other;
				other = tmp;
			}

			// LOOKUPS
			size_type	count(const value_type& key) const {
				node	*tmp = search(key);

				if (!tmp || tmp == _nil)
					return (false);
				return (true);
			}

			iterator	find(const value_type& key) {
				node	*tmp = search(key);

				return (iterator(tmp));
			}

			const_iterator	find(const value_type& key) const {
				node	*tmp = search(key);

				return (const_iterator(tmp));
			}

			pair<iterator, iterator>	equal_range(const value_type& key) {
				pair<iterator, iterator>	ret;

				ret = ft::make_pair(lower_bound(key), upper_bound(key));
				return (ret);
			}

			pair<const_iterator, const_iterator>	equal_range(const value_type& key) const {
				pair<const_iterator, const_iterator>	ret;

				ret = ft::make_pair(lower_bound(key), upper_bound(key));
				return (ret);
			}

			iterator	lower_bound(const value_type& key) {
				iterator	last = end();

				for (iterator head = begin(); head != last; ++head) {
					if (!_comp(head->first, key.first))
						return (head);
				}
				return (last);
			}

			const_iterator	lower_bound(const value_type& key) const {
				const_iterator	last = end();

				for (const_iterator head = begin(); head != last; ++head) {
					if (!_comp(head->first, key.first))
						return (head);
				}
				return (last);
			}

			iterator	upper_bound(const value_type& key) {
				iterator	last = end();

				for (iterator head = begin(); head != last; ++head) {
					if (_comp(key.first, head->first)) {
						head++;
						return (head);
					}
				}
				return (last);
			}

			const_iterator	upper_bound(const value_type& key) const {
				const_iterator	last = end();

				for (const_iterator head = begin(); head != last; ++head) {
					if (_comp(key.first, head->first)) {
						head++;
						return (head);
					}
				}
				return (last);
			}

			node*	search(const value_type& key) const {
				node	*tmp = nullptr;

				tmp = search(_root, key);
				return (tmp);
			}

			// OBSERVER
			key_compare	key_comp() const {
				return (_comp);
			}

			bool	test() {
				return (_comp(_root->value.first, _root->left->value.first));
			}

			// COMPARISON OPERATORS
			friend bool	operator==(const RBTree& lhs, const RBTree& rhs) {
				if (lhs.size() != rhs.size())
					return (false);
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			friend bool	operator<(const RBTree& lhs, const RBTree& rhs) {
				if (lhs.size() != rhs.size())
					return (false);
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}
	};
};

#endif