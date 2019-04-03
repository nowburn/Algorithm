#include <iostream>

using namespace std;

void shellSort(int a[], int n)
{
    for (int d = n / 2; d > 0; d /= 2)
    {
        for (int i = d; i < n; i++)
        {
            int j = i - d;
            int temp = a[i];
            for (; j >= 0 && a[j] > temp; j -= d)
            {
                a[j + d] = a[j];
            }
            a[j + d] = temp;
        }
    }
}

int main()
{
    int a[] = {9, 8, 7, 4, 3, 1};
    shellSort(a, 6);
    for (int x : a)
    {
        cout << x << " ";
    }
    return 0;
}