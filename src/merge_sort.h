//
// Created by pasca on 3/27/2024.
//

#include <vector>

    template<typename T>
    void insertionSort(std::vector<T> &arr, long long left, long long right) {

        for (long long i = left + 1; i <= right; i++) {

            T key = arr[i];
            long long j = i - 1;

            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j + 1] = key;

        }
    }

    template<typename T>
    void merge(std::vector<T> &arr, std::vector<T> &temp, long long left, long long mid, long long right) {

        std::copy(arr.begin() + left, arr.begin() + right + 1, temp.begin() + left);

        long long i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right) {

            if (temp[i] <= temp[j]) {
                arr[k++] = temp[i++];
            } else {
                arr[k++] = temp[j++];
            }
        }

        while (i <= mid) {
            arr[k++] = temp[i++];
        }
    }

    template<typename T>
    void mergeSortUtil(std::vector<T> &arr, std::vector<T> &temp, long long left, long long right) {

        if (left < right) {
            if (right - left <= 10) {
                insertionSort(arr, left, right);
                return;
            }

            long long mid = left + (right - left) / 2;

            mergeSortUtil(arr, temp, left, mid);
            mergeSortUtil(arr, temp, mid + 1, right);

            merge(arr, temp, left, mid, right);
        }
    }

    template<typename T>
    void mergeSort(std::vector<T> &arr) {

        std::vector<T> temp(arr.size());

        mergeSortUtil(arr, temp, 0, arr.size() - 1);
    }
