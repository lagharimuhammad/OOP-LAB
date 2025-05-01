#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file;
    string name, email;
    char word = 'y';
    file.open("signup.txt", ios::app);

    if (!file)
    {
        cerr << "error" << endl;
        return 1;
    }

    while (tolower(word) == 'y')
    {
        cout << endl;
        cout << "enter name: ";
        getline(cin, name);

        cout << "enter email: ";
        getline(cin, email);

        file << "name: " << name << endl << "email: " << email << endl;

        cout << "register word (y/n): ";
        cin >> word;
        cin.ignore();
    }
    file.close();

    return 0;
}