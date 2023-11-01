#include <iostream>
using namespace std;

template<typename T>
class Queue
{
//public:
    struct Element
    {
        T value;
        int priority;
    };
private:
    Element* data;
    int size;
public:
   /* Queue()
    {
        data = nullptr;
        top = 0;
    }*/
    Queue():data(nullptr), size(0){}
    ~Queue()
    {
        if (data != nullptr)delete[]data;
    }

    void Enqueue(T value, int priority)
    {
        int index = 0;

        while (index < size && data[index].priority < priority) { index++; }
        size++;
        Element* temp = new Element[size];
        for (int i = 0; i < index; i++)
        {
            temp[i] = data[i];
        }
        temp[index] = Element{value, priority };
        for (int i = index; i < size-1; i++)
        {
            temp[i + 1] = data[i];
        }
        if (data != nullptr)delete[]data;

        data = temp;
    }
    bool IsEmpty()
    {
        return size == 0;
    }
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = data[0];
            for (int i = 0; i < size; i++)
            {
                data[i] = data[i + 1];
            }
            size--;
            return first;
        }
        return Element();
    }
    void Print()
    {
        cout << "------------- Queue ----------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << data[i].value << " : " << data[i].priority << endl;
        }
        cout << endl;
        cout << "______________________________________" << endl;

    }
};



int main()
{
    Queue<char> q;
  
    q.Enqueue('B', 2 );
    q.Enqueue( 'N', 12);
    q.Enqueue('C', 3 );
    q.Enqueue('K', 8 );
    q.Enqueue('G', 5 );
   /* Queue<char>::Element element = { 'A', 1 };
    q.Enqueue(element);
    q.Enqueue(Queue<char>::Element{'B', 2});
    q.Enqueue(Queue<char>::Element{'N', 12});
    q.Enqueue(Queue<char>::Element{'C', 3});
    q.Enqueue(Queue<char>::Element{'K', 8});
    q.Enqueue(Queue<char>::Element{'G', 5});*/
  /*  Element<char> element = { 'A', 1 };
    q.Enqueue(element);
    q.Enqueue(Element<char>{'B',2});
    q.Enqueue(Element<char>{'N',12});
    q.Enqueue(Element<char>{'C',3});
    q.Enqueue(Element<char>{'K',8});
    q.Enqueue(Element<char>{'G',5});*/
    q.Print();

    q.Enqueue('D',4);
    q.Print();
   
    while (!q.IsEmpty())
    {
        auto res = q.Dequeue();
        cout << "Value : " << res.value<< endl;

    }
    q.Enqueue('H', 15);


    int a = 15;
    float b = 3.14;
    double d = 5.23;
    int r;
    r = 158;
    auto f = "Hello";
    auto j = 15;
    auto p = 3.14;


}

