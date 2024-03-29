#include <chrono>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <unordered_map>
#include "heap_fun.h"
#include "shell_fun.h"
#include "merge_sort.h"
#include "tim_sort.h"

enum
{
	ALGO_HEAP,
	ALGO_SHELL,
	ALGO_MERGE,
	ALGO_TIM,
	ALGO_BUCKET,
	ALGO_RADIX,
	ALGO_DEFAULT,
};

static void generateRealNumbers(std::vector<double>& v, const int N, const int nrMax)
{
	std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_real_distribution<> dis((double)(-nrMax), (double)nrMax);
  for (int i = 0; i < N; i++)
	{
    v[i] =  dis(gen);
	}
}

static void generateNumbers(std::vector<int>& v, const int N, const int nrMax)
{
	std::random_device rd;
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<> distr(0, nrMax); 

  for(int i = 0; i < N; i++)
	{
    v[i] = distr(gen);
	}
}

template<typename T> bool checkResult(std::vector<T>& result, std::unordered_map<T, bool>& orig, const int N)
{
	for(int i = 0; i < N; i++)
	{
		if(orig[result[i]] == false)
			return false;
		orig[result[i]] = false;
	}

	for (const auto & [ key, value ] : orig) 
	{	
		if(value == true)
			return false;
	}

	return true;
}

static void runTest(std::ostream& os, const int N, const int nrMax, const int nrAlgo)
{
	if(nrAlgo > 6)
	{
		os << "Unknown algorithm.";
		return;
	}
	std::vector<int> nrNat(N);
	std::unordered_map<int, bool> nrNatMap;
	std::vector<double> nrReale(N);
	std::unordered_map<double, bool> nrRealeMap;

	generateNumbers(nrNat, N, nrMax);
	for(int i = 0; i < N; i++)
	{
		nrNatMap[nrNat[i]] = true;
	}

	generateRealNumbers(nrReale, N, nrMax);
	for(int i = 0; i < N; i++)
	{
		nrRealeMap[nrReale[i]] = true;
	}

	auto start = std::chrono::steady_clock::now();
	switch(nrAlgo)
	{
		case ALGO_HEAP:
			os<<"Heap sort for natural numbers:\n";
			heapSort(nrNat);
			break;
		case ALGO_SHELL:
			os<<"Shell sort for natural numbers:\n";
			shellSort(nrNat);
			break;
		case ALGO_MERGE:
			os<<"Merge sort for natural numbers:\n";
			mergeSort(nrNat);
			break;
		case ALGO_TIM:
			os<<"Tim sort for natural numbers:\n";
			timSort(nrNat);
			break;
			/*
		case ALGO_BUCKET:
			os<<"Bucket sort for natural numbers:\n";
			bucketSort(nrNat);
			break;
		case ALGO_RADIX:
			os<<"Radix sort for natural numbers:\n";
			radixSort(nrNat);
			break;
			*/
		case ALGO_DEFAULT:
			os<<"Standard library sort for natural numbers: \n";
			std::sort(nrNat.begin(), nrNat.end());
	}
	auto finish = std::chrono::steady_clock::now();
	if(!checkResult(nrNat, nrNatMap, N))
		os<<"!Test esuat!\n\n";
	double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
	os<<elapsed_seconds<<"\n";
	start = std::chrono::steady_clock::now();
	switch(nrAlgo)
	{
		case ALGO_HEAP:
			os<<"Heap sort for real numbers:\n";
			heapSort(nrReale);
			break;
		case ALGO_SHELL:
			os<<"Shell sort for real numbers:\n";
			shellSort(nrReale);
			break;
		case ALGO_MERGE:
			os<<"Merge sort for real numbers:\n";
			mergeSort(nrReale);
			break;
		case ALGO_TIM:
			os<<"Tim sort for real numbers:\n";
			timSort(nrReale);
			break;
			/*
		case ALGO_BUCKET:
			os<<"Bucket sort for real numbers:\n";
			bucketSort(nrReale);
			break;
		case ALGO_RADIX:
			os<<"Radix sort for real numbers:\n";
			radixSort(nrReale);
			break;
			*/
		case ALGO_DEFAULT:
			os<<"Standard library sort for real numbers: \n";
			std::sort(nrReale.begin(), nrReale.end());
	}
	finish = std::chrono::steady_clock::now();
	if(!checkResult(nrReale, nrRealeMap, N))
		os<<"!Test esuat!\n\n";
	elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
	os<< elapsed_seconds<<"\n";
}

void runTests(const char* inputFile, const char* outputFile = NULL, bool generate = true)
{
	std::ifstream in(inputFile);
	std::ofstream out(outputFile);

	int T, N, nrMax;
	if(generate) // asta inseamna ca generam noi valori cand pornim testele
	{
		in >> T;
		for(int i = 0; i < T; i++)		// T e numarul de teste
		{
			in >> N;
			in >> nrMax;
		
			if(outputFile == NULL)
				std::cout<<"Test "<<i<<".	"<<N<<" numere;	"<<nrMax<<" valoarea maxima\n";
			else
				out<<"Test "<<i<<".	"<<N<<" numere;	"<<nrMax<<" valoarea maxima\n";

			for(int j = 0; j < 7; j++)
			{
				if(outputFile != NULL)
					runTest(out, N, nrMax, j);
				else
					runTest(std::cout, N, nrMax, j);
			}
		}
	}
	else // pentru fisiere cu valori pregenerate
	{
		// TO DO
	}
}
