#include <iostream>
#include <string>
using namespace std;

class CricketPlayer 
{
private:
    string name_player;
    int number;
    double batting_avg;

public:
    CricketPlayer(string name_player, int number, double batting_avg) : name_player(name_player), number(number), batting_avg(batting_avg) {}

    CricketPlayer& improve_avg(double runs) 
    {
        batting_avg += runs / 10;
        return *this;
    }

    void no_of_matchs_played(double runsScored) 
    {
        batting_avg = (batting_avg + runsScored) / 2;
    }

    void display() {
        cout << "player: " << name_player << "\njersey number: " << number << "\nbatting average: " << batting_avg << endl;
        cout << "This batting average is more consistent than Karachis weather!\n";
    }
};

int main() {
    CricketPlayer babar("Babar Azam", 56, 50.0);
    CricketPlayer rizwan("Muhammad Rizwan", 16, 48.5);
    CricketPlayer saim("Saim Ayub", 29, 32.8);

    babar.improve_avg(15).no_of_matchs_played(80);
    rizwan.improve_avg(14).no_of_matchs_played(60);
    saim.improve_avg(8).no_of_matchs_played(45);

    babar.display();
    rizwan.display();
    saim.display();
    
    return 0;
}

