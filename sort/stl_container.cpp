#include <iostream>
#include <string>
#include <vector>

using namespace std;

void stropt()
{
    //string
    string s1 = "s1:hello tomorrow";
    string s2("s2: hello tomorrow");
    string s3(5, 'a');

    string s4;
    // cin >> s4;

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    // cout << s4 << endl;

    //string io
    string str;
    // getline(cin, str);
    // cout << str << endl;

    //iterator
    // for (string::iterator it = str.begin(); it != str.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    //find sub string
    string str2 = "hello world";
    cout << str2.find("hello", 0) << endl;
    if (str2.find("xyz", 0) == string::npos)
    {
        cout << "can not find the sub string!\n";
    }
}

void vectoropt()
{
    //vector
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << v1.front() << endl;
    cout << v1.back() << endl;

    v1.insert(v1.begin() + 1, 900); //在第二个位置插入新元素

    v1.erase(v1.begin() + 3); //删除第四个元素
    
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
    {
        cout << *it << " ";
    }
}

int main()
{

    vectoropt();
    return 0;
}
