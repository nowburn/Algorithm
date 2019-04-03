#include <iostream>
#include <ctime>
#include "Student.h"

using namespace std;

template <typename T>
void selectSort(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}

/*
int main()
{
    int a[5] = {5, 1, 2, 3, 0};
    selectSort(a, 5);
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";

    cout << endl;

    float b[5] = {5.1, 1.1, 2.1, 3.1, 0.1};
    selectSort(b, 5);
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";

    cout << endl;

    string c[5] = {"e", "d", "c", "b", "a"};
    selectSort(c, 5);
    for (int i = 0; i < 5; i++)
        cout << c[i] << " ";

    cout << endl;

    Student d[5] = {{"E", 90},
                    {"D", 80},
                    {"C", 98},
                    {"B", 70},
                    {"A", 70}};
    selectSort(d, 5);
    for (int i = 0; i < 5; i++)
        cout << d[i] << " ";
    cout << endl;

    return 0;
}*/