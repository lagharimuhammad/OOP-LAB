#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream diaryFile;
    string input;
    diaryFile.open("diary.txt", ios::app);

    if (!diaryFile)
    {
        cerr << "error" << endl;
        return 1;
    }

    cout << "type 'exit' on a new line to quit." << endl;
    cout << "enter your diary input (multiple lines allowed): " << endl;
    while (true)
    {
        getline(cin, input);

        if (input == "exit")
        {
            break;
        }
        diaryFile << input << endl;
    }
    diaryFile.close();

    cout << "inputs saved to diary.txt" << endl;

    return 0;
}