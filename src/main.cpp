//
// Created by pasca on 3/27/2024.
//
#include<iostream>
#include "Merge_sort.h"

using namespace std;

int main(){

    Merge_sort get_merged;

    vector<int> a = {10,32,42,51,321,4213,4,412,321,4,123,4213,23,1};

    get_merged.mergeSort(a);

    for(auto it:a){
        cout << it <<" ";
    }

    return 0;
}