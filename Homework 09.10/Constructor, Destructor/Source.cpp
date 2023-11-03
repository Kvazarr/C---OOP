#include <iostream>
#include <Windows.h>
using namespace std;


struct Coord
{
	int coordinateX;
	int coordinateY;
};


class Rectangle
{
private:
	int width;
	int height;
	char symbol;
	Coord position;
public:
	Rectangle()
	{
		width = 0;
		height = 0;
		symbol = '*';
	}
	Rectangle(int size)
	{
		if (IsTrueParameters(width, height))
		{
			this->width = size;
			this->height = size;
		}
	}
	Rectangle(int width, int height)
	{
		if (IsTrueParameters(width, height))
		{
			this->width = width;
			this->height = height;
		}
	}

	bool IsTrueParameters(int width, int height)
	{
		if (width >= 0 && height >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	void Print()const
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << symbol;
			}cout << endl;
		}
	}
	void ChangeRectangle(int width, int height)
	{
		if (IsTrueParameters(width, height))
		{
			this->width = width;
			this->height = height;
		}
	}
	void GoToXy(int x, int y)
	{
		position.coordinateX = x;
		position.coordinateY = y;
		COORD coords;
		coords.X = position.coordinateX;
		coords.Y = position.coordinateY;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
	}
};


int main()
{
	Rectangle a;
	a.Print();
}