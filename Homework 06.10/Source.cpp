#include<iostream>
using namespace std;


class Point
{
private:
	int x;
	int y;
	int z;
public:
	Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	void Introduction()
	{
		cout << "Enter X value: "; cin >> x;
		cout << "Enter Y value: "; cin >> y;
		cout << "Enter Z value: "; cin >> z;
	}
	void Print()const
	{
		system("cls");
		cout << "X point value: [" << x << "];" << endl << "Y point value: [" << y << "];" << endl << "Z point value: [" << z << "];";
	}
	int GetX(int x)
	{
		this->x = x;
	}
	int SetX()const
	{
		return x;
	}
	int GetY(int y)
	{
		this->y = y;
	}
	int SetY()const
	{
		return y;
	}
	int GetZ(int z)
	{
		this->z = z;
	}
	int SetZ()const
	{
		return z;
	}
};


int main()
{
	Point a;
	a.Introduction();
	a.Print();
}