#include <iostream>
#include <string>
using namespace std;

struct Date//public
{
    int day;
    string month;
    int year;
};

class Person//private
{
private:
    string name;
    string surname;
    string lastname;
    Date birthday;
    unsigned long long phone;
    string city;
    string country;
    string unv_name;
    string unv_name_city;
    string unv_name_country;
    string group_number;
    int* marks;
    int countMarks;
    float average;
    void SetAverage()
    {
        float sum = 0;
        for (int i = 0; i < countMarks; i++)
        {
            sum += marks[i];
        }
        average = (float) sum / countMarks;
    }
public:
    //ctor + TAB - constructor
    Person()// default
    {
        cout << "Constructor " <<  endl;
        name = "no name";
        surname = "no surname";
        lastname = "no lastname";
        birthday = { 0,"no month",0 };
        phone = 0;
        city = "no city";
        country = "no country";
        unv_name = "no unv_name";
        unv_name_city = "no unv_name_city";
        unv_name_country = "no unv_name_country";
        group_number = "no group_number";
        marks = nullptr;
        countMarks = 0;
        average = 0;
    }
    Person(string name, string surname, string lastname)
    {
        cout << "Constructor invocation...... " << endl;
        this->name = name;
        this->surname = surname;
        this->lastname = lastname;

    }
    void Initialize()
    {
        name = "no name";
        surname = "no surname";
        lastname = "no lastname";
        birthday = { 0,"no month",0 };
        phone = 0;
        city = "no city";
        country = "no country";
        unv_name = "no unv_name";
        unv_name_city = "no unv_name_city";
        unv_name_country = "no unv_name_country";
        group_number = "no group_number";

    }
    void InitFromKeyBoard()
    {
        cout << "Enter name of student :";
        getline(cin, name);//Olena | Huan Pablo
        cout << "Enter surname of student :";
        getline(cin, surname);
        cout << "Enter lastname of student :";
        getline(cin, lastname);
        cout << "Enter day of birthday :";
        cin >> birthday.day;
        cout << "Enter moth of birthday :";
        cin >> birthday.month;
        cout << "Enter year of birthday :";
        cin >> birthday.year;
        cout << "Enter phone number :";
        cin >> phone;
        cin.ignore();
        cout << "Enter city :";
        getline(cin, city);
        cout << "Enter country :";
        getline(cin, country);
        cout << "Enter university name :";
        getline(cin, unv_name);
        cout << "Enter university city name :";
        getline(cin, unv_name_city);
        cout << "Enter university country name :";
        getline(cin, unv_name_country);
        cout << "Enter group name :";
        getline(cin, group_number);  
    }
    void Show();
    void AddMark(int mark);

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setSurame(string surname)
    {
        this->surname = surname;
    }
    string getSurname()
    {
        return surname;
    }
    void setLastName(string lastname)
    {
        this->lastname = lastname;
    }
    string getLastName()
    {
        return lastname;
    }
    void setBirthday(Date b)
    {
        birthday.day = b.day;
        birthday.month = b.month;
        birthday.year = b.year;
    }
    Date getBirthday()
    {
        return birthday;
    }
    void setPhone(unsigned long long phone)
    {
        this->phone = phone;
    }
    unsigned long long getPhone()
    {
        return phone;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    string getCity()
    {
        return city;
    }
    void setCountry(string country)
    {
        this->country = country;
    }
    string getCountry()
    {
        return country;
    }
    void setUNVName(string unv_name)
    {
        this->unv_name = unv_name;
    }
    string getUNVName()
    {
        return unv_name;
    }
    void setUNVNameCity(string unv_name_city)
    {
        this->unv_name_city = unv_name_city;
    }
    string getUNVNameCity()
    {
        return unv_name_city;
    }
    void setUNVNameCountry(string unv_name_coutry)
    {
        this->unv_name_country = unv_name_country;
    }
    string getUNVNameCountry()
    {
        return unv_name;
    }
    void setGroupName(string group_number)
    {
        this->group_number = group_number;
    }
    string getGroupName()
    {
        return group_number;
    }
    //destructor
    ~Person()
    {
        cout << "Destructor" << name << endl;
        if (marks != nullptr)
            delete[]marks;
    }
};

int main()
{
    //cout << sizeof(Student) << endl;
    Person st;//default constructor
    //st.Initialize();
    //st.InitFromKeyBoard();
    //st.setName("Olena");
    //st.setLastName("Iliushyn");
    st.Show();

    Person st2;//default constructor
    //st2.Initialize();
    //st2.setName("Bob");
    st2.Show();

    Person st3("Oleg", "Vinnuk", "Mukolayovich");
    st3.AddMark(8);
    st3.AddMark(10);
    st3.AddMark(4);
    st3.AddMark(6);
    st3.AddMark(7);
    st3.AddMark(8);
    st3.Show();


   

}

inline void Person::Show()
{
    cout << "Name : " << name << endl;
    cout << "Surname : " << surname << endl;
    cout << "Lastname : " << lastname << endl;
    cout << "Birthday  : " << birthday.day << "/" << birthday.month << "/" << birthday.year << endl;
    cout << "Phone : " << phone << endl;
    cout << "City : " << city << endl;
    cout << "Country : " << country << endl;
    cout << "University : " << unv_name << endl;
    cout << "University city : " << unv_name_city << endl;
    cout << "University country : " << unv_name_country << endl;
    cout << "Number of group: " << group_number << endl;
    cout << "Rating : " << average << endl;
    cout << "Marks : ";
    for (int i = 0; i < countMarks; i++)
    {
        cout << marks[i] << " ";
    }
    cout << endl;
}
void Person::AddMark(int mark)
{
    countMarks++;
    int* temp = new int[countMarks];
    for (int i = 0; i < countMarks - 1; i++)
    {
        temp[i] = marks[i];
    }
    temp[countMarks - 1] = mark;
    if (marks != nullptr)
        delete[]marks;
    marks = temp;
    SetAverage();

}
