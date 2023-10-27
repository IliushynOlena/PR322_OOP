#include <iostream>
using namespace std;
/*
int FindMax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)max = arr[i];
    }
    return max;
}
long FindMax(long* arr, int size)
{
    long max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)max = arr[i];
    }
    return max;
}
short FindMax(short* arr, int size)
{
    short max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)max = arr[i];
    }
    return max;
}
*/
template<typename T_arr>
T_arr FindMax(T_arr* arr, int size)
{
    T_arr max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)max = arr[i];
    }
    return max;
}
//class Point{};
//template<typename T_coll, typename T_val>
template<class T_coll, class T_val>
class MyClass
{
    T_coll* collection;
    int size;
    T_val value;
public:
    MyClass()
    {
        collection = nullptr;
        size = 0;
        //point=0;
    }
    MyClass(T_coll* coll, T_val value) :collection(coll), value(value) {}
    ~MyClass()
    {
        if (collection != nullptr)
            delete[]collection;
    }
    void SetCollection(T_coll* coll);   
    void SetValue(T_val value);
    void Print()
    {
        cout << "Collection : " << collection << endl;//032dg3sdg3ds21g
        cout << "Value : " << value << endl;
    }
};

template<class T_coll, class T_val>
void MyClass<T_coll, T_val>::SetCollection(T_coll* coll)
{
    collection = coll;
}

template<class T_coll, class T_val>
void MyClass<T_coll, T_val>::SetValue(T_val value)
{
    this->value = value;
}

template<typename T_coord>
class Point
{
private:
    T_coord x;
    T_coord y;
public:
    Point()
    {
        x = y = 0;
    }
    explicit Point(T_coord value) :x(value), y(value) {}
    Point(T_coord x, T_coord y) :x(x), y(y) {}
    void Print()const
    {
        cout << "X : " << x << " Y : " << y << endl;
    }
    void SetCoords(T_coord newX, T_coord newY)
    {
        this->x = newX;
        this->y = newY;
    }
};
template<typename T_X, typename T_Y>
class NewPoint
{
private:
    T_X x;
    T_Y y;
public:
    NewPoint()
    {
        x = y = 0;
    }
    explicit NewPoint(T_Y value) :x(value), y(value) {}
    NewPoint(T_X x, T_Y y) :x(x), y(y) {}
    void Print()const
    {
        cout << "X : " << x << " Y : " << y << endl;
    }
    void SetCoords(T_X newX, T_Y newY)
    {
        this->x = newX;
        this->y = newY;
    }
};

class Array {
    int* arr;
    int size;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    Array(const initializer_list<int> &list)
    {
        this->size = list.size();//16
        arr = new int[size];//16
        /*for (int i = 0; i < size; i++)
        {
            arr[i] = list[i];
        }*/
        int i = 0;
        for (int element : list)
        {
            arr[i++] = element;//16
        }
    }
    void Fill(const initializer_list<int>& list)
    {
        if (arr != nullptr)delete[]arr;
        this->size = list.size();//3
        arr = new int[size];//3
        int i = 0;
        for (int element : list)
        {
            arr[i++] = element;
        }
    }
    void  Print()
    {
        cout << "Array size  : " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Array()
    {
        if (arr != nullptr)
            delete[]arr;
    }
};

int main()
{
    Array arr3({ 10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 });//16
    arr3.Print();
    arr3.Fill({ 3,2,1 });
    arr3.Print();
    int static_arr[5] = { 1,2,3,4,5};
    int * dynam_arr = new int[5] { 1, 2, 3, 4, 5};
    Array arr;
    arr.Print();
    Array arr2 (15);
    arr2.Print();

   

    delete[]dynam_arr;

    /*
    Point<float> point(4.3, 6.77);
    point.Print();

    point.SetCoords(15.147, 111.33);
    point.Print();

    Point<int> point2(4, 6);
    point2.Print();

    point2.SetCoords(15, 113);
    point2.Print();


    NewPoint<double, long> point3(2.25, 10);
    point3.Print();
    cout << endl << endl;


    long* long_arr = new long[6];
    for (int i = 0; i < 6; i++)
    {
        long_arr[i] = i + 1; 
        cout << long_arr[i] << " ";
    }
    cout << endl;
    char* char_arr = new char[6];
    for (int i = 0; i < 6; i++)
    {
        char_arr[i] = 'a' + i;
        cout << char_arr[i] << " ";
    }
    MyClass<long,string> cl1(long_arr, "Class with long collection");
    MyClass<char,string> cl2(char_arr, "Class with char collection");

    cl1.Print();
    cl2.Print();
   // delete[]long_arr;
   // delete[]char_arr;
   */

    /*
    const int size = 10;
    short numbers[size] = { 5,6,7,9,12,14,23,5,88,36 };
    cout << "Max = " << FindMax(numbers, size) << endl;

    string colors[5] = { "Red","White", "blue","Green","black" };
    cout << "Max = " << FindMax(colors, 5) << endl;

    short numbers1[size] = { 5,6,7,9,12,14,23,5,88,36 };
    cout << "Max = " << FindMax(numbers1, size) << endl;
    */

}

