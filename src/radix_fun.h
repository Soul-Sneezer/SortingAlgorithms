#include <bit>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

template <typename T1, typename T>
void radixSort(std::vector<T>& arr , const int bits) {
  std::queue<T> q_zeros, q_ones;
  const long long N = arr.size();

  for (int j = 0; j < bits; j++) 
  {
    for (long long i = 0; i < N; i++) 
    {
      T1 mask = 1 << j;
      auto val = std::bit_cast<T1>(arr[i]);
      if (arr[i] < 0.0)
      {
        if(bits == 32)
        {
          val ^= 0xFFFFFFFF;
        }
        else if(bits == 64)
        {
          val ^= 0xFFFFFFFFFFFFFFFF;
        }
      }
      else
        val ^= 1 << (bits - 1);
      
      if (val & mask) 
      {
        q_ones.push(arr[i]);
      } 
      else 
      {
        q_zeros.push(arr[i]);
      }
    }

    long long i = 0;
    while (!q_zeros.empty()) {
      arr[i++] = q_zeros.front();
      q_zeros.pop();
    }
    while (!q_ones.empty()) {
      arr[i++] = q_ones.front();
      q_ones.pop();
    }
  }
}
