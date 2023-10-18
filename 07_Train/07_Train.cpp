#include <iostream>
using namespace std;

struct Vagon
{
	int wag_number;
	int seats_number;
	int passengers;
	Vagon()
	{
		wag_number = 0;
		seats_number = 0;
		passengers = 0;
	}
	Vagon(int wag_number, int seats_number, int passengers)
	{
		this->wag_number = wag_number;
		this->seats_number = seats_number;
		this->passengers = passengers;
	}
	void Show()
	{
		cout << "Wagon number: " << wag_number << endl;
		cout << "Amount of places: " << seats_number << endl;
		cout << "Amount of passengers: " << passengers << endl << endl;
	}
};

class Train
{
private:
	string model;
	int number_of_wag;
	Vagon* vagon;
public:
	Train()
	{
		model = " ";
		number_of_wag = 0;
		vagon = nullptr;
	}
	/*Train(string model, Vagon*& vagon, int number_of_wag)
	{
		this->model = model;
		this->vagon = vagon;
		this->number_of_wag = number_of_wag;
	}*/
	Train(string model)
	{
		this->model = model;
		number_of_wag = 0;
		vagon = nullptr;
	}
	void Show()
	{
		cout << "Model: " << model << endl;
		for (int i = 0; i < number_of_wag; i++)
		{
			vagon[i].Show();
		}
		cout << endl;
	}
	void AddWag(Vagon new_vagon)
	{
		Vagon* tmp = new Vagon[number_of_wag + 1];
		for (int i = 0; i < number_of_wag; i++)
		{
			tmp[i] = vagon[i];
		}
		tmp[number_of_wag] = new_vagon;
		delete[]vagon;
		vagon = tmp;
		number_of_wag++;
	}
	void AddPassenger(int wag_number)
	{
		for (int i = 0; i < number_of_wag; i++)
		{
			if (wag_number == vagon[i].wag_number)
			{
				vagon[i].passengers++;
			}
		}
	}
	Train(const Train& other)
	{
		this->model = other.model;
		this->number_of_wag = other.number_of_wag;
		this->vagon = new Vagon[other.number_of_wag];
		for (int i = 0; i < other.number_of_wag; i++)
		{
			vagon[i] = other.vagon[i];
		}
	}
	~Train()
	{
		delete[]vagon;
	}
	Train operator+(const Train &other)
	{
		Train result(*this);//copy this
		for (int i = 0; i < other.number_of_wag; i++)
		{
			result.AddWag(other.vagon[i]);
		}
		return result;
	}
};

int main() 
{

	Train t1("Tomas");
	Vagon v(1, 1, 2);
	t1.AddWag(v);
	t1.AddWag(Vagon(2, 10, 3));
	t1.AddWag(Vagon(3, 15, 4));
	t1.AddWag(Vagon(4, 20, 17));
	cout << "Train 1: " << endl;
	t1.Show();
	t1.AddPassenger(1);


	//Train t2("train2");
	Train t2(t1);
	cout << "Train 2 (clone of Train 1): " << endl;
	t2.Show();
	cout << "------------------------------------" << endl;
	Train superTrain = t1 + t2; //t1.operator+(t2);
	superTrain.Show();



	return 0;



}