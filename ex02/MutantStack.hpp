/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:42:09 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 17:00:32 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() : std::stack<T, Container>() {}
		MutantStack(const MutantStack<T, Container>& other) : std::stack<T, Container>(other) {}
		MutantStack<T, Container>& operator=(const MutantStack<T, Container>& other) {
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return (*this);
		}
		~MutantStack() {}

		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
};

#endif