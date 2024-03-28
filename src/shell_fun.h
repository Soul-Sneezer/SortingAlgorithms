#include <vector>

template <typename T> void shellSort(T arr[], const int N)
{
	for(int gap = N / 2; gap > 0; gap /= 2)
	{	
		for (int i = gap; i < N; i+= 1)
		{
			int c = arr[i];

			int j;
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
	int N = v.size();
	for(int gap = N / 2; gap > 0; gap /= 2)
	{	
		for (int i = gap; i < N; i+= 1)
		{
			int c = v[i];

			int j;
			for (j = i; j >= gap && v[j - gap] > c; j -= gap)
			{
				v[j] = v[j - gap];
			}

			v[j] = c;
		}
	}
}
