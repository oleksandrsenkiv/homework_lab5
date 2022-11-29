#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;


class Candy
{

public:
	int price;
	int mass_in_grams;
	int amount;
	string name;
	Candy()
	{
	}
	Candy(string name, int price, int mass_in_grams, int amount)
	{
		this->name = name;
		this->price = price;
		this->mass_in_grams = mass_in_grams;
		this->amount = amount;
		
	}

	~Candy()
	{
		
	};

	void Print_candy()
	{
		cout << "name:" << name << endl;
		cout << "price:" << price << endl;
		cout << "mass in grams:"<<mass_in_grams << endl;
		cout << "amount:" << amount << endl;

    }
	void ate()
	{
		if ((mass_in_grams * amount) < 2000)
			cout << "What delicious candies!" << endl;
		else
			cout << "You are on a diet!" << endl;
    }
	

};
class Dinner
{
private:
	string day;
	int time_in_hours;

public:
	vector<Candy> MyCandy;

	string GetDay()
	{
		return day;
	}

	int GetTime_in_hours()
	{
		return time_in_hours;
	}
	Dinner()
	{
	}
	Dinner(string day, int time_in_hours)
	{
		this->day = day;
		this->time_in_hours = time_in_hours;


	}

	~Dinner()
	{
		
	};

	void Print_Dinner()
	{
		cout << "day:" << day << endl;
		cout << "time:" << time_in_hours <<" o`clock"<< endl;

	}
	void AddCandy(Candy candy)
	{
		MyCandy.push_back(candy);

	}
	void findTheMostExpensiveCandies()
	{
		cout << "Top the most expensive candies" << endl;
		sort(MyCandy.begin(),
			MyCandy.end(),
			[](const Candy& s1, const Candy& s2)
			{
				return s1.price > s2.price;
			});

	}
	void SortMass()
	{
		cout << "Sorted by mass:" << endl;
		sort(MyCandy.begin(),
			MyCandy.end(),
			[](const Candy& s1, const Candy& s2)
			{
				return s1.mass_in_grams > s2.mass_in_grams;
			});
	}
	void PrintSortedVector()
	{
		for (auto it = MyCandy.begin(); it != MyCandy.end(); it++) {
			cout << it->name << ", " << it->mass_in_grams << endl;

		}

	}
	void PrintTop()
	{
		for (auto it = MyCandy.begin(); it != MyCandy.end(); it++) {
			cout << it->name << ", " << it->price << endl;

		}

	}
	enum type
	{
		BAR, CARAMEL, BUTTON, GUM, LOLLIPOP, POPCORN
	};
	friend class Candy;
};



int main()
{
	vector<Candy> MyCandy;
	Candy candy1("Milka", 40, 100, 21);
	Candy candy2("chupa-chups", 10, 5, 3);
	Candy candy3("Barbarys", 35, 200, 2);
	Dinner dinner1("Monday", 19);
	dinner1.Print_Dinner();
	cout << "___________________________________" << endl;
	candy1.ate();
	candy1.Print_candy();
	cout << "___________________________________" << endl;
	candy2.ate();
	candy2.Print_candy();
	cout << "___________________________________" << endl;
	candy3.ate();
	candy3.Print_candy();
	dinner1.AddCandy(candy1);
	dinner1.AddCandy(candy2);
	dinner1.AddCandy(candy3);
	cout << "___________________________________" << endl;
	dinner1.SortMass();
	dinner1.PrintSortedVector();
	cout << "___________________________________" << endl;
	dinner1.findTheMostExpensiveCandies();
	dinner1.PrintTop();

}

	