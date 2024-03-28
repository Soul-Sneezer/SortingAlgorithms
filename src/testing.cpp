#include <chrono>
#include <fstream>
#include "heap_fun.h"
#include "shell_fun.h"

// TO DO:
// finish number generation
// properly measure time
// show the results to screen(or a file)

enum
{
	ALGO_HEAP,
	ALGO_SHELL,
	ALGO_MERGE,
	ALGO_TIM,
	ALGO_BUCKET,
	ALGO_RADIX,
}

static double* generateRealNumbers(const int N, const int nrMax)
{
	double* arr = (double*)malloc(N * sizeof(double)); // check if allocation succeded
}

static int* generateNumbers(const int N, const int nrMax)
{
	int result = (int*)malloc(N *  sizeof(int)); // should check if allocation succeded
}

static void runTest(const int N, const int nrMax, const int nrAlgo)
{
	int* arr = generateNumbers(N, nrMax);
	
	switch(nrAlgo)
	{
		case ALGO_HEAP:
			heapSort(arr, N);
			break;
		case ALGO_SHELL:
			shellSort(arr, N);
			break;
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
		default:
			fprintf(stderr, "Unknown algorithm.");
	}

	free(arr);
}

void runTests(int nrAlgo, const char* inputFile, const char* outputFile = stdout, bool generate = true)
{
	ifstream in(inputFile);
	ofstream out(outputFile);

	int T, N, nrMax;
	if(generate) // asta inseamna ca generam noi valori cand pornim testele
	{
		in >> T;
		for(int i = 0; i < T; i++)		// T e numarul de teste
		{
			in >> N;
			in >> nrMax;

			for(int j = 0; j < nrAlgo; j++)
			{
				runTest(N, nrMax, j);
			}
		}
	}
	else // pentru fisiere cu valori pregenerate
	{
	}

	free(buffer);
}
