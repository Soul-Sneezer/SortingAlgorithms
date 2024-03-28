//
// Created by pasca on 3/27/2024.
//

#ifndef SORTINGALGORITHMS_MERGE_SORT_H
#define SORTINGALGORITHMS_MERGE_SORT_H


#include <vector>

class Merge_sort {
public:
    void insertionSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right);
    void mergeSortUtil(std::vector<int>& arr, std::vector<int>& temp, int left, int right);
    void mergeSort(std::vector<int>& arr);
};


#endif //SORTINGALGORITHMS_MERGE_SORT_H
