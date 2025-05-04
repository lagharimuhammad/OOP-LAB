#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("target.txt", ios::binary);
    if (!file)
    {
        cerr << "error opening" << endl;
        return 1;
    }

    streampos beforePos = file.tellg();
    cout << "initial pointer position: " << beforePos;

    cout << "enter byte offset to jump to: ";
    streamoff offset;
    cin >> offset;

    file.seekg(offset, ios::beg);
    streampos afterPos = file.tellg();

    cout << "pointer after seekg(): " << afterPos;
    cout << "reading next 100 characters:\n\n";

    char buffer[101] = {0};
    file.read(buffer, 100);
    cout.write(buffer, file.gcount()); // had issues in this code alot
    cout << endl;

    file.close();
    return 0;
}