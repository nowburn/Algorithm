#include <iostream>

using namespace std;

template <typename T>
void __quickSort3ways(T arr[], int l, int r)
{
    if (l >= r)
        return;

    int pos = rand() % (r - l + 1) + l;
    swap(arr[l], arr[pos]);

    T v = arr[l];
    int i = l+1;                //arr[lt+1...i] == v
    int lt = l, gt = r+1;       //arr[l+1...lt] <  v  , arr[gt...r] > v
    while (i < gt)
    {
        if (arr[i] < v)
        {
            swap(arr[++lt], arr[i]);
            i++;
        }
        else if (arr[i] > v)
        {
            swap(arr[--gt], arr[i]);
        }
        else
        {
            i++;
        }
    }
    swap(arr[l], arr[lt]);
    __quickSort3ways(arr, l, lt);
    __quickSort3ways(arr, gt, r);
}

template <typename T>
void quickSort(T arr[], int n)
{
    srand(time(NULL));
    __quickSort3ways(arr, 0, n - 1);
}

// int main()
// {
    // int arr[] = {5, 4, 3, 2, 1};
    // quickSort(arr, 5);
    // for (int i = 0; i < 5; i++)
    // {
        // cout << arr[i] << " ";
    // }
    // cout << endl;
    // return 0;
// }
