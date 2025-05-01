#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
    ifstream inputFile("secret.txt");

    if (!inputFile.is_open())
    {
        cerr << "arror" << endl;
        return 1;
    }
    char ch;
    int uppercaseCount = 0;
    while (inputFile.get(ch))
    {
        if (isupper(ch))
        {
            uppercaseCount++;
        }
    }
    cout << "Signal count: " << uppercaseCount << endl;
    inputFile.close();
    return 0;
}