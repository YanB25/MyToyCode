#ifndef _STL_ITERATOR_TRAIT_
#define _STL_ITERATOR_TRAIT_

#include "stl_debug"
#include <cstddef>
namespace yb {
	//below is about iterator
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <typename T>
	struct iterator_traits {
		typedef typename T::iterator_category iteratory_category;
		typedef typename T::value_type value_type;
		typedef typename T::difference_type difference_type;
		typedef typename T::pointer pointer;
		typedef typename T::reference reference;
	};

	template <typename T>
	struct iterator_traits<T*> {
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
	};

	template <typename T>
	struct iterator_traits<const T*> {
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
	};

	template <typename Iterator>
	inline typename iterator_traits<Iterator>::iterator_category
	iterator_category(const Iterator& ) {
		DEBUG("use func:iterator_category");
		typedef typename iterator_traits<Iterator>::iterator_category category;
		return category();
	}

	template <typename Iterator>
	inline typename iterator_traits<Iterator>::difference_type*
	difference_type(const Iterator& ) {
		DEBUG("ues func:difference_type");
		typedef typename iterator_traits<Iterator>::difference_type* type;
		return type();
	}

	template <typename Iterator>
	inline typename iterator_traits<Iterator>::value_type*
	value_type(const Iterator& ) {
		DEBUG("use func:value_type");
		typedef typename iterator_traits<Iterator>::value_type* value_type;
		return value_type();
	}

	template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T& >
	struct Iterator {
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distance difference_type;
		//typedef Pointer Pointer;
		typedef Reference reference;
	};

	//below is some algorithms for iterator

	//distance
	template <typename InputIterator>
	inline typename iterator_traits<InputIterator>::difference_type
	__distance(InputIterator first, InputIterator last, input_iterator_tag) {
		DEBUG("advance for input_iterator");
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last) {
			++first;
			++n;
		}
		return n;
	}

	template <typename InputIterator>
	inline typename iterator_traits<InputIterator>::difference_type
	__distance(InputIterator first, InputIterator last, random_access_iterator_tag ) {
		DEBUG("distance for random_access_iterator");
		return last - first;
	}

	template <typename InputIterator>
	inline typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last) {
		typedef typename iterator_traits<InputIterator>::iterator_category category;
		return __distance(first, last, category());
	}

	//advance
	template <typename InputIterator, typename Distance>
	inline void __advance(InputIterator& it,  Distance n, input_iterator_tag ) {
		DEBUG("advance for input_iterator");
		if (n < 0) exit(1);
		while (n--) ++it;
	}

	template <typename BidirectionIterator, typename Distance>
	inline void __advance(BidirectionIterator& it, Distance n, bidirectional_iterator_tag ) {
		DEBUG("advance for bidirectional_iterator");
		if (n >= 0) {
			while (n--) ++it;
		} else {
			while (n++) --it;
		}
	}

	template <typename RandomAccessIterator, typename Distance>
	inline void __advance(RandomAccessIterator& it, Distance n, random_access_iterator_tag ) {
		DEBUG("advance for random_access_iterator");
		it += n;
	}

	template <typename InputIterator, typename Distance>
	inline void advance(InputIterator& it, Distance n) {
		__advance(it, n, iterator_category(it));
	} 
}
#endif
