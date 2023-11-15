#include <iostream>
using namespace std;

class Car
{
public:
    void Drive()
    {
        cout << "I drive" << endl;
    }
    void Use()
    {
        cout << "I drive" << endl;
    }
};
class Airplane
{
public:
    void Fly()
    {
        cout << "I fly" << endl;
    }
    void Use()
    {
        cout << "I fly" << endl;
    }
};
class FlyingCar: public Car, public Airplane
{

};

class A
{
public:
    int a;
    void Show()
    {
        cout << "A" << endl;
    }
};
class B : public A{};
class C : public A{};
class D1 : public B, public C 
{
public :
    int getValue() { return C::A::a; }
};
class D2:public A{};
class D3:public D1, public D2{};
int main()
{
    D1 d;
    cout << d.C::a << endl;

    D3 d3;
    d3.D2::A::Show();
    d3.D1::C::A::a;


    Car car;
    car.Drive();
    Airplane air;
    air.Fly();

    FlyingCar flyCar;
    flyCar.Drive();
    flyCar.Fly();
    ((Car)flyCar).Use();
    ((Airplane)flyCar).Use();
    
}

