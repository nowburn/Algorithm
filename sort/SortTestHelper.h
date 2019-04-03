#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper
{

int *generateRandomArray(int n, int l, int r)
{
    assert(l <= r);
    int *arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (r - l + 1) + l;
    }
    return arr;
}
int *generateNearlyOrderArray(int n, int swapTimes)
{
    assert(n > 0);
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < swapTimes; i++)
    {
        int pos1 = rand() % n;
        int pos2 = rand() % n;
        swap(arr[pos1], arr[pos2]);
    }

    return arr;
}

template <typename T>
void printArray(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

template <typename T>
bool isSorted(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

template <typename T>
void testSort(string sortName, void (*sort)(T[], int), T arr[], int n)
{
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();

    assert(isSorted(arr, n));
    cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    cout << endl;
    return;
}

int *copyIntArray(int arr[], int n)
{
    int *a = new int[n];
    copy(arr, arr + n, a);
    return a;
}

} // namespace SortTestHelper