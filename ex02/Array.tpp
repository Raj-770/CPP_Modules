/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:32:21 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 17:48:20 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : _array(NULL), _size(0) {
	if (other._size > 0) {
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] _array;
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator[](unsigned int index) {
	if (index >= size)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() {
	return (_size);
}