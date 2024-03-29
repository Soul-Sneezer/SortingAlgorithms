#ifndef SORTINGALGORITHMS_TIM_SORT_H
#define SORTINGALGORITHMS_TIM_SORT_H

#include <algorithm>
#include <vector>
#include <cmath>

template<typename T>
void insertionSort_tim(std::vector<T>& arr, int left, int right) {

    for (int i = left + 1; i <= right; i++) {

        T temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

template<typename T>
void merge_tim(std::vector<T>& arr, int l, int m, int r) {

    int len1 = m - l + 1, len2 = r - m;

    std::vector<T> left(arr.begin() + l, arr.begin() + l + len1);
    std::vector<T> right(arr.begin() + m + 1, arr.begin() + m + 1 + len2);

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k++] = left[i++];
    }

    while (j < len2) {
        arr[k++] = right[j++];
    }
}

template<typename T>
void timSort(std::vector<T>& arr) {

    int n = arr.size();
    int RUN = 32;

    for (int i = 0; i < n; i += RUN) {
        insertionSort_tim(arr, i, std::min(i + RUN - 1, n - 1));
    }

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {\

            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                merge_tim(arr, left, mid, right);
            }
        }
    }
}

#endif //SORTINGALGORITHMS_TIM_SORT_H
