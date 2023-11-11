#include <iostream>
using namespace std;


struct Wagon
{
public:
	int wagonNumber;
	int countPassenger;
	int countPlace;

	Wagon() :wagonNumber(0), countPassenger(0), countPlace(0){}
	Wagon(int countPassenger, int countPlace) :wagonNumber(0), countPassenger(countPassenger), countPlace(countPlace){}

	void Print()const
	{
		cout << "Wagon number: " << wagonNumber << endl;
		cout << "Counts of passengers: " << countPassenger << endl;
		cout << "Counts of place in wagon: " << countPlace << endl;
	}
};


class Train
{
private:
	string model;
	int countWagons;
	Wagon* wagons;
public:
	Train()
	{
		model = "No data";
		countWagons = 0;
		wagons = new Wagon[countWagons];
	}
	Train(string model)
	{
		this->model = model;
		countWagons = 0;
		wagons = new Wagon[countWagons];
	}


	void Print()const
	{
		cout << "Model of Train: " << model << endl;
		cout << "Counts of wagons: " << countWagons << endl;
		cout << "-----------------------------" << endl;
		for (int i = 0; i < countWagons; i++)
		{
			wagons[i].Print();
		}
	}
	void AddWagon(Wagon wagon)
	{
		Wagon* temp = new Wagon[countWagons + 1];
		for (int i = 0; i < countWagons; i++)
		{
			temp[i] = wagons[i];
		}
		wagon.wagonNumber++;
		temp[countWagons] = wagon;
		delete[] wagons;
		wagons = temp;
		countWagons++;
	}
	void AddPassenger(int wagonNumber)
	{
		for (int i = 0; i < countWagons; i++)
		{
			if (wagonNumber == wagons[i].wagonNumber)
				wagons[i].countPassenger++;
		}
	}
	Train(const Train& other)
	{
		this->model = other.model;
		this->countWagons = other.countWagons;
		this->wagons = new Wagon[other.countWagons];
		for (int i = 0; i < other.countWagons; i++)
		{
			wagons[i] = other.wagons[i];
		}
	}
	~Train()
	{
		if (wagons != nullptr)
		{
			delete[] wagons;
		}
	}
};



int main()
{
	Train a("Train qwe");
	Wagon b(10, 15);
	a.AddWagon(b);
	a.AddPassenger(1);
	a.Print();
	cout << endl;
	Train copy(a);
	copy.Print();
}