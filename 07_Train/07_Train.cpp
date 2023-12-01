#include <iostream>
#include <string>
using namespace std;

struct Vagon
{

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
	Train operator++()//increment prefix form
	{
		for (int i = 0; i < number_of_wag; i++)
		{
			vagon[i].passengers++;
		}
		return *this;
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
	Vagon GetVagon(int index)//71
	{
		if (index < 0 || index >= number_of_wag) return Vagon();
		return vagon[index];
	}
	Vagon operator[](int index)//71
	{
		if (index < 0 || index >= number_of_wag) return Vagon();
		return vagon[index];
	}
	void ChangePassanges(int count)
	{
		for (int i = 0; i < number_of_wag; i++)
		{
			vagon[i].passengers += count;
		}
	}
	void operator()(int count)
	{
		for (int i = 0; i < number_of_wag; i++)
		{
			vagon[i].passengers += count;
		}
	}
	void operator()(int count, int number)
	{
		for (int i = 0; i < number_of_wag; i++)
		{
			if(vagon[i].wag_number == number)
				vagon[i].passengers += count;
		}
	}
	operator string()
	{
		/*string res = "";
		for (int i = 0; i < number_of_wag; i++)
		{
			res += to_string(vagon[i].wag_number) + " ";
		}
		return res;*/
		return model;
	}
	string ConvertToString()
	{		
		return model;
	}

};

int main() 
{
	int a = 5;
	//istream cin;
	//cin >> a;
	//ostream cout;
	//cout << a;

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
	cout << "------------------------------------" << endl;
	(++superTrain).Show();
	//superTrain.Show();
	cout << "------------------------------------" << endl;

	Vagon res = superTrain.GetVagon(71);
	res.Show();

	res = superTrain[2];
	res.Show();

	cout << "------------------------------------" << endl;
	superTrain.ChangePassanges(10);
	superTrain.Show();

	superTrain(10);
	superTrain.Show();

	cout << "------------------------------------" << endl;
	superTrain(100,1);
	superTrain.Show();


	cout << (string)superTrain << endl;
	cout << superTrain.ConvertToString() << endl;

	return 0;



}