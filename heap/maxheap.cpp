#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class MaxHeap
{
  private:
    T *data;
    int index;
    int capacity;

    void shiftUp(int k)
    {
        while (k > 0 && data[(k - 1) / 2] < data[k])
        {
            swap(data[(k - 1) / 2], data[k]);
            k = (k - 1) / 2;
        }
    }

    void shiftDown(int k)
    {
        while (2 * k + 1 <= index)
        {
            int j = 2 * k + 1;
            if (data[k] >= data[j])
                break;

            if (j + 1 <= index && data[j + 1] > data[j])
                j++;

            swap(data[k], data[j]);
            k = j;
        }
    }

  public:
    MaxHeap(int capacity)
    {
        data = new T[capacity];
        this->capacity = capacity;
        index = -1;
    }
    MaxHeap(T arr[], int n)
    {
        data = new T[n];
        this->capacity = n;
        index = -1;

        for (int i = 0; i < n; i++)
        {
            data[++index] = arr[i];
        }
        //heapify
        for (int i = (index - 1) / 2; i >= 0; i--)
        {
            shiftDown(i);
        }
    }

    ~MaxHeap()
    {
        delete[] data;
    }

    int size()
    {
        return index + 1;
    }

    bool isEmpty()
    {
        return index == -1;
    }

    void insert(T item)
    {
        assert(index + 2 <= capacity);
        data[++index] = item;
        shiftUp(index);
    }

    T removeMax()
    {
        assert(index >= 0);
        T item = data[0];
        swap(data[0], data[index]);
        index--;
        shiftDown(0);
        return item;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    MaxHeap<int> maxheap = MaxHeap<int>(arr, 5);
    // MaxHeap<int> maxheap = MaxHeap<int>(5);
    // srand(time(NULL));
    // for (int i = 0; i < 5; i++)
    //     maxheap.insert(rand() % 100);

    while (!maxheap.isEmpty())
        cout << maxheap.removeMax() << " ";
    cout << endl;
    return 0;
}
