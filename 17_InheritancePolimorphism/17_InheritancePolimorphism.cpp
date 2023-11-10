#include<iostream>
#include <windows.h> 
using namespace std;

class Car
{
protected:
	string mark;//brand
	string model;
	int year;
	float volume;
	string typeFuel;
	int maxSpeed;
	int hoursePower;
public:
	Car() :mark(""), model(""), year(0), volume(0), typeFuel(""), maxSpeed(0), hoursePower(0) {}
	Car(string mark, string model,int year,float volume,string type,
		int maxSpeed, int hoursePower) :mark(mark), model(model), year(year), volume(volume),
		typeFuel(type), maxSpeed(maxSpeed), hoursePower(hoursePower) {}
	virtual void Drive()const
	{
		cout << " I am a Car! I can drive with speed " << maxSpeed << "km/h" << endl;
	}
	virtual void Print()const
	{
		cout << "Mark of car : " << mark << endl;
		cout << "Model of car : " << model << endl;
		cout << "Year : " << year << endl;
		cout << "Volume : " << volume << endl;
		cout << "Type of fuel : " << typeFuel << endl;
		cout << "Max Speed : " << maxSpeed << endl;
		cout << "Hourse Power : " << hoursePower << endl;		
	}
	void SetSpeed(int speed)
	{
		if (speed >= 0)
			maxSpeed = speed;
	}

};

class PoliceCar : public Car
{
	int soudVolume;
public:
	PoliceCar() : soudVolume(0), Car() {}
	PoliceCar(string mark, string model, int year, float volume, string type,
		int maxSpeed, int hoursePower, int sound) : soudVolume(sound), Car(mark,model,
			year,volume,type, maxSpeed,hoursePower) {}

	void Drive()const override
	{
		cout << " I am a Police Car! I can drive with speed " << maxSpeed << "km/h" << endl;
	}
	void Print()const override
	{
		Car::Print();
		cout << "Sound volume " << soudVolume << endl;
	}
	void BeepBeep()
	{
		Beep(1568, 400);
		Beep(1245, 400);
		Beep(1568, 400);
		Beep(1245, 400);
		Beep(1568, 400);
		Beep(1245, 400);
		Beep(1568, 400);
		Beep(1245, 400);
	}

};
class SportCar : public Car
{
	int turbo;
public:
	SportCar() : turbo(0), Car() {}
	SportCar(string mark, string model, int year, float volume, string type,
		int maxSpeed, int hoursePower, int turbo) : turbo(turbo), Car(mark, model,
			year, volume, type, maxSpeed, hoursePower) {}

	void Drive()const override
	{
		cout << " I am a Sport Car! I can drive with speed " << maxSpeed << "km/h" << endl;
	}
	void Print()const override
	{
		Car::Print();
		cout << "Turbo  " << turbo << endl;
	}
	void Nitro()
	{
		maxSpeed += turbo;
		cout << "Enabme turbo speed : " << maxSpeed<<"km/h";
	}

};
void TestDrive(Car& car)
{
	car.SetSpeed(60);
	car.Drive();

}
void main() 
{
	Car simpleCar("Daewoo", "Lanos", 2010, 1.5, "petrol", 100, 75);
	simpleCar.SetSpeed(70);
	simpleCar.Drive();
	simpleCar.Print();
	cout << endl << endl;

	PoliceCar police("Toyota","Prius",2015,1.3,"electric+petrol",200,90,500);
	police.SetSpeed(120);
	police.Drive();
	police.Print();
	//police.BeepBeep();

	SportCar sport("Porcshe", "911", 2022, 2.5, "petrol", 320, 500, 40);
	sport.Drive();

	TestDrive(simpleCar);
	TestDrive(police);
	TestDrive(sport);

	Car* carSalon[3]
	{
		new Car("Daewoo", "Lanos", 2010, 1.5, "petrol", 100, 75),
		new PoliceCar("Toyota","Prius",2015,1.3,"electric+petrol",200,90,500),
		new SportCar("Porcshe", "911", 2022, 2.5, "petrol", 320, 500, 40)
	};

	for (int i = 0; i < 3; i++)
	{
		carSalon[i]->Print();
	}

	for (int i = 0; i < 3; i++)
	{
		delete carSalon[i];
	}

	//p.Drive();



}