#include <iostream>
#include <string>
using namespace std;

class Character 
{
public:
	int health, damage;
    string name;

    Character(string name, int h, int d) : name(name), health(h), damage(d) {}

    void display() 
    {
        cout << "Name: " << name << endl << "\tHealth: " << health << endl << "\tDamage: " << damage << endl ;
    }
};
class Enemy : public Character 
{
public:
    Enemy(string enemy_n, int e_h, int e_d) : Character(enemy_n, e_h, e_d) {}

    void display()
    {
        cout << "Enemy:\n\tName: " << name << endl << "\tHealth: " << health << endl << "\tDamage: " << damage << endl ;
    }
};
class Player : public Character 
{
public:
    Player(string player_n, int p_h, int p_d) : Character(player_n, p_h, p_d) {}

    void display()
    {
        cout << "Player:\n\tName: " << name << endl << "\tHealth: " << health << endl << "\tDamage: " << damage << endl;
    }
};
class Wizard : public Player 
{
private:
    int magicPower;
public:
    Wizard(string wizardName, int wizardHealth, int wizardDamage, int wizardMagicPower) : Player(wizardName, wizardHealth, wizardDamage), magicPower(wizardMagicPower) {}

    void display() 
    {
        cout << "Wizard:\n\tName: " << name << endl << "\tHealth: " << health << endl << "\tDamage: " << damage << endl <<"\tMagic Power: " << magicPower << endl;
    }
};

int main() 
{
    Wizard wizard("Dob", 500, 90, 750);
    wizard.display();
    return 0;
}
