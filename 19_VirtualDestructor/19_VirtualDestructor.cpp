//#include <iostream>
//using namespace std;
//
//class Student
//{
//    string name;
//    string spetialization;
//    int* marks;
//    int markCount;
//public:
//    Student():name("no name"),spetialization("none"), marks(nullptr), markCount(0) {}
//    Student(string name, string sp):name(name),spetialization(sp)
//    {
//        markCount = 1 + rand()%9;
//
//        marks = new int[markCount];
//        for (int i = 0; i < markCount; i++)
//        {
//            marks[i] = 1 + rand() % 12;//0....11
//        }
//    }
//    virtual void Print()const
//    {
//        cout << "Student name : " << name << endl;
//        cout << "Spetialization: " << spetialization << endl;
//        cout << "Marks : ";
//        for (int i = 0; i < markCount; i++)
//        {
//            cout << marks[i] << " ";
//        }
//        cout << "\n---------------------------------" << endl;
//    }
//    virtual ~Student()
//    {
//        if (marks != nullptr)
//            delete[]marks;
//    }
//};
//class Aspirant: public Student
//{
//    string *subjects;
//    int subCount;
//public:
//    Aspirant(string name, string sp, initializer_list<string> list) : Student(name, sp)
//    {
//        this->subCount = list.size();
//        subjects = new string[subCount];
//        int i = 0;
//        for (string sub : list)
//        {
//            subjects[i] = sub;
//            i++;
//        }    
//    }
//    void Print()const override
//    {
//        Student::Print();
//        cout << "Subject : ";
//        for (int i = 0; i < subCount; i++)
//        {
//            cout << subjects[i] << " | ";
//        }
//        cout << "\n_______________________________" << endl;
//    }
//    ~Aspirant()
//    {
//        cout << "Destructor" << endl;
//        if (subjects != nullptr)
//            delete[]subjects;
//    }
//
//};
//
//int main()
//{
//    srand(time(0));   
//    
//    Student st("Anton","Programmer");
//    st.Print();
//
//    Aspirant asp("Vasya", "Water engineer", { "Beaver dams", "Hydroelectric power plant"
//        , "How to take bribes" });
//
//    asp.Print();
//
//    cout << "*****************************************" << endl;
//    Student* group[3]
//    {
//        new Student("Anton","Programmer"),
//        new Aspirant("Vasya", "Water engineer", { "Beaver dams", "Hydroelectric power plant"
//        , "How to take bribes" }),
//        new Aspirant("Grisha", "Car engineer", { "Engine"})
//    };
//
//    for (int i = 0; i < 3; i++)
//    {
//        group[i]->Print();
//        delete group[i];
//    }
//
//
//}
//
