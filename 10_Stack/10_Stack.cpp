#include <iostream>
using namespace std;

const int EMPTY = -1;
const int FULL = 9;
/*
class Stack
{
    enum{ EMPTY = -1,  FULL = 9 };
    int arr[FULL + 1];//10
    int topIndex;
public:
    Stack() 
    {
        topIndex = EMPTY;
    }
    //default delete
    ~Stack() = default;
    //default constructor
    //destructor
    //copy constructor
    //operator =
    explicit Stack(const Stack& other) = delete;

    bool IsFull()const
    {
        return topIndex == FULL;
    }
    bool Push(int elem)
    {
        if (!IsFull())
        {           
            arr[++topIndex] = elem;
            return true;
        }
        return false;
    }
    bool IsEmpty()const
    {
        return topIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
            return arr[topIndex--];
        return 0;
    }
    int GetCount()const
    {
        return topIndex+1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
            return arr[topIndex];
        return 0;
    }
    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
*/
class Stack
{
private:
    enum {EMPTY = -1};
    int* arr;
    int size;
    int topIndex;
public:
    Stack() = delete;
    Stack(int size):size(size)
    {
        //this->size = size;
        arr = new int[size];
        topIndex = EMPTY;
    }
    bool IsFull()const
    {
        return topIndex == size-1;
    }
    bool Push(int elem)
    {
        if (!IsFull())
        {
            arr[++topIndex] = elem;
            return true;
        }
        return false;
    }
    bool IsEmpty()const
    {
        return topIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
            return arr[topIndex--];
        return 0;
    }
    int GetCount()const
    {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
            return arr[topIndex];
        return 0;
    }
    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        delete[]arr;
    }

};
bool IsValidCode(string code)
{
    Stack st(10);
    for (char symbol : code)
    {
        if (symbol == '{')
        {
            st.Push(1);
        }
        if (symbol == '}')
        {
            if (st.IsEmpty())return false;
            st.Pop();
        }
    }
    return st.IsEmpty();
}


int main()
{
   
    
    Stack st(20);
    st.Push(5);
    st.Push(7);
    st.Push(8);
    st.Push(4);
    st.Push(11);
    cout << "Count : " << st.GetCount() << endl;
    st.Print();
    cout << "Element  by Peek : " << st.Peek() << endl;
    while (!st.IsEmpty())
    {
        cout << "Element  : " << st.Pop() << endl;
        st.Print();
    }
    cout << "Count : " << st.GetCount() << endl;

    string code = "class Stack{ void Print(){for(.....){if(.....){.....}}}};";
    if (IsValidCode(code))
        cout << "Valid code" << endl;
    else
        cout << "Invalid code" << endl;
    
}

