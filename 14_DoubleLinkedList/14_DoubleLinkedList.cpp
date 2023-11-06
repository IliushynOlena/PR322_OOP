#include <iostream>
using namespace std;

template<typename T>
class List
{
	struct Node
	{
		Node* prev;
		T value;
		Node* next;
		Node(Node* prev ,T value, Node* next) :prev(prev),value(value), next(next) {}
	};
private:
	Node* head;
	Node* tail;
	int size;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	void AddToHead(T value)
	{
		Node* newNode = new Node(nullptr, value, head);

		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			head = newNode;
		}	
		size++;
	}
	void PrintList()
	{
		//Node* current = head;//int i = 0;
		//while (current != nullptr)//i < 10
		//{
		//	cout << current->value << " ";
		//	current = current->next;//i++;
		//}
		for (Node* i = head; i != nullptr; i = i->next)
		{
			cout << i->value << " ";
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
		Node* newNode = new Node(tail, value, nullptr);

		if (IsEmpty())
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
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
	T operator[](int pos)
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
		if (IsEmpty())return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail =  nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		size--;
	}
	int GetSize()
	{
		return size;
	}
	void DeleteByPosition(int pos)//4
	{
		if (pos < 1 || pos > size)return;
		else if (pos == 1)
		{
			//DeleteFromHead(); 
		}
		else if (pos == size)
		{
			DeleteFromTail();
		}
		else
		{
			Node* current;
			if (pos <= size / 2)
			{
				current = head;
				for (int i = 1; i < pos; i++)
				{
					current = current->next;
				}
			}
			else
			{
				current = tail;
				for (int i = size; i > pos; i--)
				{
					current = current->prev;
				}
			}	
			
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			size--;
		}
		
	}
};

int main()
{
	List<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.AddToHead(i);
	}
	cout << "Size : " << list.GetSize() << endl;
	list.PrintList();
	list.AddToTail(100);
	list.AddToTail(200);
	list.AddToTail(300);
	list.AddToTail(400);
	cout << "Size : " << list.GetSize() << endl;
	list.PrintList();
	//cout << "Element [3] : " << list.GetElementByPosition(3) << endl;
	//cout << "Element [5] : " << list[5] << endl;
	list.DeleteFromTail();
	list.DeleteFromTail();
	list.DeleteFromTail();
	cout << "Size : " << list.GetSize() << endl;
	list.PrintList();
	list.DeleteByPosition(3);
	list.DeleteByPosition(2);
	list.DeleteByPosition(4);
	list.DeleteByPosition(8);
	cout << "Size : " << list.GetSize() << endl;
	list.PrintList();






}