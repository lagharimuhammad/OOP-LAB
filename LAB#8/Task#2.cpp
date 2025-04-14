/*Cricket fans, get ready for some coding action! Imagine the ICC is developing a high-tech system
to analyze a batsman's total runs in a match. To make this happen, let's create two C++ classes—
Runs and BallsFaced—to store the number of runs scored and the number of balls faced by a
batsman, respectively. But since these two classes are as secretive as a team's match strategy,
we’ll introduce them to a mutual friend function called calculateStrikeRate(), which will access
their private data and calculate the player's strike rate using the formula:
Strike Rate = (Runs / Balls Faced) × 100
Your task is to write a C++ program where calculateStrikeRate() takes values from both classes
(e.g., a batsman scores 85 runs off 60 balls) and computes the strike rate. Finally, in the main()
function, instantiate objects with sample values and print out the calculated strike rate—because
even the ICC needs a little coding magic to keep up with the game!*/

#include<iostream>
using namespace std;

class Balls;

class Runs
{
    int total_runs;
    public:
    Runs(int r) : total_runs(r){}
    friend double calculate_strike_rate(const Runs&, const Balls&);
};

class Balls
{
    int balls_faced;
    public:
    Balls(int b) : balls_faced(b){}
    friend double calculate_strike_rate(const Runs&, const Balls&);
};

double calculate_strike_rate(const Runs& r, const Balls& b)
{
    const double sr = (static_cast<double>(r.total_runs)/static_cast<double>(b.balls_faced))*100;
    cout << "strike rate: " << sr;
    return sr;
}

int main()
{
    Runs r(47);
    Balls b(30);
    calculate_strike_rate(r,b);
}