#include <iostream>
#include "SortTestHelper.h"
#include "select_sort.cpp"
#include "insert_sort.cpp"
#include "merge_sort.cpp"
#include "quick_sort.cpp"
#include "heap_sort.cpp"

using namespace std;

int main()
{
    int n = 10000;
    int *a = SortTestHelper ::generateRandomArray(n, 0, n);
    // int *a = SortTestHelper ::generateNearlyOrderArray(n, 10);
    int *b = SortTestHelper ::copyIntArray(a, n);
    int *c = SortTestHelper ::copyIntArray(a, n);
    int *d = SortTestHelper ::copyIntArray(a, n);
    int *e = SortTestHelper ::copyIntArray(a, n);

    SortTestHelper ::testSort("selectSort", selectSort, a, n);
    SortTestHelper ::testSort("insertSort", insertSort, b, n);
    SortTestHelper ::testSort("mergeSort", mergeSort, c, n);
    SortTestHelper ::testSort("quickSort", quickSort, d, n);
    SortTestHelper ::testSort("heapSort", heapSort, e, n);

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;
    delete[] e;

    return 0;
}