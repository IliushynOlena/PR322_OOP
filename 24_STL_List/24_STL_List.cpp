#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

void Show(list<int>& list1, list<int> &list2)
{
	list<int>::iterator iter;
	cout << "List 1 : ";
	for (iter = list1.begin(); iter != list1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "List 2 : ";
	for (auto iter = list2.begin(); iter != list2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl<<endl;
}

struct Book
{
	string name;
	string author;
	int pages;
};

bool CompareBookByName(const Book& b1, const Book& b2)
{
	return b1.name < b2.name;
}
bool CompareBookByAuthor(const Book& b1, const Book& b2)
{
	return b1.author < b2.author;
}
bool CompareBookByPages(const Book& b1, const Book& b2)
{
	return b1.pages < b2.pages;
}
bool comparator(const int&a, const int& b)
{
	return a < b;
}
void Print()
{
	cout << "hello";
}
int main()
{
	//Print();
	//cout << Print << endl;
	list<Book> library;
	library.assign({
		Book{"Harry Potter","Royling",800},
		Book{"Maria","Kotlarevskiy",200},
		Book{"The GodFather","Mario",600}
		});
	cout << "------------- Original list ------------ " << endl;
	for(Book b :library)
	{
		cout << left<< setw(15)<< b.name << left<< setw(15)<< b.author << setw(15) << b.pages << endl;
	}

	//CompareBookByName(Book{ "Harry Potter","Royling",800 }, Book{ "Harry Potter","Royling",800 });
	library.sort(CompareBookByName);
	cout << "------------- Sorted list by Name ------------ " << endl;
	for (Book b : library)
	{
		cout << left << setw(15) << b.name << left << setw(15) << b.author << setw(15) << b.pages << endl;
	}

	library.sort(CompareBookByAuthor);
	cout << "------------- Sorted list by Author ------------ " << endl;
	for (Book b : library)
	{
		cout << left << setw(15) << b.name << left << setw(15) << b.author << setw(15) << b.pages << endl;
	}
	library.sort(CompareBookByPages);
	cout << "------------- Sorted list by Pages ------------ " << endl;
	for (Book b : library)
	{
		cout << left << setw(15) << b.name << left << setw(15) << b.author << setw(15) << b.pages << endl;
	}
	/*
    list<int> l1, l2;

	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i); 
		l2.push_front(i);
	}
	Show(l1, l2);
	cout << "Size : " << l1.size() << endl;


	//l1.assign({ 11,21,31,41 });
	//Show(l1, l2);

	list<int>::iterator del= l1.begin();
	del++;
	del++;
	*del += 2;
	l1.erase(del);
	Show(l1, l2);

	l1.push_back(2);
	l1.push_back(2);
	l1.push_back(2);
	Show(l1, l2);
	l1.remove(2);
	Show(l1, l2);

	l1.insert(l1.begin(), 55);
	Show(l1, l2);
	l1.insert(l1.end(), { 7,7,7 });
	Show(l1, l2);
	l1.insert(l1.begin(), 4,77);
	Show(l1, l2);
	l1.insert(l1.begin(), l2.begin(), l2.end());
	Show(l1, l2);
	

	l1.resize(30, 99);
	Show(l1, l2);
	l1.push_back(2);
	l1.push_back(2);
	l1.push_back(2);
	Show(l1, l2);

	l1.splice(l1.end(), l2, l2.begin());
	Show(l1, l2);

	l1.reverse();
	Show(l1, l2);

	l1.sort();
	l2.sort();
	Show(l1, l2);

	l1.merge(l2);
	Show(l1, l2);

	l1.unique();
	Show(l1, l2);

	l1.swap(l2);
	Show(l1, l2);
    */
}

