/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:59:38 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/17 14:11:32 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <chrono>
#include <iostream>

class PmergeMe {
	private:
		std::vector<int> dataVec;
		std::deque<int> dataDeq;


		void mergeInsertionSortVector(std::vector<int> &arr);
		void insertionSortVector(std::vector<int>& arr, std::vector<int>::iterator left, std::vector<int>::iterator right);

		double sortAndTimeVector(std::vector<int>& container);

		void displayContainer(const std::string& preamble, const std::vector<int>& container) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseInput(int argc, char **argv);
		void sortAndDisplayResults();
};

#endif