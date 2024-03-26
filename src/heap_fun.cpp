#include<vector>

static void heapify(int arr[], const int N, const int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;

	if (l < N && arr[l] > arr[largest])
	{
		largest = l;
	}

	if(r < N && arr[r] > arr[largest])
	{
		largest = r;
	}
	
	if(largest != i)
	{
		std::swap(arr[largest], arr[i]);
		heapify(arr, N, largest);
	}

}

static void heapify(std::vector<int>& v, const int N, const int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;

	if (l < N && v[l] > v[largest])
	{
		largest = l;
	}

	if(r < N && v[r] > v[largest])
	{
		largest = r;
	}
	
	if(largest != i)
	{
		std::swap(v[largest], v[i]);
		heapify(v, N, largest);
	}
}

void heapSort(int arr[], const int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		heapify(arr, N, i);
	}
	for (int i = N - 1; i > 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void heapSort(std::vector<int>& v)
{
	int N = v.size();
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		heapify(v, N, i);
	}

	for (int i = N - 1; i > 0; i--)
	{
		std::swap(v[0], v[i]);
		heapify(v, i, 0);
	}
}
