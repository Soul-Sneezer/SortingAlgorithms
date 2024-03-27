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
#include "radix_fun.h"
#include "bucket_sort.h"

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

static void generateRealNumbers(std::vector<float>& v, const long long N, const long long nrMax)
{
	std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_real_distribution<> dis((float)(-nrMax), (float)nrMax);
  
	for (long long i = 0; i < N; i++)
	{
    v[i] =  dis(gen);
	}
}

static void generateNumbers(std::vector<long long>& v, const long long N, const long long nrMax)
{
	std::random_device rd;
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<> distr(0, nrMax); 

  for(long long i = 0; i < N; i++)
	{
    v[i] = distr(gen);
	}
}

template<typename T> bool checkResult(std::vector<T>& orig, std::vector<T>& result, const long long N)
{
	if(result.size() != orig.size())
		return false;

	for(long long i = 1; i < N; i++)
	{
		if(result[i] < result[i - 1])
			return false;
	}

	std::sort(orig.begin(), orig.end());
	return orig == result;

	return true;
}

static void runTest(std::ostream& os, const long long N, const long long nrMax, const int nrAlgo, bool def = false, bool rev = false)
{
	if(nrAlgo > 6)
	{
		os << "Unknown algorithm.";
		return;
	}

	std::vector<long long> nrNat(N);
	std::vector<float> nrReale(N);

	if(!def)
	{
		generateNumbers(nrNat, N, nrMax);
		generateRealNumbers(nrReale, N, nrMax);
	}
	else
	{
		for(long long i = 0; i < N; i++)
		{
			if(!rev)
			{
				nrNat[i] = i + 1;
				nrReale[i] = (float)nrNat[i];
			}
			else
			{
				nrNat[i] = N - i;
				nrReale[i] = (float)nrNat[i];
			}
		}
	}

	std::vector<long long> nrNatCopy= nrNat;
	std::vector<float> nrRealeCopy= nrReale;
	
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
		case ALGO_BUCKET:
			os<<"Bucket sort for natural numbers:\n";
			bucketSort(nrNat);
			break;
		case ALGO_RADIX:
			os<<"Radix sort for natural numbers:\n";
			radixSort<long long, long long>(nrNat, 64);
			break;
		case ALGO_DEFAULT:
			os<<"Standard library sort for natural numbers: \n";
			std::sort(nrNat.begin(), nrNat.end());
	}

	auto finish = std::chrono::steady_clock::now();
	if(!checkResult(nrNatCopy, nrNat, N))
		os<<"!Test esuat!\n\n";
	
	float elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
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
		case ALGO_BUCKET:
			os<<"Bucket sort for real numbers:\n";
			bucketSort(nrReale);
			break;
		case ALGO_RADIX:
			os<<"Radix sort for real numbers:\n";
			radixSort<unsigned int, float>(nrReale, 64);
			break;
		case ALGO_DEFAULT:
			os<<"Standard library sort for real numbers: \n";
			std::sort(nrReale.begin(), nrReale.end());
	}
	
	finish = std::chrono::steady_clock::now();
	if(!checkResult(nrRealeCopy, nrReale, N))
		os<<"!Test esuat!\n\n";
	
	elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<float>>(finish - start).count();
	os<< elapsed_seconds<<"\n";
}

void runTests(const char* inputFile, const char* outputFile = NULL, bool generate = true)
{
	std::ifstream in(inputFile);
	std::ofstream out(outputFile);

	long long T, N, nrMax;
	if(generate) // asta inseamna ca generam noi valori cand pornim testele
	{
		in >> T;
		for(long long i = 0; i < T; i++)		// T e numarul de teste
		{
			in >> N;
			in >> nrMax;
		
			if(outputFile == NULL)
				std::cout<<"Test "<<i<<".	"<<N<<" numbers;	"<<nrMax<<" maximum value\n";
			else
				out<<"Test "<<i<<".	"<<N<<" numbers;	"<<nrMax<<" maximum value\n";

			for(int j = 0; j < 7; j++)
			{
				if(outputFile != NULL)
					runTest(out, N, nrMax, j);
				else
					runTest(std::cout, N, nrMax, j);
			}
		}

		if(outputFile == NULL)
			std::cout<<"Test for an already sorted list. "<<N<<" numbers\n";
		else
			out<<"Test for an already sorted list. "<<N<<" numbers\n";

		for(int j = 0; j < 7; j++)
		{
			if(outputFile != NULL)
				runTest(out, N, nrMax, j, true);
			else
				runTest(std::cout, N, nrMax, j, true);
		}

		if(outputFile == NULL)
			std::cout<<"Test for a list that is already sorted in reverse order. "<<N<<" numbers\n";
		else
			out<<"Test for a list that is already sorted in reverse order. "<<N<<" numbers\n";

		for(int j = 0; j < 7; j++)
		{
			if(outputFile != NULL)
				runTest(out, N, nrMax, j, true, true);
			else
				runTest(std::cout, N, nrMax, j, true, true);
		}
	}
	else // pentru fisiere cu valori pregenerate
	{
		// TO DO
	}
}
