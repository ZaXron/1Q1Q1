using namespace std;
#include<iostream>
#include<time.h>

class Point
{
	int x;
	int y;
public:
	Point()  // construct by default
	{
		cout << "Construct\n";
		x = y = 0;
	}
	Point(int x1, int y1)	// Construct by 2 param
	{
		cout << "Construct by 2 param\n";
		x = x1;
		y = y1;
	}
	void Init()
	{
		x = rand() % 10;
		y = rand() % 10;
	}
	void Init(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	void Output()
	{
		cout << "X: " << x << "\tY: " << y << endl;
	}

	Point operator+(Point& b) {
		Point temp;
		temp.x = this->x + b.x;
		temp.y = this->y + b.y;
		return temp;
	}

	Point operator+(int a) {
		Point temp(x + a, y + a);
		return temp;
	}

	Point operator-(Point& b) {
		Point temp;
		temp.x = this->x - b.x;
		temp.y = this->y - b.y;
		return temp;
	}
	Point operator*(Point& b) {
		Point temp;
		temp.x = this->x * b.x;
		temp.y = this->y * b.y;
		return temp;
	}
	Point operator/(Point& b) {
		Point temp;
		temp.x = this->x / b.x;
		temp.y = this->y / b.y;
		return temp;
	}

	Point operator*(int a) {
		Point temp(x * a, y * a);
		return temp;
	}

	Point operator/(int a) {
		Point temp(x / a, y / a);
		return temp;
	}

	friend ostream& operator<<(ostream& cout, const Point& p);
	friend istream& operator>>(istream& cin, Point& p);

};

ostream& operator<<(ostream& cout, const Point& p)
{
	cout << "X: " << p.x << endl << "Y: " << p.y;
	return cout;
}

istream& operator>>(istream& cin, Point& p)
{
	cout << "Your X: " << endl;
	cin >> p.x;
	cout << "Your Y: " << endl;
	cin >> p.y;
	return cin;
}

int main()
{
	srand(unsigned(time(0)));

	Point a(5, 4);
	Point b(6, 9);
	Point c = a / 2;

	c.Output();
}