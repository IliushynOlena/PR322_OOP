#include <iostream>
using namespace std;
/*
struct Player//defaul - public
{
	string name;
	short age;
	int games;
	int goals;
};

void InitPlayer(Player &player)
{
	cout << "Enter name : ";
	cin >> player.name;
	cout << "Enter age : ";
	cin >> player.age;
	player.games = 0;
	player.goals = 0;
}

void PrintPlayer(Player& player)
{
	cout << "Name : " << player.name << endl;
	cout << "Age : " << player.age << endl;
	cout << "Games : " << player.games << endl;
	cout << "Goals : " << player.goals << endl;
}

void AddGameToPlayer(Player& player, int goals = 0)
{
	player.games++;
	player.goals += goals;
}
*/

class Player//defaul - public
{
private://defaul
	string name;
	short age;
	int games;
	int goals;
	bool IsValidGoals(int goals) { return goals >= 0; }
public:
	void Initialize()
	{
		name = "no name";
		age = 0;
		games = 0;
		goals = 0;
	}
	void InitPlayerFromKeyBoard()
	{
		cout << "Enter name : ";cin >> name;
		cout << "Enter age : ";cin >> age;
	}

	void AddGame(int goals = 0)//-5
	{
		
		this->games++;
		if (IsValidGoals(goals))
			this->goals += goals;
	}
	void PrintPlayer()
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Games : " << games << endl;
		cout << "Goals : " << goals << endl;
	}

};
//private:
//public:
//protected:
class Person
{
private:
	string name;
	int marks[3];
public:
	double getAverage()
	{
		double sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum += marks[i];
		}
		return sum / 3;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setMark(int mark, int index)
	{
		if (mark < 1 || mark > 12)
		{
			mark = 0;
		}
		marks[index] = mark;
	}
	string getName()
	{
		return name;
	}
	int getMark(int index)
	{
		return marks[index];
	}
};



int main()
{
	
	Person st;
	st.setName("Stive");
	st.setMark(2, 0);
	st.setMark(12, 1);
	st.setMark(8, 2);
	
	cout << "Name : " << st.getName() << " Marks " << st.getMark(0) << endl;

	double res = st.getAverage();
	cout << "Average mark : " << res << endl;
	
	/*
    Student st;
	st.name = "Stive";
	st.marks[0] = 2;
	st.marks[1] = 12;
	st.marks[2] = 8;

	cout << "Name : " << st.name << " Marks " << st.marks[0] << endl;

	double res = st.getAverage();
	cout << "Average mark : " << res << endl;
	*/
	//getAverage();
	Person st2;
	/*
	Player pl;

	
	pl.Initialize();
	pl.InitPlayerFromKeyBoard();
	pl.PrintPlayer();

	pl.AddGame();
	pl.AddGame(2);
	pl.AddGame(3);
	pl.AddGame(1);
	pl.PrintPlayer();
	*/
	/*
	Player pl
	InitPlayer(pl);
	PrintPlayer(pl);

	AddGameToPlayer(pl);
	PrintPlayer(pl);
	AddGameToPlayer(pl,1);
	PrintPlayer(pl);
	AddGameToPlayer(pl,4);
	PrintPlayer(pl);
   */
}

