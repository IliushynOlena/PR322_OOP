#include <iostream>
#include <string>
#include <fstream>
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
	explicit Point(int value)
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
	Point operator-()const
	{
		/*Point res(this->x * -1, this->y * -1);
		return res;*/
		return Point(-x, -y);
	}

	Point operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;

	}
	bool operator < (const Point& other)const
	{
		/*if ((this->x + this->y) < (other.x + other.y))
			return true;
		else
			return false;*/

		return (this->x + this->y) < (other.x + other.y);
	}	
	bool operator>= (const Point& other)const
	{
		return (this->x + this->y) >= (other.x + other.y);
	}
	bool operator<= (const Point& other)const
	{
		return (this->x + this->y) <= (other.x + other.y);
	}
	bool operator == (const Point& other)const
	{
		return (this->x == other.x) && (this->y == other.y);
	}
	bool operator!= (const Point& other)const
	{
		//return (this->x != other.x) && (this->y != other.y);
		return !(*this == other);
	}
	
	Point operator --()//prefix form of decrement
	{
		--this->x;
		--this->y;
		return *this;
	}
	Point operator ++(int a)//postfix form of incerement
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator --(int )//postfix form of decrement
	{
		this->x--;
		this->y--;
		return *this;
	}
	int getX()const
	{
		return x;
	}
	int getY()const
	{
		return y;
	}
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	friend bool operator > (const Point& point1, const Point& point2);
	friend Point operator ++(Point& point);
	friend ostream& operator << (ostream& out, const Point& point);
	friend istream& operator >>(istream& in, Point& other);
};

//bool operator> (const Point& point1 ,const Point& point2)
//{
//	return (point1.getX() + point1.getY()) > (point2.getX() + point2.getY());
//}
//Point operator ++(Point& point)//prefix form of incerement
//{
//	point.setX(point.getX()+1);
//	point.setY(point.getY()+1);
//	return point;
//}
bool operator> (const Point& point1, const Point& point2)
{
	return (point1.x + point1.y) > (point2.x + point2.y);
}
Point operator ++(Point& point)//prefix form of incerement
{
	point.x++;
	point.y++;
	return point;
}
ostream& operator << (ostream& out, const Point& point)
{
	out << "X : " << point.x << " Y : " << point.y << endl;
	return out;
}
istream& operator >>(istream& in,  Point& other)
{
	in >> other.x;
	in >> other.y;
	return in;
}
int main() {


	Point p2(5, 7);
	Point p8(15, 71);
	cout << p2;
	cin >> p2 >> p8;
	cout << p2 << p8 << endl;

	int a = 3.33;//double -> int 3
    // a = p2;


	if (p2 > p8)
	{
		cout << "p2 > p8" << endl;
	}
	else
		cout << "p2 < p8" << endl;
	p2.Print();
	++p2;//postfix
	p2.Print();
	--p2;
	p2.Print();

	p2.Print();
	p2++;//postfix
	p2.Print();
	p2--;
	p2.Print();

	
	int m(5);
	/*cout << m << endl;
	m++;
	cout << m << endl;
	++m;
	cout << m << endl;*/
	cout << m << endl;
	cout << m++ << endl;//postfix -------->
	cout << ++m << endl;//prefix  <--------
	cout << m << endl;




   /*
	Point p1;//defaut constructor
	p1.Print();
	
	p2.Print();
	Point p3(15);
	p3.Print();

	Point copy(p2);
	copy.Print();

	Point point1(3, 5);
	Point point2(7, 9);
	Point res = point1.Plus(point2);
	
	res = point1 + point2;// point1.operator+(point2);
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

	point1 += point2;
	cout << "Point : point1 +=15 "; point1.Print();
	
	res = -point1;
	cout << "Res : -point1  "; res.Print();

	res = point1 = point2;
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

	*/
}