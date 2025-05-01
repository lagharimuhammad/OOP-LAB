#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;
    string msg;

    cout << "enter the you name: ";
    getline(cin, name);

    cout << "enter your message: ";
    getline(cin, msg);
    ofstream outFile("greeting.txt");

    if (!outFile)
    {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }
    outFile << "Dear " << name << endl << msg << endl << "good regards" << endl;
    outFile.close();

    return 0;
}