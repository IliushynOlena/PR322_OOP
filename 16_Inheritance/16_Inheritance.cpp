#include <iostream>
using namespace std;

class Enemy
{
protected:
    string name;
    int health;
    float damage;
    int level;
    float defence;
public:
    Enemy() :name("no name"), health(0), damage(0), level(0), defence(0) {}
    Enemy(string n, int h, float d, int l, float def) :name(n), health(h), damage(d), 
        level(l), defence(def) {}
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Damage : " << damage << endl;
        cout << "Level : " << level << endl;
        cout << "Defence : " << defence << endl;
    }
    void DecreaseHealth(int value)
    {
        if (health - (value - defence) < 0)
            health = 0;
        else
            health -= (value - defence);
    }
    bool IsAlive()const
    {
        return health > 0;
    }   

};
//class Child : [spiceficator] Parent
//public private protected
class Dragon: public Enemy
{
    int fire;
public:
    Dragon() :fire(0), Enemy() {}
    Dragon(string n, int h, float d, int l, float def,int f) :fire(f), Enemy(n,h,d,l,def) {}
    float Attack()const
    {
        cout << "Attacking with damage " << damage << endl;
        return damage;
    }
    void Defence(int damage)
    {
        cout << "Getting " << damage << " damage" << endl;
        DecreaseHealth(damage - fire);
        cout << "Health after damage " << health << " % " << endl;
    }
    void Print()const
    {
        cout << "------------------ Dragon----------------------" << endl;
        Enemy::Print();
        cout << "Fire strength : " << fire << endl;
    }
};

class Monster : public Enemy
{
    float runSpeed;
public:
    Monster() :runSpeed(0), Enemy() {}
    Monster(string n, int h, float d, int l, float def, float  r) :runSpeed(r), 
        Enemy(n,h,d,l,def) {}
    void Run()
    {
        cout << "Run with speed : " << runSpeed << "km/h" << endl;
    }
    void Print()const
    {
        cout << "------------------ Monster----------------------" << endl;
        Enemy::Print();
        cout << "Run Speed : " << runSpeed << endl;
    }
};

int main()
{
    Monster monster("Grisha", 2, 0, 1, 100, 150);
    monster.Run();
    monster.Print();



    Dragon boss("Boss",100,10,80,1,2);
    boss.Print();
    
    Dragon dragon("Alesha", 100, 8, 60, 1, 1);
    dragon.Print();
    int i = 1;
    do
    {
        cout << "---------- Round :" << i << "--------------" << endl;
        boss.Defence(dragon.Attack());
        dragon.Defence(boss.Attack());
        cout << endl;
        boss.Print();
        dragon.Print();
        i++;

    } while (dragon.IsAlive()&& boss.IsAlive());
  

    
    
    
}

