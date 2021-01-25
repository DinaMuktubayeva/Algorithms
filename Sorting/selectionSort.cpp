#include <iostream>
#include <vector>

/* Sort a vector with the selection sort algorithm */

void selectionSort(std::vector<int> &arr)
{
  for (size_t i = 0; i < arr.size() - 1; i++)
  {
    int min = i; // index of the smallest element

    for (size_t j = i + 1; j < arr.size(); j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }

    if (i != min)
      std::swap(arr[min], arr[i]);
  }
}

void print(std::vector<int> &arr)
{
  for (size_t i = 0; i < arr.size(); ++i)
    std::cout << arr[i] << ' ';

  std::cout << '\n';
}

int main()
{
  std::vector<int> arr;

  int n = 10;

  for (size_t i = 0; i < n; ++i)
  {
    int r = rand() % 10 + 1;
    arr.push_back(r);
  }

  std::cout << "Initial array: ";
  print(arr);

  selectionSort(arr);

  std::cout << "Sorted array:  ";
  print(arr);
}
