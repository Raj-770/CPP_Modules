/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:20:04 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/17 14:59:34 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : dataVec(other.dataVec), dataDeq(other.dataDeq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		dataDeq = other.dataDeq;
		dataVec = other.dataVec;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::insertionSortVector(std::vector<int>::iterator left, std::vector<int>::iterator right) {
	for (auto i = left + 1; i <= right; ++i) {
		auto key = *i;
		auto j = i - 1;
		while (j >= left && *j > key) {
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = key;
	}
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& arr) {
	if (arr.size() < 2) return;

	auto mid = arr.begin() + arr.size() / 2;
	std::vector<int> leftHalf(arr.begin(), mid);
	std::vector<int> rightHalf(mid, arr.end());

	mergeInsertionSortVector(leftHalf);
	mergeInsertionSortVector(rightHalf);

	std::copy(leftHalf.begin(), leftHalf.end(), arr.begin());
	std::copy(rightHalf.begin(), rightHalf.end(), mid);

	insertionSortVector(arr.begin(), arr.end() - 1);
}

void PmergeMe::insertionSortDeque(std::deque<int>::iterator left, std::deque<int>::iterator right) {
	for (auto i = left + 1; i <= right; ++i) {
		auto key = *i;
		auto j = i - 1;
		while (j >= left && *j > key) {
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = key;
	}
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int>& arr) {
	if (arr.size() < 2) return;

	auto mid = arr.begin() + arr.size() / 2;
	std::deque<int> leftHalf(arr.begin(), mid);
	std::deque<int> rightHalf(mid, arr.end());

	mergeInsertionSortDeque(leftHalf);
	mergeInsertionSortDeque(rightHalf);

	std::copy(leftHalf.begin(), leftHalf.end(), arr.begin());
	std::copy(rightHalf.begin(), rightHalf.end(), mid);

	insertionSortDeque(arr.begin(), arr.end() - 1);
}

double PmergeMe::sortAndTimeVector(std::vector<int>& container) {
	auto start = std::chrono::high_resolution_clock::now();
	mergeInsertionSortVector(container);
	auto end = std::chrono::high_resolution_clock::now();
	return (std::chrono::duration<double, std::micro>(end - start).count());
}

double PmergeMe::sortAndTimeDeque(std::deque<int>& container) {
	auto start = std::chrono::high_resolution_clock::now();
	mergeInsertionSortDeque(container);
	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration<double, std::micro>(end - start).count();
}

void PmergeMe::sortAndDisplayResults() {
	std::cout << "Before: ";
	displayContainer("", dataVec);

	double timeVec = sortAndTimeVector(dataVec) / 1000;
	double timeDeq = sortAndTimeDeque(dataDeq) / 1000;

	std::cout << "After: ";
	displayContainer("", dataVec);
	std::cout << "Time to process a range of " << dataVec.size() << " elements with std::vector: " << timeVec << " us\n";
	std::cout << "Time to process a range of " << dataDeq.size() << " elements with std::deque: " << timeDeq << " us\n";
}

void PmergeMe::displayContainer(const std::string& preamble, const std::vector<int>& container) const {
	std::cout << preamble;
	for (auto num : container) std::cout << num << " ";
	std::cout << "\n";
}

void PmergeMe::parseInput(int argc, char **argv) {
	for (int i = 1; i < argc; ++i)
	{
		int value;
		std::istringstream iss(argv[i]);
		if (!(iss >> value) || value < 0)
		{
			throw std::runtime_error("Error: invalid input");
		}
		dataVec.push_back(value);
	}
}