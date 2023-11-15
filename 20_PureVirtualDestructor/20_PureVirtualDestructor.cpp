#include <iostream>
using namespace std;

class Person//abstract class
{
    string name;
public:
    Person() :name("no name") {}
    Person(string name) :name(name) {}
    virtual void Print()const
    {
        cout << "Student name : " << name << endl;
        cout << "\n---------------------------------" << endl;
    }
    virtual ~Person() = 0 {}

};
class Aspirant : public Person
{
    string* subjects;
    int subCount;
public:
    Aspirant(string name, initializer_list<string> list) : Person(name)
    {
        this->subCount = list.size();
        subjects = new string[subCount];
        int i = 0;
        for (string sub : list)
        {
            subjects[i] = sub;
            i++;
        }
    }
    void Print()const override
    {
        Person::Print();
        cout << "Subject : ";
        for (int i = 0; i < subCount; i++)
        {
            cout << subjects[i] << " | ";
        }
        cout << "\n_______________________________" << endl;
    }
    ~Aspirant()
    {
        cout << "Destructor" << endl;
        if (subjects != nullptr)
            delete[]subjects;
    }

};

int main()
{
    srand(time(0));

    cout << "*****************************************" << endl;
    Person* people[2]
    {
        //new Person("Anton"),
        new Aspirant("Vasya",{ "Beaver dams", "Hydroelectric power plant"
        , "How to take bribes" }),
        new Aspirant("Grisha",{ "Engine"})
    };

    for (int i = 0; i < 2; i++)
    {
        people[i]->Print();
        delete people[i];
    }


}

