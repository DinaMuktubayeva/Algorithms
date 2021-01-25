#include <iostream>
#include <vector>

/* Sort a vector with the bubble sort algorithm */

void bubbleSort(std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        for (size_t j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
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

    bubbleSort(arr);

    std::cout << "Sorted array:  ";
    print(arr);
}
