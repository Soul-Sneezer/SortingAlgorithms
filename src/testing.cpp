#include <chrono>
#include <iostream>
#include <fstream>
#include <random>
#include "heap_fun.h"
#include "shell_fun.h"

enum
{
	ALGO_HEAP,
	ALGO_SHELL,
	ALGO_MERGE,
	ALGO_TIM,
	ALGO_BUCKET,
	ALGO_RADIX,
};

static double* generateRealNumbers(const int N, const int nrMax)
{
	double* arr = (double*)malloc(N * sizeof(double)); // check if allocation succeded
	
	std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_real_distribution<> dis(0.0, (double)nrMax);
  for (int i = 0; i < N; i++)
    arr[i] =  dis(gen);

	return arr;
}

static int* generateNumbers(const int N, const int nrMax)
{
	int* arr = (int*)malloc(N *  sizeof(int)); // should check if allocation succeded

	std::random_device rd;
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<> distr(0, nrMax); 

  for(int i = 0; i < N; i++)
    arr[i] = distr(gen);

	return arr;
}

void checkResult()
{

}

static void runTest(std::ostream& os, const int N, const int nrMax, const int nrAlgo)
{
	if(nrAlgo > 5)
	{
		os << "Unknown algorithm.";
		return;
	}

	int* arr = generateNumbers(N, nrMax);
	double* realArr = generateRealNumbers(N, nrMax);

	auto start = std::chrono::steady_clock::now();
	switch(nrAlgo)
	{
		case ALGO_HEAP:
			heapSort(arr, N);
			break;
		case ALGO_SHELL:
			shellSort(arr, N);
			break;
			/*
		case ALGO_MERGE:
			mergeSort(arr, N);
			break;
		case ALGO_TIM:
			timSort(arr, N);
			break;
		case ALGO_BUCKET:
			bucketSort(arr, N);
			break;
		case ALGO_RADIX:
			radixSort(arr, N);
			break;
			*/
	}
	checkResult();
	auto finish = std::chrono::steady_clock::now();
	double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
	os<<elapsed_seconds<<"\n";
	start = std::chrono::steady_clock::now();
	switch(nrAlgo)
	{
		case ALGO_HEAP:
			heapSort(arr, N);
			break;
		case ALGO_SHELL:
			shellSort(arr, N);
			break;
			/*
		case ALGO_MERGE:
			mergeSort(arr, N);
			break;
		case ALGO_TIM:
			timSort(arr, N);
			break;
		case ALGO_BUCKET:
			bucketSort(arr, N);
			break;
		case ALGO_RADIX:
			radixSort(arr, N);
			break;
			*/
	}
	checkResult();
	finish = std::chrono::steady_clock::now();
	elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
	os<< elapsed_seconds<<"\n";
	free(arr);
	free(realArr);
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

			for(int j = 0; j < 6; j++)
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
	}
}
