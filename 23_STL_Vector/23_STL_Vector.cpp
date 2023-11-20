#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(vector<int> v)
{
    sort(v.begin(), v.end());
    for (auto item : v)
    {
        cout << item << "  ";
    }
    cout << endl;
}
template<typename T>
ostream& operator << (ostream& out, vector<T> v)
{
    for (T item : v)
    {
        out << item << "  ";
    }
    out << endl;
    return out;
}
int main()
{
    vector<int> v({ 1, 2, 3, 4, 5, 6, 7, 8, });
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    vector<int>v2 = { 10,20,30,40,50 };
    cout << v << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int item : v)
    {
        cout << item << " - ";
    }
    cout << endl;
    cout << "------------------------------" << endl;
    //delete elements
    v.erase(v.begin());
    cout << v;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    v.erase(v.begin()+3);
    cout << v;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    v.erase(v.begin()+4, v.end());
    cout << v;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    v.erase(v.end()-1);
    cout << v;

    //insert element
    v.insert(v.begin(), { 7,8,9,10 });
    cout << v;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    v.insert(v.end(), 1000);
    cout << v;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    v.insert(v.end(), 5, 888);
    cout << v;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    v.insert(v.begin(), 111);
    cout << v;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    v.insert(v.begin(), v2.begin()+1, v2.end()-2);
    cout << v;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;


    v[0] = 555;
    cout << v;
   v.push_back(100);
   v.push_back(200);
   v.push_back(300);
   v.push_back(400);
   cout << v;
   cout << "Size : " << v.size() << endl;
   cout << "Capacity : " << v.capacity() << endl;
   v.pop_back();
   cout << v;

   //cout << v;
   //cout << v2;

   //v.swap(v2);
   //cout << v;
   //cout << v2;
   //cout << "First element : " << v.front() << endl;
   //cout << "Back element : " << v.back() << endl;

   v.resize(5);
   cout << v;
   cout << "Size : " << v.size() << endl;
   cout << "Capacity : " << v.capacity() << endl;
   v.push_back(400);
   v.push_back(400);
   v.push_back(400);
   cout << v;
   cout << "Size : " << v.size() << endl;
   cout << "Capacity : " << v.capacity() << endl;

   v.shrink_to_fit();
   cout << v;
   cout << "Size : " << v.size() << endl;
   cout << "Capacity : " << v.capacity() << endl;

   v.push_back(400);
   v.push_back(400);
   v.push_back(400);
   cout << v;
   cout << "Size : " << v.size() << endl;
   cout << "Capacity : " << v.capacity() << endl;
   //555  30  111   10 10  10  10 7 10 8  400  400  400  400  400  400
   for (int i = 0; i < v.size(); i++)
   {
       if (v[i] == 7)
       {
           v.insert(v.begin() + i + 1 , 10);

       }
   }
   cout << v;
   Print(v);
}

