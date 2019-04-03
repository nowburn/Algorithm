#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v)
{
    bool sorted = false;
    int size = v.size();
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i && !sorted; j++)
        {
            sorted = true;
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                sorted = false;
            }
        }
    }
}

int main()
{
    vector<int> v = {9, 8, 7, 4, 3, 1};
    bubbleSort(v);
    for (int x : v)
    {
        cout << x << " ";
    }
    return 0;
}