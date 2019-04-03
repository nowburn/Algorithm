#include <iostream>
// #include "SortTestHelper.h"

using namespace std;

template <typename T>
void insertSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && e < arr[j-1]; j--)
            arr[j] = arr[j-1];

        arr[j] = e;
    }
}

/*
int main()
{
   
    int n = 10;
    int *a = SortTestHelper ::generateRandomArray(n, 0, n);
    SortTestHelper ::testSort("insertSort", insertSort, a, n);
    delete[] a;

    return 0;
}
*/