#include <iostream>
#include <cassert>
using namespace std;

#define pi 3.14
#define begin {
#define end }
#define plus(a,b) (a)+(b)
#define write(a) cout<<a<<endl;


class Animal//abstract class
{
    string name;
    string place;
    float weight;
public:
    Animal() :name("no name"), place("no place"), weight(0) {}
    Animal(string name, string place, float weight) :name(name), place(place)
    {
      /*  if (weight < 0)
            this->weight = 0;
        else
            this->weight = weight;*/
        //assert(weight >= 0);
        this->weight = weight > 0 ? weight : 0;
    }
    virtual void ShowInfo()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }
    //pure virtual method
    virtual void MakeSound() = 0;

    virtual void Move()const
    {
        cout << "I am moving........." << endl;
    }

};

class Lion : public Animal
{
    float runSpeed;
public:
    Lion() :runSpeed(0), Animal() {}
    Lion(string n, string p, float w, float s) :runSpeed(s), Animal(n,p,w) {}
    void ShowInfo()const
    {
        Animal::ShowInfo();
        cout << "Run speed " << runSpeed << "km/h" << endl;
    }
    void Move()const override
    {
        cout << "I am running with speed " << runSpeed << "km/h"<<endl;
    }
    void MakeSound()override
    {
        cout << "RRRRRRRRRRRRRRRRRRR-rrrrrrrrrrrrrrr-rrrrrrrrrrrrr" << endl;
    }
};
class Duck:public Animal
{
    float balance;
    float flyHeight;
public:
    Duck():balance(10000000),flyHeight(0), Animal(){}
    Duck(string n, string p, float w, float b, float f):balance(b),flyHeight(f), Animal(n,p,w){}
    void Move()const override
    {
        cout << "I am swimming and flying up to  " << flyHeight << " m" << endl;;
    }
    void MakeSound()override
    {
        cout << "Quack-Quack-Quack-Quack-Quack-Quack-Quack-Quack" << endl;
    }
    void ShowInfo()const
    {
        Animal::ShowInfo();
        cout << "Balance " << balance << "$" << endl;
        cout << "Fly Height " << flyHeight << "m" << endl;
    }
};

class Reptile: public Animal
{
    float swimDeep;
public:
    Reptile() :swimDeep(0), Animal() {}
    Reptile(string n, string p, float w, float d) :swimDeep(d), Animal(n,p,w) {}

    void Move()const override
    {
        cout << "I am crawling  and swimming up to  " << swimDeep << " m" << endl;
    }
    void ShowInfo()const
    {
        Animal::ShowInfo();
        cout << "Swim Deep " << swimDeep << "m" << endl;  
    }
};
class Turtle: public Reptile
{
public:
    Turtle():Reptile(){}
    Turtle(string n, string p, float w, float d):Reptile(n,p,w,d){}

    void MakeSound()override
    {
        cout << "chirps-chirps-chirps-chirps-chirps-chirps-chirps" << endl;
    }
};
void RollCall(Animal& animal)
{
    animal.MakeSound();
    animal.Move();
    animal.ShowInfo();
    cout << endl;
}

int main()
{   
    /* Animal animal("Animal","Village",15);
    animal.MakeSound();*/
    Lion lion("Simba","Africa",190,81);
  /*  lion.ShowInfo();
    lion.Move();
    lion.MakeSound();*/
    cout << endl;
    Duck duck("Donald", "USA", 1.2, 44000000000, 2000);
   /* duck.ShowInfo();
    duck.Move();
    duck.MakeSound();*/

    Turtle turtle("Leonardo", "Ocean", 35, 290);

    RollCall(lion);
    RollCall(duck);
    RollCall(turtle);











  /*  const float PI = 3.14;
    cout << PI << endl;
    cout << PI << endl;
    cout << PI << endl;

    cout << plus(5, 3) << endl;
    if(true)
        begin
        cout << 3.14 << endl;
        end*/

    
}

