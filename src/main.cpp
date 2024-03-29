//
// Created by pasca on 3/27/2024.
//
#include<iostream>
#include "Merge_sort.h"
#include "Tim_sort.h"

using namespace std;

int main(){

    vector<double> a = {10,32,42,51,321.34,4213,4.2,412,321.36,4.1,123,4213,23,1};

    timSort(a);

    for(auto it:a){
        cout << it <<" ";
    }

    return 0;
}