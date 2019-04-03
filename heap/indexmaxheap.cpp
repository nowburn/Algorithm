#include <iostream>
#include <cassert>

using namespace std;

/*
实现了一个最大索引堆,
可应用于(1)优先队列 (2)n个元素选出前m个大的数 (3)多路归并
时间复杂度：插入，删除，修改 O(logn)
          查询           O(1)
*/

template <typename T>
class IndexMaxHeap
{
  private:
    T *data;
    int *indexes;
    int *reverse;
    int index;
    int capacity;

    void shiftUp(int k)
    {
        while (k > 0 && data[indexes[(k - 1) / 2]] < data[indexes[k]])
        {
            swap(indexes[(k - 1) / 2], indexes[k]);
            reverse[(indexes[(k - 1) / 2])] = (k - 1) / 2;
            reverse[indexes[k]] = k;
            k = (k - 1) / 2;
        }
    }

    void shiftDown(int k)
    {
        while (2 * k + 1 <= index)
        {
            int j = 2 * k + 1;
            if (data[indexes[k]] >= data[indexes[j]])
                break;

            if (j + 1 <= index && data[indexes[j + 1]] > data[indexes[j]])
                j++;

            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

  public:
    IndexMaxHeap(int capacity)
    {
        data = new T[capacity];
        indexes = new T[capacity];
        reverse = new T[capacity];
        for (int i = 0; i <= capacity; i++)
            reverse[i] = -1;
        this->capacity = capacity;
        index = -1;
    }

    ~IndexMaxHeap()
    {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size()
    {
        return index + 1;
    }

    bool isEmpty()
    {
        return index == -1;
    }

    void insert(int i, T item)
    {
        assert(index + 2 <= capacity);
        data[i] = item;
        indexes[++index] = i;
        reverse[i] = index;
        shiftUp(index);
    }

    T removeMax()
    {
        assert(index >= 0);
        T item = data[indexes[0]];
        swap(indexes[0], indexes[index]);
        reverse[indexes[0]] = 0;
        reverse[indexes[index]] = -1;
        index--;
        shiftDown(0);
        return item;
    }

    T getItem(int i)
    {
        assert(contain(i));
        return data[i];
    }


    void change(int i, T newItem)
    {
        assert(contain(i));
        data[i] = newItem;
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

    bool contain(int i)
    {
        assert(i >= 0 && i + 1 <= capacity);
        return reverse[i] != -1;
    }
};

int main()
{
    IndexMaxHeap<int> indexMaxheap = IndexMaxHeap<int>(5);
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
        indexMaxheap.insert(i, i + 1);

    indexMaxheap.change(3, 8);
    while (!indexMaxheap.isEmpty())
        cout << indexMaxheap.removeMax() << " ";
    cout << endl;
    return 0;
}
