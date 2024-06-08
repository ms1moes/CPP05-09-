#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <iomanip>

void parser(char **av);

void showVector();
void showDeque();

void ft_sort(char **av);

void mergeVector(std::vector<int> &arr, int left, int mid, int right);
void mergeDeque(std::deque<int> &arr, int left, int mid, int right);

void insertionSortVector(std::vector<int> &arr, int left, int right);
void insertionSortDeque(std::deque<int> &arr, int left, int right);

void mergeSortVector(std::vector<int> &arr);
void mergeSortDeque(std::deque<int> &arr);

#endif