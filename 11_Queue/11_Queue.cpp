#include <iostream>
#include <conio.h>
#include <stack>
using namespace std;

class Queue
{
	enum { Empty = 0};
	int* arr;
	int maxSize;
	int top;
public:
	Queue(int maxSize):maxSize(maxSize)
	{
		arr = new int[maxSize];
		top = Empty;
	}
	~Queue()
	{
		delete[]arr;
	}
	bool IsFull()const
	{
		return top == maxSize;
	}
	bool IsEmpty()const
	{
		return top == Empty;
	}
	void Enqueue(int elem)
	{
		if (!IsFull())
			arr[top++] = elem;
	}
	int Dequeue()
	{
		if (!IsEmpty())
		{
			int first = arr[0];
			for (int i = 0; i < top-1; i++)
			{
				arr[i] = arr[i + 1];
			}
			//simple queue
			//top--;

			//cycle queue
			arr[top-1] = first;


			return first;
		}

	}
	int GetCount()const
	{
		return top;
	}
	void Clear()
	{
		top = Empty;
	}
	void Show()const
	{
		for (int i = 0; i < top; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	srand(time(0));
	Queue q(15);

	for (int i = 0; i < 10; i++)
	{
		q.Enqueue(rand() % 30);
	}
	q.Show();
	cout << "Count : " << q.GetCount() << endl;
	while (!q.IsEmpty())
	{
		cout << "Element : " << q.Dequeue() << endl;
		_getch();
	}
	cout << "Element : " << q.Dequeue() << endl;
	cout << "Count : " << q.GetCount() << endl;
   
}

