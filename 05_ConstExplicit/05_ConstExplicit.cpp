#include <iostream>
using namespace std;

//class Date
//{
//public:
//    int day;
//    int month;
//    int year;
//  /*  Date()
//    {
//        day = 0;
//        month = 0;
//        year = 0;
//    }*/
//    void setDay(int day)
//    {
//        this->day = day;
//    }
//   /* void setDay(Date * const this, int day)
//    {
//        this->day = day;
//    }*/
//    int getDay()
//    {
//        return day;
//    }
//    int getDay()const
//    {
//        return day;
//    }
//  /*  Date(const Date & other)
//    {
//
//    }*/
//};
class Date
{
    const int baseYear;
    int& currentYear;
    int day;
    int month;
    int year;
public:
    Date(int current) :baseYear(2000), currentYear(current), day(0), month(0), year(0) {}
    Date(int base , int current) :baseYear(base), currentYear(current), day(0), month(0), year(0) {}
  /*  {
        baseYear = 2000;
        currentYear = current;
        day = 0;
        month = 0;
        year = 0;
    }*/
    void Show()
    {
        cout << "Base year : " << baseYear << endl;
        cout << "currentYear : " << currentYear << endl;
        cout << "day : " << day << endl;
        cout << "month : " << month << endl;
        cout << "year : " << year << endl;
    }
};

class Account
{
private:
    double sum;
    const double rate;
public:
    Account(double Rate, double Sum):rate(Rate)
    {
        //rate = Rate;
        sum = Sum;
    }
    double getRate() const
    {
        return rate;
    }
    double getIncome()
    {
        return sum * rate / 100;
    }
    double getIncome() const
    {
        return sum * rate / 100;
    }
    double getSum()
    {
        return sum;
    }
    double getSum()const
    {
        return sum;
    }
    double setSum()
    { 
        sum += getIncome();
        return sum;
    }
};

void doSomething(long number)
{

}
float doSomething()
{
    return 10.02;//double -> float
}


class Array
{
private:
    int size;
    int* arr;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size)
    {       
        this->size = size;
        arr = new int[size];
       /* for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 30;
        }*/
    }
    Array(int size, int a)
    {
        this->size = size;
        arr = new int[size];
        /* for (int i = 0; i < size; i++)
         {
             arr[i] = rand() % 30;
         }*/
    }
    ~Array()
    {
        delete[]arr;
    }

    int getSize()const
    {
        return size;
    }
    void setArray(int value, int index)
    {
        arr[index] = value;
    }
    void display(int index)const
    {
        cout << arr[index] << " ";
    }

};

void Display(const Array& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.display(i);
    }
    cout << endl;
}

int main()
{
    Array arr ;//default constructor
    Array arr2(10);
    int size = arr2.getSize();
    cout<<"Size : "<< arr2.getSize()<<endl;
    for (int i = 0; i < arr2.getSize(); i++)
    {
        arr2.setArray(i + 1,i);
    }
    Display(arr2);//Array
    cout << "!!!!!!!!!!!!!!!!!!!" << endl;
    //Display(5);//int -> Array

    //Array arr3 = 15;//int -> Array
    Array arr3(15);//int -> Array
    Display(arr3);
    int a = 3.33;//implicit double -> int  - 3
    int b = (int) 5.25;//explicit

    /*
    double a(10);//int -> double; // 10.0000000000000
    a = 5;
    doSomething(15);//int -> long

    double d = 5.0 / 4;//double/ int = double


    Account account1(5, 2000);
    const Account account2(8, 5000);

    cout << "getRate ac 1 : " << account1.getRate() << endl;
    cout << "getRate ac 2 : " << account2.getRate() << endl;

    cout << "getSum ac 1 : " << account1.getSum() << endl;
    cout << "getSum ac 2 : " << account2.getSum() << endl;

    cout << "getIncome ac 1 : " << account1.getIncome() << endl;
    cout << "getIncome ac 2 : " << account2.getIncome() << endl;

    cout << "setSum ac 1 : " << account1.setSum() << endl;
   // cout << "setSum ac 2 : " << account2.setSum() << endl;//error
   */
    /*
    Date d(2023);
    d.Show();
    cout << "Enter base year : ";
    int base;
    cin >> base;
    Date current(base, 2000);
    current.Show();
    */
    /*
    const int size = 10;
    const string str{ "First day" };
    const char* path{ "D:/Tets/test.txt" };
    const int days[]{ 31,31,28 };

    const Date eventDay{ 1, 1, 2024 };
    cout << "Day : " << eventDay.day << " Month : " << eventDay.month << " Year : " 
        << eventDay.year << endl;

    //eventDay.setDay(9);
   cout<<  eventDay.getDay()<<endl;
    cout << "Day : " << eventDay.day << " Month : " << eventDay.month << " Year : "
        << eventDay.year << endl;

    Date vacation{ 23,10,2023 };
    cout << "Day : " << vacation.day << " Month : " << vacation.month << " Year : "
        << vacation.year << endl;
    cout << vacation.getDay() << endl;
    */

    









}

