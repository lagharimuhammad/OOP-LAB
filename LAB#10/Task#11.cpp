#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main() 
{
    ifstream inFile("article.txt");
    
    if (!inFile) 
	{
        cerr << "error opening" << endl;
        return 1;
    }

    int chcount = 0, letterword = 0, linecount = 0, markcount = 0;
    string line;

    while (getline(inFile, line)) 
	{
        linecount++;
        chcount += line.length() + 1;

        bool inWord = false;
        for (char ch : line) 
		{
            if (ispunct(ch)) markcount++;

            if (isspace(ch)) 
			{
                if (inWord) 
				{
                    letterword++;
                    inWord = false;
                }
            } else 
			{
                inWord = true;
            }
        }

        if (inWord) letterword++; 
    }

    inFile.close();

    ofstream report("report.txt");
    if (!report) 
	{
        cerr << "error creating" << endl;
        return 1;
    }

    cout << "total Characters         : " << chcount << endl;
    cout << "total Words              : " << letterword << endl;
    cout << "total Lines              : " << linecount << endl;
    cout << "punctuation marks count  : " << markcount << endl;

    report.close();
    cout << "report updated";

    return 0;
}
