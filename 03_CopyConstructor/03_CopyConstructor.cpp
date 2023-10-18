#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};


class Student
{
private:
	string name;//Victor   - Victor
	int age;//        15   - 15
	int* marks;//00dd78tr  - 00dd78tr
	int marksCount;//4     - 4

public:
	// Конструктор - метод, який викликається автоматично при створенні об'єкта класу.
	// Використовується для ініціалізації полів

	// Конструктора за замовчуванням (default ctor) - без параметрів
	Student()
	{
		name = "";
		age = 0;
		marks = nullptr;
		marksCount = 0;
	}

	// Параметризований конструктор - який приймає якісь параметри
	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
		this->marks = nullptr;
		this->marksCount = 0;

		cout << "Paramerized Constructor [" << name << "]...\n";
	}
	Student(int age, string name)
	{
		this->name = name;
		this->age = age;
		this->marks = nullptr;
		this->marksCount = 0;

		cout << "Paramerized Constructor [" << name << "]...\n";
	}
	//copy constructor
	Student(const Student & other)
	{
		this->name = other.name;//Victor   - Victor
		this->age = other.age;//   15   - 15
		//this->marks = other.marks;//00dd78tr  - 00dd78tr --error
		this->marks = new int[other.marksCount];
		for (int i = 0; i < other.marksCount; i++)
		{
			marks[i] = other.marks[i];
		}
		this->marksCount = other.marksCount;//4     - 4

	}
	// Деструктор - метод, який викликається автоматично при видаленні об'єкта класу
	// Використовується для очищення пам'яті, звільнення ресурсів і тд.
	~Student()
	{
		if (marks != nullptr)
			delete[] marks;
		cout << "Destructor [" << name << "]...\n";
	}


	void Print()  
	{
		cout << "-------- STUDENT [" << name << "] ---------\n";
		cout << "Age: " << age << endl;
		cout << "Marks: ";
		for (size_t i = 0; i < marksCount; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}

	void AddMark(int value)
	{
		int* new_arr = new int[marksCount + 1];
		for (size_t i = 0; i < marksCount; ++i)
		{
			new_arr[i] = marks[i];
		}
		new_arr[marksCount] = value;
		if (marks != nullptr)
			delete[] marks;
		marks = new_arr;

		++marksCount;
	}

};
int main()
{

	Student testSt;					
	Student st("Viktor", 15);	

	st.AddMark(8);
	st.AddMark(7);
	st.AddMark(11);
	st.AddMark(10);


	st.Print();

	{
		//Student copy = Student(st);
		Student copy(st);
		copy.Print();
	}
	

	st.Print();




#pragma region Initialization of varoables
    /*
int answer{ 42 };
const float goodTemp{ 36.6 };
int grades[4]{ 9.3,7,10,8 };
for (int i = 0; i < 4; i++)
{
    cout << grades[i] <<" ";
}
int mass[2][2]{ {1,2},{3,4} };
int* ptr{ nullptr };
int& reference{ answer };
Point point{ 10,8 };



int a;
int b = 10;
int c = 33.3;//double -> int
//cout << a << endl;
cout << b << endl;
cout << c << endl;

int numbers[2];
numbers[0] += 2;
cout << numbers[0] << endl;
cout << "Your Numbers" << endl;
int number = 0.25;//ініціалізація з копіюванням
cout << number << endl;
int value(42.5);//пряма ініціалізація
cout << value << endl;
int size{ 333};//уніфікована ініціалізація
cout << size << endl;
char ch{ 77 };
cout << ch << endl;
*/
#pragma endregion
}

