#pragma once
#ifndef DARRAY_H_
#define DARRAY_H_

#include <stdio.h>
#include <new>

namespace ary
{
	template<class _Ty> // for more type a array
	class dynamic_array
	{
	private:
		_Ty* array; // Dynamic array
		size_t size_array; // uint32 for size was never < 0;
	public:
		dynamic_array() noexcept : array(nullptr), size_array(0) {};
		explicit dynamic_array(size_t _size);
		dynamic_array(const dynamic_array& d);
		~dynamic_array() noexcept;

		// methodes;
		bool is_empty();
		int size();

		_Ty& operator[](size_t index); // for give elament [index]
		_Ty& operator[](size_t index) const; // for give elament [index] const

		dynamic_array& operator=(const dynamic_array& d);
	};
}
#endif //!DARRAY_H_

using ary::dynamic_array;

template<class _Ty>
inline dynamic_array<_Ty>::dynamic_array(size_t _size)
{
	try {
		size_array = _size;
		array = new _Ty[size_array]; // Memory allocation for Array
	}
	catch (const std::bad_alloc& ex) {
		printf("%s ", ex.what());
	}
}

template<class _Ty>
inline dynamic_array<_Ty>::dynamic_array(const dynamic_array& d)
{
	array = d.array;
	size_array = d.size_array;
}

template<class _Ty>
inline dynamic_array<_Ty>::~dynamic_array() noexcept {
	delete[] array;
}

template<class _Ty>
inline bool ary::dynamic_array<_Ty>::is_empty()
{
	if (size_array == 0)
		return true;
	else
		return false;
}

template<class _Ty>
inline int ary::dynamic_array<_Ty>::size() {
	return size_array;
}

template<class _Ty>
inline _Ty& dynamic_array<_Ty>::operator[](size_t index) {
	return array[index];
}

template<class _Ty>
inline _Ty& dynamic_array<_Ty>::operator[](size_t index) const {
	return array[index];
}

template<class _Ty>
inline dynamic_array<_Ty>& ary::dynamic_array<_Ty>::operator=(const dynamic_array& d)
{
	if (this == &d)
		return *this;
	delete[] array;
	size_array = d.size_array;
	array = new _Ty[size_array];
	array = d.array;
	return *this;
}