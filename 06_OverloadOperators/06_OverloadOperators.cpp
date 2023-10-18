#include <iostream>
#include <string>
using namespace std;
class Point
{
private:
	int x;
	int y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(int value)
	{
		x = y = value;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;	
	}
	Point(const Point &other)
	{
		this->x = other.x;//5 - 5
		this->y = other.y;//8 - 8
	}
	void Print()const
	{
		cout << "X : " << x << " Y : " << y << endl;
	}
	Point Plus(const Point& other)const
	{
		Point res(this->x + other.x, this->y + other.y);
		return res;
	}
	Point Minus(const Point& other)const
	{
		Point res(this->x - other.x, this->y - other.y);
		return res;
	}
	Point operator+(const Point& other)const
	{
		Point res(this->x + other.x, this->y + other.y);
		return res;
	}
	Point operator+(int value)const
	{
		Point res(this->x + value, this->y + value);
		return res;
	}
	Point operator-(const Point& other)const
	{
		Point res(this->x - other.x, this->y - other.y);
		return res;
	}
	Point operator*(const Point& other)const
	{
		Point res(this->x * other.x, this->y * other.y);
		return res;
	}
	Point operator/(const Point& other)const
	{
		Point res(this->x / other.x, this->y / other.y);
		return res;
	}
	Point operator+= (const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point operator-()
	{
		/*Point res(this->x * -1, this->y * -1);
		return res;*/
		return Point(-x, -y);
	}
	Point operator= (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
	bool operator< (const Point& other)
	{
		/*if ((this->x + this->y) < (other.x + other.y))
			return true;
		else
			return false;*/

		return (this->x + this->y) < (other.x + other.y);
	}
	bool operator> (const Point& other)
	{
		return (this->x + this->y) > (other.x + other.y);
	}
	bool operator>= (const Point& other)
	{
		return (this->x + this->y) >= (other.x + other.y);
	}
	bool operator<= (const Point& other)
	{
		return (this->x + this->y) <= (other.x + other.y);
	}
	bool operator == (const Point& other)
	{
		return (this->x == other.x) && (this->y == other.y);
	}
	bool operator!= (const Point& other)
	{
		//return (this->x != other.x) && (this->y != other.y);
		return !(*this == other);
	}
};

int main() {
   
	Point p1;//defaut constructor
	p1.Print();
	Point p2(5, 7);
	p2.Print();
	Point p3(15);
	p3.Print();

	Point copy(p2);
	copy.Print();

	Point point1(3, 5);
	Point point2(7, 9);
	Point res = point1.Plus(point2);
	point1.Print();
	point2.Print();
	res.Print();
	res = point2.Minus(point1);
	res.Print();

	res = point1 + point2;//point1.operator+(point2);
	cout << "Res : point1 + point2 "; res.Print();
	res = point1 + 100;//point1.operator+(point2);
	cout << "Res : point1 + 100 "; res.Print();
	res = point1 - point2;//point1.operator-(point2);
	cout << "Res : point1 - point2 "; res.Print();
	res = point1 * point2;//point1.operator*(point2);
	cout << "Res : point1 * point2 "; res.Print();
	res = point1 / point2;//point1.operator/(point2);
	cout << "Res : point1 / point2 "; res.Print();

	point1 += 15;
	cout << "Point : point1 +=15 "; point1.Print();
	
	res = -point1;
	cout << "Res : -point1  "; res.Print();

	//res = point1 = point2;
	cout << "Point1 "; point1.Print();
	cout << "Point2 "; point2.Print();
	cout << "Res :  "; res.Print();


	if (point1 > point2)
		cout << "Point 1 is more than point 2" << endl;
	else
		cout << "Point 1 is less than point 2" << endl;

	if (point1 != point2)
		cout << "Point 1 != Point2" << endl;
	else
		cout << "Point 1 == point 2" << endl;
	//point1.x = 10;


	int a = 5;
	a = 2000;
	a += 100;
	a++;
	a--;
	cout << -a << endl;;

	int b = 7;
	int c = a + b;
	int d = a - b;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	if (a > 0)
		cout << "More than 0";
	else
		cout << "Less than 0";

	(a > 0)? cout << "More than 0": cout << "Less than 0";
}