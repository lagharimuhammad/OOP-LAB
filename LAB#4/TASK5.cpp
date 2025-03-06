#include<iostream>
#include<string>
using namespace std;

class FootballPlayer
{
	private: 
	string name, position;
	int goal_counter;
	
	public:
		FootballPLayer()
		{
			name = "Unknown";
			position = "Bencher";
			goal_counter = 0;
		}
	FootballPlayer(string name, string position = "Midfielder", int goals = 10)
	{
		this->name = name;
		this->position = position;
		goal_counter = goals;
	}
	FootballPlayer(const FootballPlayer &other)
	{
		name = other.name;
		position = other.position;
		goal_counter = other.goal_counter;
	}
	void boost(int goal)
	{
		goal_counter += goal;
	}
	void display()
	{
		cout <<"player " << name << " is on position " << position << " has scored " << goal_counter << " goals this season!" << endl;
		cout << "This player is on the road to Ballon d'or!" << endl;
	}
};
int main ()
{
	FootballPlayer ronaldo("ronaldo", "forward", 900);
	FootballPlayer messi("lionel messi");
	FootballPlayer mbappe = ronaldo;
	ronaldo.boost(15);
	messi.boost(12);
	ronaldo.display();
	messi.display();
	mbappe.display();
	
	return 0;
}


