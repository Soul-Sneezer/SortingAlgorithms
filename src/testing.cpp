#include <fstream>
#include "heap_fun.h"
#include "shell_fun.h"

static void generateRealNumbers(const int N, const int nrMax)
{

}

static void generateNumbers(const int N, const int nrMax)
{
}

static void runTest(const int N, const int nrMax, const int nrAlgo)
{
	generateNumbers(N, nrMax);
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
