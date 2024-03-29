#include <vector>

template <typename T> void shellSort(T arr[], const long long N)
{
	for(long long gap = N / 2; gap > 0; gap /= 2)
	{	
		for (long long i = gap; i < N; i+= 1)
		{
			T c = arr[i];

			long long j;
			for (j = i; j >= gap && arr[j - gap] > c; j -= gap)
			{
				arr[j] = arr[j - gap];
			}

			arr[j] = c;
		}
	}
}

template <typename T> void shellSort(std::vector<T>& v)
{
	long long N = v.size();
	for(long long gap = N / 2; gap > 0; gap /= 2)
	{	
		for (long long i = gap; i < N; i+= 1)
		{
			T c = v[i];

			long long j;
			for (j = i; j >= gap && v[j - gap] > c; j -= gap)
			{
				v[j] = v[j - gap];
			}

			v[j] = c;
		}
	}
}
