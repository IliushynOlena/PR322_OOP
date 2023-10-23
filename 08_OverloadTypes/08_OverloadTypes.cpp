#include <iostream>
using namespace std;


class Square;
class Rectangle
{
private:
	int width;
	int height;
public:
	Rectangle() :width(0), height(0) {}
	Rectangle(int value) :width(value), height(value) {}
	Rectangle(int w, int h) :width(w), height(h) {}
	void Show()const
	{
		cout << "Height : " << height << endl;
		cout << "Weight : " << width << endl;
		cout << endl;
	}
	//operator typename() {}//1
	//operator typename() const {}//2
	//explicit operator typename() const {}//3
	explicit operator int()
	{
		return width * height;
	}
	 operator Square();
	
};



class Square
{
private:
	int side;
public:
	Square() :side(2) {}
	Square(int s) :side(s) {}
	void Show()const
	{
		cout << "Height : " << side << endl;
		cout << "Weight : " << side << endl;
		cout << endl;
	}
	operator Rectangle()
	{
		Rectangle res(side, side + 5);
		return res;
	}

};
 Rectangle::operator Square()
{
	return Square(width + height);
}

int main()
{
	int valueInt = 9;//int -> int 
	double valDob = valueInt;//int -> double implicit 9.00000000000000000  statndart type to standart type
    valDob = (double)valueInt;//int -> double explicit 9.00000000000000000 statndart type to standart type
	Square sq(5);//standart to  absract 
	sq.Show();
	Rectangle rect(15,45);////standart to  absract 
	rect.Show();
	valueInt = (int)rect;//Rectangle -> int absract to standart
	cout << "Square of rectangle = " << valueInt << endl;

	rect = sq;//Square -> Rectangle  absract to absract
	rect.Show();
	cout << "Square : " << endl;
	sq = rect;//absract to absract
	sq.Show();
}

