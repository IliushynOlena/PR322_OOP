#include <iostream>
#include <map>
using namespace std;


map<string, int>::iterator findByValue(map<string, int> &m, int value)
{
	for (map<string, int>::iterator i = m.begin(); i != m.end(); ++i)
	{
		if (i->second == value)
		{
			cout << i->first << "   " << i->second << endl;
			return i;
		}
	}
	return m.end();
}
int main()
{
	map<string, int> m;

	pair<string, int> p("Valia", 5);
	m.insert(p);
	m.insert(pair<string, int>("Olga", 7));
	m.insert(make_pair("Petro", 3));

	for (auto i : m)
	{
		cout << "Key : "<<  i.first << "  Value : "<< i.second << endl;
	}

	//auto res = m.insert(pair<string, int>("Olga", 15));
	pair<map<string,int>::iterator, bool> res = m.insert(pair<string, int>("Olga", 15));

	if (res.second)
	{
		cout << "Was added!!!" << endl;
	}
	else
	{
		cout << "Was not added!!!" << endl;
	}
	for (auto i : m)
	{
		cout << "Key : " << i.first << "  Value : " << i.second << endl;
	}

	cout << "Value : " << m["Valia"] << endl;
	cout << "Value : " << m["Olga"] << endl;


	map<string, int>::iterator it = m.find("Olga");

	if (it == m.end())
	{
		cout << "Not found!!" << endl;
	}
	else
	{
		cout << "Found!!" << endl;
		cout << "Key : " << it->first << "  Value : " << it->second << endl;
		//it->first = "Ivanka";//error
		it->second = 333;
		cout << "Key : " << it->first << "  Value : " << it->second << endl;
	}

	it = findByValue(m, 5);

	if(it != m.end())
		cout << "Key : " << it->first << "  Value : " << it->second << endl;

	if (it != m.end())
		m.erase(it);
	cout << endl;
	for (auto i : m)
	{
		cout << "Key : " << i.first << "  Value : " << i.second << endl;
	}
	cout << endl;
	m["Kolya"] = 100500;
	m["Olia"] = 100500;
	for (auto i : m)
	{
		cout << "Key : " << i.first << "  Value : " << i.second << endl;
	}

}