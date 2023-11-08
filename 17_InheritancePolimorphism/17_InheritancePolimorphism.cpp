#include<iostream>
#include<Windows.h>



using namespace std;


void Gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Point {
private:
	int m_x;
	int m_y;
public:
	Point() :m_x(0), m_y(0) {}
	Point(int x, int y) :m_x(x), m_y(y) {}
	int operator ++ (int n) {
		return m_x++, m_y++;
	}
	int operator -- (int n) {
		return m_x--, m_y--;
	}
	int operator ! () {
		m_x = (-m_x);
		m_y = (-m_y);
		return m_x, m_y;
	}
	bool operator < (Point p) {
		return (this->m_x < p.m_x&& this->m_y < p.m_y);
	}
	bool operator > (Point p) {
		return (this->m_x > p.m_x && this->m_y > p.m_y);
	}
	void Print() {
		cout << "X:" << m_x << endl;
		cout << "Y:" << m_y << endl;
	}
	int GetX() {
		return m_x;
	}
	int GetY() {
		return m_y;
	}
};
class Vector
{
private:
	Point* points;
	int countPoint;
public:
	Vector() {
		points = nullptr;
		countPoint = 0;
	}
	Vector(int size) {
		countPoint = size;
		points = new Point[countPoint];
		for (int i = 0; i < countPoint; i++) {
			points[i] = Point(i, i);
		}

	}
	~Vector() {
		delete[]points;
	}
	void Add(int x, int y) {
		countPoint++;
		Point* pt = new Point[countPoint];
		if (countPoint > 1) {
			for (int i = 0; i < countPoint; i++) {
				pt[i] = points[i];
			}
		}
		pt[countPoint - 1] = Point(x, y);
		delete[]points;
		points = pt;


	}
	Point& Pop(Point* points) {
		countPoint--;
		Point* pt = new Point[countPoint];
		if (countPoint >= 1) {
			for (int i = 0; i < countPoint; i++) {
				pt[i] = points[i];
			}
		}
		points = pt;
		delete[]pt;
	}
	void Print() {
		for (int i = 0; i < countPoint; i++) {
			Gotoxy(points[i].GetX(), points[i].GetY());
			cout << char(223);
		}

	}
};


void main() {
	//===========part 1=============
	Point p1 = Point(1,1);
	p1.Print();
	p1--;
	p1.Print();
	p1++;
	p1.Print();
	!p1;
	p1.Print();
	Point p2 = Point();
	if (p1 > p2) {
		cout << "p1 is biger" << endl;
	}
	else if (p1 < p2) {
		cout << "p1 is smaller" << endl;
	}
	//=================part 2=====================
	/*Vector v = Vector();
	int j = 20;
	int k = 0;
	for (int i = 0; i < 10; i++) {
		v.Add(j, i);
		j -= 2;
	}
	for (int i = 0; i < 10; i++) {
		v.Add(k, i);
		k += 2;
	}

	v.Print();*/


}