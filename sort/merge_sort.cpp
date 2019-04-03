#include <iostream>

using namespace std;

template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
    T aux[r - l + 1];
    for (int i = l; i <= r; i++)
        aux[i - l] = arr[i];

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r)
        {
            arr[k] = aux[i - l];
            i++;
        }
        else if (aux[i - l] <= aux[j - l])  //<= : stable sort
        {
            arr[k] = aux[i - l];
            i++;
        }
        else
        {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

template <typename T>
void __mergeSort(T arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr, 0, n - 1);
}

template <typename T>
void mergeSortBU(T arr[], int n)
{
    for (int sz = 1; sz <= n; sz += sz)
        // arr[i...i+size-1] arr[i+size...i+size+size-1]
        for (int i = 0; i + sz < n; i += sz + sz)
            __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

// int main()
// {
//     int arr[] = {5, 4, 3, 2, 1, 0};
//     __merge(arr, 0, 0, 1);
//     for (int i = 0; i < 6; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }
