#include <iostream>
using namespace std;

inline void Hello()
{
	cout << "Hello world" << endl;
}

class Human
{
	string name;//1
	int age;//2
	int weight;//3
	static int countHuman;
public:
	static int getStaticCount()
	{
		return countHuman;
	}
	//default
	Human() //:name{ "no name" }, age{ 0 }, weight{ 0 } {}
	{
		name = "no name";
		age = 0;
		weight = 0;
		countHuman++;
	}
	Human(string name):Human()
	{
		this->name = name;
		//age = 0;
		//weight = 0;
		
	}
	Human(string name , int age): Human(name)
	{
		//this->name = name;
		this->age = age;
		//weight = 0;
		
	}
	Human(string name, int age, int weight):Human(name,age)
	{
		//this->name = name;
		//this->age = age;
		this->weight = weight;
		
	}
	/*
	Human(int age)
	{
		name = "no name";
		this->age = age;
		weight = 0;
	}
	Human(int weight, string name)
	{
		this->name = name;
		age = 0;
		this->weight = weight;
	}
	*/
	void Show()
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Weight : " << weight << endl;
		cout << "_______________________________________" << endl;
	}
	~Human()
	{
		countHuman--;
	}
	void PrintCount()
	{
		cout << "Print count : " << countHuman << endl;
	}
	

};
 int Human::countHuman = 0;
int main()
{

	//cout << Human::countHuman << endl;
	//Hello();
	
	Human h1;//default
	//h1.Show();
	Human h2("Andriy");
	//h2.Show();
	Human h3("Olena", 15);
	//h3.Show();
	if (true)
	{
		Human h4("Yura", 10, 40);
		///h4.Show();
	}
	
	//cout << "Count of Human : "<<  Human::countHuman << endl;
	/*cout << "Count of Human h1 : "<< h1.countHuman << endl;
	cout << "Count of Human h2 : "<< h2.countHuman << endl;
	cout << "Count of Human h3: "<< h3.countHuman << endl;*/
	//cout << "Count of Human h4: "<< h4.countHuman << endl;
	cout << "Count of Human h1 : "; h1.PrintCount() ;
	cout << "Count of Human h1 : " << h1.getStaticCount() << endl;
	cout << "Count of Human : " << Human::getStaticCount() << endl;
	//cout << "Count of Human : " << Human::PrintCount() << endl;//error
	/*
	Human h5(100);
	h5.Show();
	Human h6(30, "Kolya");
	h6.Show();
	Human h7(47);
	h7.Show();
	*/






}

