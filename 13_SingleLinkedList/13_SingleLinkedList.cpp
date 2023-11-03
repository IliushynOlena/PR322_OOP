#include <iostream>
using namespace std;
#include "windows.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
template<typename T>
class List
{
	struct Node
	{
		T value;
		Node* next;
		Node(T value, Node* next) :value(value), next(next) {}
	};
private:
	Node* head;
public:
	List()
	{
		head = nullptr;		
	}
	void AddToHead(T value)
	{
		Node* newNode = new Node(value,head);
		//newNode->value = value;
		//newNode->next = head;

		head = newNode;
	}
	void PrintList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void AddToTail(T value)
	{
		Node* newNode = new Node(value, nullptr);

		if (head == nullptr)
			head = newNode;
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}	
	}
	T GetElementByPosition(int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
	}
	void DeleteFromTail()
	{
		if (head == nullptr)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}		
	}
};
class Point{};
class Vector
{
	int size;
	//Point * points = new Point[size];
	List<Point> points;
public:
	//Vector()
	//{
	//	size = 0;
	//	points = nullptr;
	//}
	//void AddPoint(Point p)
	//{
	//	size++;
	//	Point* temp = new Point[size];//1
	//	for (int i = 0; i < size; i++)
	//	{
	//		temp[i] = points[i];
	//	}
	//}
	void AddPointToHead(Point p)
	{
		points.AddToHead(p);
	}
};

int main()
{
	//gotoxy(10, 10);
	List<int> list;
	/*for (int i = 0; i < 10; i++)
	{
		list.AddToHead(i);
	}
	list.PrintList();*/
	list.AddToTail(100);
	/*list.AddToTail(200);
	list.AddToTail(300);
	list.AddToTail(400);*/
	list.PrintList();
	//cout << "Element [3] : " << list.GetElementByPosition(3) << endl;
	list.DeleteFromTail();
	//list.DeleteFromTail();
	//list.DeleteFromTail();
	list.PrintList();






}